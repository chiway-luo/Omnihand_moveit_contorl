#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "omnihand_node_msgs/msg/motor_angle.hpp"
#include "omnihand_node_msgs/msg/control_mode.hpp"
/*
    工作流程:
    1. 订阅灵巧手驱动反馈 /agihand/omnihand/left/motor_angle (100Hz, 真实关节角度)
    2. 计算 mimic 关节角度，发布完整 /joint_states 给 MoveIt + robot_state_publisher
       → MoveIt 据此做碰撞检测，robot_state_publisher 据此发布 TF
    3. 订阅 /controller_joint_states (MoveIt fake controller 轨迹插值输出，
       已从 /joint_states 重映射，避免和真实状态冲突)
    4. 将轨迹指令转发到 /agihand/omnihand/left/motor_angle_cmd 控制真实灵巧手
*/

using namespace std::placeholders;

class HandControl : public rclcpp::Node {
public:
    HandControl() : Node("hand_control_node") {
        RCLCPP_INFO(this->get_logger(), "HandControl 节点已启动");

        // MoveIt 关节名 → MotorAngle.angles[] 索引（左手10个主动关节）
        joint_index_map_ = {
            {"L_thumb_roll_joint",  0},
            {"L_thumb_abad_joint",  1},
            {"L_thumb_mcp_joint",   2},
            {"L_index_abad_joint",  3},
            {"L_index_pip_joint",   4},
            {"L_middle_pip_joint",  5},
            {"L_ring_abad_joint",   6},
            {"L_ring_pip_joint",    7},
            {"L_pinky_abad_joint",  8},
            {"L_pinky_pip_joint",   9},
        };

        // 所有16个关节名（10主动 + 6 mimic）
        all_joint_names_ = {
            "L_thumb_roll_joint", "L_thumb_abad_joint", "L_thumb_mcp_joint",
            "L_thumb_pip_joint", "L_thumb_dip_joint",
            "L_index_abad_joint", "L_index_pip_joint", "L_index_dip_joint",
            "L_middle_pip_joint", "L_middle_dip_joint",
            "L_ring_abad_joint", "L_ring_pip_joint", "L_ring_dip_joint",
            "L_pinky_abad_joint", "L_pinky_pip_joint", "L_pinky_dip_joint",
        };

        // 发布控制模式（全部设为位置控制 = 0）
        pub_control_mode_ = this->create_publisher<omnihand_node_msgs::msg::ControlMode>(
            "/agihand/omnihand/left/control_mode_cmd", 10);
        auto mode_msg = omnihand_node_msgs::msg::ControlMode();
        mode_msg.modes = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        pub_control_mode_->publish(mode_msg);

        // 发布电机角度指令（转发 MoveIt 轨迹到真实驱动）
        pub_motor_angle_ = this->create_publisher<omnihand_node_msgs::msg::MotorAngle>(
            "/agihand/omnihand/left/motor_angle_cmd", 10);

        // 发布真实关节状态给 MoveIt + robot_state_publisher
        pub_joint_states_ = this->create_publisher<sensor_msgs::msg::JointState>(
            "/joint_states", 10);

        // 订阅灵巧手驱动反馈（真实关节角度 100Hz）
        sub_motor_angle_ = this->create_subscription<omnihand_node_msgs::msg::MotorAngle>(
            "/agihand/omnihand/left/motor_angle", 10,
            std::bind(&HandControl::motor_angle_callback, this, _1));

        // 订阅 MoveIt fake controller 轨迹插值输出（重映射到 /controller_joint_states）
        sub_controller_states_ = this->create_subscription<sensor_msgs::msg::JointState>(
            "/controller_joint_states", 10,
            std::bind(&HandControl::controller_states_callback, this, _1));
    }

private:
    std::unordered_map<std::string, int> joint_index_map_;
    std::vector<std::string> all_joint_names_;
    rclcpp::Publisher<omnihand_node_msgs::msg::ControlMode>::SharedPtr pub_control_mode_;
    rclcpp::Publisher<omnihand_node_msgs::msg::MotorAngle>::SharedPtr pub_motor_angle_;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr pub_joint_states_;
    rclcpp::Subscription<omnihand_node_msgs::msg::MotorAngle>::SharedPtr sub_motor_angle_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr sub_controller_states_;

    // 驱动反馈回调：真实关节 → /joint_states（MoveIt 碰撞检测 + TF 可视化）
    void motor_angle_callback(const omnihand_node_msgs::msg::MotorAngle::SharedPtr msg) {
        if (msg->angles.size() < 10) return;

        double thumb_roll = msg->angles[0];
        double thumb_abad = msg->angles[1];
        double thumb_mcp  = msg->angles[2];
        double index_abad = msg->angles[3];
        double index_pip  = msg->angles[4];
        double middle_pip = msg->angles[5];
        double ring_abad  = msg->angles[6];
        double ring_pip   = msg->angles[7];
        double pinky_abad = msg->angles[8];
        double pinky_pip  = msg->angles[9];

        // 计算 mimic 关节（与 URDF mimic 标签一致）
        double thumb_pip = thumb_mcp * 1.33;
        double thumb_dip = thumb_mcp * 1.30;
        double index_dip = index_pip * 1.097;
        double middle_dip = middle_pip * 1.097;
        double ring_dip  = ring_pip * 1.097;
        double pinky_dip = pinky_pip * 1.097;

        sensor_msgs::msg::JointState js;
        js.header.stamp = this->get_clock()->now();
        js.name = all_joint_names_;
        js.position = {
            thumb_roll, thumb_abad, thumb_mcp, thumb_pip, thumb_dip,
            index_abad, index_pip, index_dip,
            middle_pip, middle_dip,
            ring_abad, ring_pip, ring_dip,
            pinky_abad, pinky_pip, pinky_dip,
        };

        pub_joint_states_->publish(js);
    }

    // MoveIt 轨迹回调：将规划指令转发给真实驱动
    void controller_states_callback(const sensor_msgs::msg::JointState::SharedPtr msg) {
        omnihand_node_msgs::msg::MotorAngle motor_msg;
        motor_msg.header.stamp = this->get_clock()->now();
        motor_msg.header.frame_id = "angle_frame";
        motor_msg.angles.resize(10, 0.0);

        for (size_t i = 0; i < msg->name.size(); ++i) {
            auto it = joint_index_map_.find(msg->name[i]);
            if (it != joint_index_map_.end()) {
                motor_msg.angles[it->second] = msg->position[i];
            }
        }

        pub_motor_angle_->publish(motor_msg);
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<HandControl>());
    rclcpp::shutdown();
    return 0;
}