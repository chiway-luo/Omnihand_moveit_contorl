#install(DIRECTORY config params launch DESTINATION share/${PROJECT_NAME}) #cmake配置
#<exec_depend>ros2launch</exec_depend> <!--package.xml配置-->
#from glob import glob #用于setup.py配置多个launch文件
#('share/' + package_name + '/launch', glob('launch/*launch.py')),
#('share/' + package_name + '/launch', glob('launch/*launch.xml')),
#('share/' + package_name + '/launch', glob('launch/*launch.yaml')),
#(os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),

from launch import LaunchDescription
from launch_ros.actions import Node
import os
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
from moveit_configs_utils import MoveItConfigsBuilder


def generate_launch_description():
    ld = LaunchDescription()

    moveit_config = MoveItConfigsBuilder(
        "omnihand", package_name="hand_moveit"
    ).to_moveit_configs()

    hand_moveit_dir = get_package_share_directory("hand_moveit")

    # ---------- 1. 静态 TF (virtual joint) ----------
    static_tf_launch = os.path.join(
        hand_moveit_dir, "launch", "static_virtual_joint_tfs.launch.py"
    )
    if os.path.exists(static_tf_launch):
        ld.add_action(
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(static_tf_launch)
            )
        )

    # ---------- 2. robot_state_publisher (读 /joint_states 发 TF) ----------
    ld.add_action(
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(hand_moveit_dir, "launch", "rsp.launch.py")
            )
        )
    )

    # ---------- 3. ros2_control_node (fake hardware) ----------
    # 关键：重映射 /joint_states → /controller_joint_states
    # 这样 fake controller 的轨迹插值输出不会覆盖真实关节状态
    ld.add_action(
        Node(
            package="controller_manager",
            executable="ros2_control_node",
            parameters=[
                moveit_config.robot_description,
                os.path.join(hand_moveit_dir, "config", "ros2_controllers.yaml"),
            ],
            remappings=[("/joint_states", "/controller_joint_states")],
            output="screen",
        )
    )

    # ---------- 4. 启动 controller spawners ----------
    controller_names = [
        "thumb_controller",
        "index_controller",
        "middle_controller",
        "ring_controller",
        "little_controller",
        "joint_state_broadcaster",
    ]
    for controller in controller_names:
        ld.add_action(
            Node(
                package="controller_manager",
                executable="spawner",
                arguments=[controller],
                output="screen",
            )
        )

    # ---------- 5. move_group ----------
    ld.add_action(
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(hand_moveit_dir, "launch", "move_group.launch.py")
            )
        )
    )

    # ---------- 6. RViz ----------
    ld.add_action(
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(hand_moveit_dir, "launch", "moveit_rviz.launch.py")
            )
        )
    )

    # ---------- 7. 灵巧手驱动节点 ----------
    ld.add_action(
        Node(
            package="omnihand_node",
            executable="hand_node",
            name="hand_driver_node",
            output="screen",
        )
    )

    # ---------- 8. hand_control 桥接节点 ----------
    # 真实驱动反馈 → /joint_states (MoveIt碰撞检测+TF)
    # /controller_joint_states (MoveIt轨迹) → 驱动指令
    ld.add_action(
        Node(
            package="hand_control",
            executable="hand_control",
            name="hand_control_node",
            output="screen",
        )
    )

    return ld

