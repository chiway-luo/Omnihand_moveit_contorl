# 基于moveit的路径规划实现自动规划手指移动的功能

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
- hand_description 描述文件

- hand_moveit moveit路径规划算法

- hand_control 
```
目标角节点
→ MoveGroupInterface 设 joint target 并 plan/execute
→ MoveIt 把轨迹发到 /<controller_name>/follow_joint_trajectory
→ joint_trajectory_controller
→ 你的硬件驱动层把命令转换成下位机 API
→ 下位机执行
→ 当前关节状态回传
→ /joint_states
→ RViz 同步显示真实执行状态
```