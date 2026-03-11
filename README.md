# 基于moveit的路径规划实现自动规划手指移动的功能
---
class_doc中为公开课讲义文件，包含了每一章的内容介绍和代码实现细节，供同学们参考学习。
## 课程文件导览
[第一章 环境准备](class_doc/第一章.md)

[第二章 灵巧手介绍](class_doc/第二章.md)

[第三章 测试功能包编写](class_doc/第三章.md)
## 示例视频
<video src="https://github.com/user-attachments/assets/ac17ca8b-bb46-4fef-8a15-a6e34bdc93ea" controls="controls" width="600">
</video>

## 配置依赖
安装moveit和ros_control相关的包
```bash
sudo apt install ros-${ROS_DISTRO}-moveit ros-${ROS_DISTRO}-ros-control ros-${ROS_DISTRO}-ros-controllers
```
## 安装灵巧手
```
sudo chmod 666 /dev/ttyACM0
```
## 功能包说明
- omnihand_node 灵巧手底层驱动功能包,提供底层通信接口

- omnihand_node_msgs 灵巧手底层驱动消息定义功能包,包含电机控制模式消息定义

- hand_description 描述文件

- hand_moveit moveit路径规划算法

- hand_control 桥接moveit和底层驱动的控制节点

- hand_test_bag 测试功能包,包含测试节点和launch文件(robot_state_publisher_gui控制灵巧手)

## 启动测试功能包
```bash
ros2 launch hand_test_bag hand_test.launch.py
```
## 启动moveit配置助手
```bash
ros2 launch moveit_setup_assistant setup_assistant.launch.py
```
## 启动moveit控制节点
```bash
ros2 launch hand_control hand_control.launch.py
```