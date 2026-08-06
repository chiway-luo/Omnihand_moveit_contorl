<!-- # 基于moveit的路径规划实现自动规划手指移动的功能 -->
# 基于 ROS2 + MoveIt2 搭建灵巧手手型规划与执行系统

官方文档 [Omnihand-O10](https://www.zhiyuan-robot.com/DOCS/OS/Omnihand-O10)

> 手型请求 -> 角度预设读取 -> MoveIt 规划 -> 执行结果反馈 -> 底层驱动下发
---

- 开发背景
> 在当前的大部分灵巧手sdk中并没有引入手指之间的碰撞检测和路径规划算法,导致在一些复杂的手型切换过程中,可能会出现手指之间的碰撞或者无法规划出合理的路径的问题,因此引入moveit的路径规划算法可以有效的解决这些问题,实现更加智能和安全的手指移动控制

- 实现原理
> 通过配置不同手型,发送请求到服务端,调用moveit的路径规划算法,实现自动规划手指移动的功能,并通过底层驱动接口控制灵巧手执行相应动作。

- 注意事项
> RViz 已启用目标状态半透明预览（Goal State Alpha 为 0.5，Start State Alpha 为 0.2）。可使用 MotionPlanning 的关节滑块设置目标并规划，也可通过服务请求规划预设手型。`hand` 是由五个手指子组组成的关节空间规划组；RViz 提示 `No active joints or end effectors found for group 'hand'` 仅表示没有 6D IK 交互标记，不表示该组不能规划。


---
class_doc中为公开课讲义文件，包含了每一章的内容介绍和代码实现细节，供同学们参考学习。
## 课程文件导览
[第一章 环境准备](class_doc/第一章.md)

[第二章 灵巧手介绍](class_doc/第二章.md)

[第三章 测试功能包编写](class_doc/第三章.md)
## 示例视频
<video src="https://github.com/user-attachments/assets/ac17ca8b-bb46-4fef-8a15-a6e34bdc93ea" controls="controls" width="600">
</video>

## 系统要求
- ubuntu 22.04
- ros2 humble
- moveit2 humble

## 配置依赖
安装moveit和ros_control相关的包
```bash
sudo apt update
sudo apt install cmake
sudo apt install ros-${ROS_DISTRO}-moveit ros-${ROS_DISTRO}-ros2-control ros-${ROS_DISTRO}-ros2-controllers
sudo apt install python3.10-dev
sudo apt install ros-${ROS_DISTRO}-joint-state-publisher-gui 
sudo apt install ros-${ROS_DISTRO}-joint-state-publisher
pip3 install build setuptools wheel

```
## 安装灵巧手
> 当前已验证的 O10 连接方式为 USB-C 虚拟串口（USB CDC），不是外置 RS485 转接器。节点固定使用 udev 映射 `/dev/omnihand_left`；规则中的 `MODE="0666"` 生效后，无需每次对 `/dev/ttyACM0` 执行 `chmod`。
## 设置端口映射
参阅文档
[端口映射步骤](./端口规则映射.md)
## 功能包说明
- omnihand_node 灵巧手底层驱动功能包,提供底层通信接口

- omnihand_node_msgs 灵巧手底层驱动消息定义功能包,包含电机控制模式消息定义

- hand_description 描述文件

- hand_moveit moveit路径规划算法

- hand_control 桥接moveit和底层驱动的控制节点

- hand_test_bag 独立底层测试功能包,包含测试节点和launch文件(robot_state_publisher_gui控制灵巧手)。它会启动自己的驱动节点，禁止与 hand_control 同时启动

- hand_shape 手型库功能包,包含不同手型的描述文件和moveit配置文件
## SDK 集成与工作区构建

当前工程使用 AgiBot OmniHand SDK v1.1.8。SDK 源码目录 `src/Omnihand-2025-SDK` 仅用于版本溯源并带有 `COLCON_IGNORE`，**禁止在本工作区编译 SDK**。所需头文件和预编译共享库已随 `omnihand_node` 放入 `include/`、`lib/`，安装后由节点通过 `$ORIGIN` 加载，不依赖 SDK 的 `build/` 或 `install/` 产物。

```bash
cd ~/work_temp/agibot_hand/ws00_test_hand
source /opt/ros/humble/setup.bash
colcon list --names-only
colcon build --cmake-args -DCMAKE_BUILD_TYPE=RelWithDebInfo
source install/setup.bash
```

`colcon list --names-only` 应只列出 8 个 ROS 2 功能包，不应出现 SDK。

## 启动测试功能包
```bash
ros2 launch hand_test_bag hand_test.launch.py
```

> 该入口仅用于独立直连硬件测试，会占用 `/dev/omnihand_left` 并直接发布电机指令。运行前必须停止 MoveIt 控制栈；不要与下面的 `hand_control` 入口同时运行。
## 启动moveit配置助手(仅供测试使用)
```bash
ros2 launch moveit_setup_assistant setup_assistant.launch.py
```

配置过程参见[moveit官方文档](https://moveit.picknik.ai/main/doc/examples/setup_assistant/setup_assistant_tutorial.html)

## 启动moveit控制节点(实现节点)
```bash
cd ~/work_temp/agibot_hand/ws00_test_hand
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 launch hand_control hand_control.launch.py
```

MoveIt 规划、RViz 预览和真实手执行统一使用上述唯一入口。启动前可用 `ros2 pkg prefix hand_moveit` 和 `ros2 pkg prefix omnihand_node` 确认二者都来自当前工作区的 `install/`。

## 规划不同手型
<!-- ```bash
ros2 param set /hand_shape current_shape default  # 默认手型
ros2 param set /hand_shape current_shape catch    # 抓握
ros2 param set /hand_shape current_shape joke     # 竖中指
``` -->
```bash
ros2 service call /hand_shape/set_shape omnihand_node_msgs/srv/SetHandShape "{shape_name: catch}"
```
- 详细预定义手型见 [hand_shape.yaml](src/hand_test/hand_shape/param/hand_shape.yaml)

> 我将退学在家,专心研究这个代码是怎么写的,感谢copilot && claude && gpt 的帮助,让我能在短时间内完成这个功能包的编写,并且在这个过程中学到了很多ROS2和moveit的知识,非常感谢他们的帮助和支持!
