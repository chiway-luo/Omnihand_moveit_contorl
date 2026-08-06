#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "omnihand_node_msgs/msg/control_mode.hpp"
#include "omnihand_node_msgs/msg/motor_angle.hpp"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

using namespace std::placeholders;

class HandControl : public rclcpp::Node
{
public:
  HandControl()
  : Node("hand_control_node")
  {
    RCLCPP_INFO(this->get_logger(), "HandControl 节点已启动");

    joint_index_map_ = {
      {"L_thumb_roll_joint", 0},
      {"L_thumb_abad_joint", 1},
      {"L_thumb_mcp_joint", 2},
      {"L_index_abad_joint", 3},
      {"L_index_pip_joint", 4},
      {"L_middle_pip_joint", 5},
      {"L_ring_abad_joint", 6},
      {"L_ring_pip_joint", 7},
      {"L_pinky_abad_joint", 8},
      {"L_pinky_pip_joint", 9},
    };

    active_joint_names_ = {
      "L_thumb_roll_joint", "L_thumb_abad_joint", "L_thumb_mcp_joint",
      "L_index_abad_joint", "L_index_pip_joint", "L_middle_pip_joint",
      "L_ring_abad_joint", "L_ring_pip_joint", "L_pinky_abad_joint",
      "L_pinky_pip_joint",
    };

    // O10 USB 默认就是位置控制，v1.1.8 不支持切换控制模式。
    // 仅在需要兼容旧驱动时显式打开该参数。
    const bool send_legacy_control_mode =
      this->declare_parameter<bool>("send_legacy_control_mode", false);
    if (send_legacy_control_mode) {
      pub_control_mode_ =
        this->create_publisher<omnihand_node_msgs::msg::ControlMode>(
        "/agihand/omnihand/left/control_mode_cmd", 10);
      timer_control_mode_ = this->create_wall_timer(
        std::chrono::milliseconds(500),
        std::bind(&HandControl::send_control_mode, this));
    } else {
      RCLCPP_INFO(
        this->get_logger(),
        "O10 USB 使用 SDK 默认位置模式，不发送 legacy control_mode_cmd");
    }

    pub_motor_angle_ =
      this->create_publisher<omnihand_node_msgs::msg::MotorAngle>(
      "/agihand/omnihand/left/motor_angle_cmd", 10);
    pub_joint_states_ = this->create_publisher<sensor_msgs::msg::JointState>(
      "/joint_states", 10);

    sub_motor_angle_ =
      this->create_subscription<omnihand_node_msgs::msg::MotorAngle>(
      "/agihand/omnihand/left/motor_angle", 10,
      std::bind(&HandControl::motor_angle_callback, this, _1));
    sub_controller_states_ =
      this->create_subscription<sensor_msgs::msg::JointState>(
      "/controller_joint_states", 10,
      std::bind(&HandControl::controller_states_callback, this, _1));

    cached_positions_.assign(kActiveJointCount, 0.0);
    last_published_angles_.assign(kActiveJointCount, 0.0);
    previous_controller_angles_.assign(kActiveJointCount, 0.0);

    // 只发布10个独立关节。MoveIt 与 robot_state_publisher 依据 URDF
    // mimic 关系自行计算6个从动关节，避免多项式反馈与线性 mimic 模型冲突。
    js_msg_.name = active_joint_names_;
    js_msg_.position.assign(kActiveJointCount, 0.0);

    timer_republish_ = this->create_wall_timer(
      std::chrono::milliseconds(20),
      std::bind(&HandControl::republish_joint_states, this));
    timer_republish_->cancel();
  }

private:
  static constexpr std::size_t kActiveJointCount = 10;
  static constexpr std::size_t kRequiredAlignedFrames = 3;
  static constexpr double kAlignmentTolerance = 0.03;
  static constexpr double kPublishThreshold = 0.001;
  static constexpr double kControllerJumpLimit = 0.05;
  static constexpr double kControllerGapLimitSeconds = 0.25;
  static constexpr double kIdleTrackingTimeoutSeconds = 0.5;
  static constexpr double kIdleTrackingError = 0.1;
  static constexpr double kBoundsTolerance = 1.0e-4;

  inline static constexpr std::array<double, kActiveJointCount> kJointLower = {
    -1.12, -0.05, -0.8416, 0.0, 0.0, 0.0, -0.17, 0.0, -0.19, 0.0,
  };
  inline static constexpr std::array<double, kActiveJointCount> kJointUpper = {
    0.03, 1.64, 0.0, 0.16, 1.48, 1.48, 0.0, 1.48, 0.0, 1.48,
  };

  enum class BridgeState { WAIT_ALIGN, ARMED };

  std::unordered_map<std::string, std::size_t> joint_index_map_;
  std::vector<std::string> active_joint_names_;

  rclcpp::Publisher<omnihand_node_msgs::msg::ControlMode>::SharedPtr
    pub_control_mode_;
  rclcpp::Publisher<omnihand_node_msgs::msg::MotorAngle>::SharedPtr
    pub_motor_angle_;
  rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr pub_joint_states_;
  rclcpp::Subscription<omnihand_node_msgs::msg::MotorAngle>::SharedPtr
    sub_motor_angle_;
  rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr
    sub_controller_states_;
  rclcpp::TimerBase::SharedPtr timer_republish_;
  rclcpp::TimerBase::SharedPtr timer_control_mode_;

  int control_mode_send_count_ = 0;
  std::vector<double> cached_positions_;
  std::vector<double> last_published_angles_;
  std::vector<double> previous_controller_angles_;
  bool has_joint_data_ = false;
  bool driver_connected_ = false;
  bool has_controller_sample_ = false;
  bool has_published_command_ = false;
  std::size_t aligned_frame_count_ = 0;
  BridgeState bridge_state_ = BridgeState::WAIT_ALIGN;
  rclcpp::Time last_motor_time_;
  rclcpp::Time last_controller_time_;
  rclcpp::Time last_publish_time_;
  sensor_msgs::msg::JointState js_msg_;

  void send_control_mode()
  {
    auto mode_msg = omnihand_node_msgs::msg::ControlMode();
    mode_msg.modes.assign(kActiveJointCount, 0);
    pub_control_mode_->publish(mode_msg);
    ++control_mode_send_count_;

    if (pub_control_mode_->get_subscription_count() > 0 &&
      control_mode_send_count_ >= 3)
    {
      RCLCPP_INFO(this->get_logger(), "legacy 控制模式消息已发送");
      timer_control_mode_->cancel();
    } else if (control_mode_send_count_ >= 20) {
      RCLCPP_WARN(this->get_logger(), "legacy 控制模式发送已达上限");
      timer_control_mode_->cancel();
    }
  }

  void disarm_bridge(const char * reason)
  {
    if (bridge_state_ == BridgeState::ARMED) {
      RCLCPP_WARN(this->get_logger(), "[Bridge] 关闭轨迹转发: %s", reason);
    }
    bridge_state_ = BridgeState::WAIT_ALIGN;
    aligned_frame_count_ = 0;
    has_published_command_ = false;
  }

  void motor_angle_callback(
    const omnihand_node_msgs::msg::MotorAngle::SharedPtr msg)
  {
    if (msg->angles.size() != kActiveJointCount ||
      !std::all_of(
        msg->angles.begin(), msg->angles.end(),
        [](double value) {return std::isfinite(value);}))
    {
      RCLCPP_WARN_THROTTLE(
        this->get_logger(), *this->get_clock(), 3000,
        "忽略无效驱动反馈：期望10个有限角度，实际%zu个",
        msg->angles.size());
      return;
    }

    cached_positions_.assign(msg->angles.begin(), msg->angles.end());
    has_joint_data_ = true;
    last_motor_time_ = this->get_clock()->now();

    if (!driver_connected_) {
      driver_connected_ = true;
      disarm_bridge("驱动重新连接");
      RCLCPP_INFO(this->get_logger(), "灵巧手驱动已连接，开始接收10关节反馈");
    }

    if (timer_republish_->is_canceled()) {
      timer_republish_->reset();
      RCLCPP_INFO(this->get_logger(), "已启动50Hz /joint_states 重发");
    }
  }

  void republish_joint_states()
  {
    if (!has_joint_data_) {
      return;
    }

    if (driver_connected_ &&
      (this->get_clock()->now() - last_motor_time_).seconds() > 1.0)
    {
      driver_connected_ = false;
      disarm_bridge("驱动反馈超时");
      RCLCPP_ERROR(
        this->get_logger(),
        "灵巧手驱动掉线：超过1秒无反馈，停止节点以防止误执行");
      rclcpp::shutdown();
      return;
    }

    js_msg_.header.stamp = this->get_clock()->now();
    js_msg_.position = cached_positions_;
    pub_joint_states_->publish(js_msg_);
  }

  bool decode_controller_state(
    const sensor_msgs::msg::JointState & msg,
    std::vector<double> & angles)
  {
    if (msg.name.size() != msg.position.size()) {
      RCLCPP_WARN_THROTTLE(
        this->get_logger(), *this->get_clock(), 3000,
        "忽略控制器状态：name(%zu) 与 position(%zu) 长度不一致",
        msg.name.size(), msg.position.size());
      return false;
    }

    angles.assign(kActiveJointCount, 0.0);
    std::array<bool, kActiveJointCount> seen{};
    for (std::size_t i = 0; i < msg.name.size(); ++i) {
      const auto mapping = joint_index_map_.find(msg.name[i]);
      if (mapping == joint_index_map_.end()) {
        continue;
      }

      const std::size_t index = mapping->second;
      const double value = msg.position[i];
      if (seen[index] || !std::isfinite(value)) {
        RCLCPP_WARN_THROTTLE(
          this->get_logger(), *this->get_clock(), 3000,
          "忽略控制器状态：关节 %s 重复或角度非有限值",
          msg.name[i].c_str());
        return false;
      }
      if (value < kJointLower[index] - kBoundsTolerance ||
        value > kJointUpper[index] + kBoundsTolerance)
      {
        RCLCPP_ERROR_THROTTLE(
          this->get_logger(), *this->get_clock(), 3000,
          "忽略越界轨迹：%s=%.6f rad，允许[%.4f, %.4f]",
          msg.name[i].c_str(), value, kJointLower[index],
          kJointUpper[index]);
        return false;
      }

      angles[index] = value;
      seen[index] = true;
    }

    if (!std::all_of(seen.begin(), seen.end(), [](bool value) {return value;})) {
      RCLCPP_WARN_THROTTLE(
        this->get_logger(), *this->get_clock(), 3000,
        "忽略不完整控制器状态：必须同时包含左手10个主动关节");
      return false;
    }
    return true;
  }

  void controller_states_callback(
    const sensor_msgs::msg::JointState::SharedPtr msg)
  {
    if (!driver_connected_ || !has_joint_data_) {
      RCLCPP_WARN_THROTTLE(
        this->get_logger(), *this->get_clock(), 3000,
        "驱动未连接，忽略控制器输出");
      return;
    }

    std::vector<double> controller_angles;
    if (!decode_controller_state(*msg, controller_angles)) {
      disarm_bridge("控制器状态无效");
      return;
    }

    const rclcpp::Time now = this->get_clock()->now();
    bool reject_current_frame = false;
    if (has_controller_sample_ && bridge_state_ == BridgeState::ARMED) {
      const double gap = (now - last_controller_time_).seconds();
      if (gap > kControllerGapLimitSeconds) {
        disarm_bridge("控制器数据中断");
        reject_current_frame = true;
      } else {
        double max_step = 0.0;
        for (std::size_t i = 0; i < kActiveJointCount; ++i) {
          max_step = std::max(
            max_step,
            std::abs(controller_angles[i] - previous_controller_angles_[i]));
        }
        if (max_step > kControllerJumpLimit) {
          disarm_bridge("控制器状态突变");
          reject_current_frame = true;
        }
      }
    }

    previous_controller_angles_ = controller_angles;
    last_controller_time_ = now;
    has_controller_sample_ = true;
    if (reject_current_frame) {
      return;
    }

    if (bridge_state_ == BridgeState::WAIT_ALIGN) {
      double max_alignment_error = 0.0;
      for (std::size_t i = 0; i < kActiveJointCount; ++i) {
        max_alignment_error = std::max(
          max_alignment_error,
          std::abs(controller_angles[i] - cached_positions_[i]));
      }

      if (max_alignment_error <= kAlignmentTolerance) {
        ++aligned_frame_count_;
      } else {
        aligned_frame_count_ = 0;
      }

      if (aligned_frame_count_ >= kRequiredAlignedFrames) {
        bridge_state_ = BridgeState::ARMED;
        last_published_angles_ = cached_positions_;
        last_publish_time_ = now;
        has_published_command_ = false;
        RCLCPP_INFO(
          this->get_logger(),
          "[Bridge] fake controller 连续%zu帧与真手对齐，转发已武装",
          kRequiredAlignedFrames);
      } else {
        RCLCPP_INFO_THROTTLE(
          this->get_logger(), *this->get_clock(), 3000,
          "[Bridge] 等待 fake controller 对齐，当前最大误差 %.4f rad",
          max_alignment_error);
      }
      return;
    }

    if (has_published_command_ &&
      (now - last_publish_time_).seconds() > kIdleTrackingTimeoutSeconds)
    {
      double max_tracking_error = 0.0;
      for (std::size_t i = 0; i < kActiveJointCount; ++i) {
        max_tracking_error = std::max(
          max_tracking_error,
          std::abs(controller_angles[i] - cached_positions_[i]));
      }
      if (max_tracking_error > kIdleTrackingError) {
        disarm_bridge("轨迹停止后真实位置未跟上");
        return;
      }
    }

    double max_change = 0.0;
    for (std::size_t i = 0; i < kActiveJointCount; ++i) {
      max_change = std::max(
        max_change,
        std::abs(controller_angles[i] - last_published_angles_[i]));
    }
    if (max_change <= kPublishThreshold) {
      // 不更新基线：小幅变化需相对“上次实际发布值”累积。
      return;
    }

    auto motor_msg = omnihand_node_msgs::msg::MotorAngle();
    motor_msg.header.stamp = now;
    motor_msg.header.frame_id = "angle_frame";
    motor_msg.angles = controller_angles;
    pub_motor_angle_->publish(motor_msg);
    last_published_angles_ = controller_angles;
    last_publish_time_ = now;
    has_published_command_ = true;
  }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<HandControl>());
  rclcpp::shutdown();
  return 0;
}
