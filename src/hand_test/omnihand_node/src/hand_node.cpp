/*
 * @Author: huangshiheng@agibot.com
 * @Date: 2025-11-06 17:29:45
 * @Description: OmniHand Pro Node implementation
 *
 * Copyright (c) 2025 by huangshiheng@agibot.com, All Rights Reserved.
 */

#include "omnihand_node/hand_node.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <stdexcept>

namespace omnihand
{

namespace
{

constexpr std::size_t kActiveJointCount = 10;
constexpr double kBoundsTolerance = 1.0e-4;

constexpr std::array<double, kActiveJointCount> kLeftJointLower = {
  -1.12, -0.05, -0.8416, 0.0, 0.0, 0.0, -0.17, 0.0, -0.19, 0.0,
};
constexpr std::array<double, kActiveJointCount> kLeftJointUpper = {
  0.03, 1.64, 0.0, 0.16, 1.48, 1.48, 0.0, 1.48, 0.0, 1.48,
};

bool has_valid_left_joint_angles(const std::vector<double> & angles)
{
  if (angles.size() != kActiveJointCount) {
    return false;
  }
  for (std::size_t i = 0; i < angles.size(); ++i) {
    if (!std::isfinite(angles[i]) ||
      angles[i] < kLeftJointLower[i] - kBoundsTolerance ||
      angles[i] > kLeftJointUpper[i] + kBoundsTolerance)
    {
      return false;
    }
  }
  return true;
}

}  // namespace

OmniHandProNode::OmniHandProNode(
  uint8_t device_id,
  agilink::omnihand::HandType hand_type,
  const std::string & uart_port,
  int32_t baudrate)
: Node("omnihand_node" + std::to_string(device_id))
{
  agibot_hand_ = agilink::omnihand::OmniHand2025::createHandByUsb(
    hand_type, device_id, uart_port, baudrate);

  if (!agibot_hand_) {
    RCLCPP_ERROR(
      this->get_logger(),
      "Failed to create OmniHand 2025 USB device on %s",
      uart_port.c_str());
    throw std::runtime_error("failed to create OmniHand 2025 USB device");
  }

  if (!agibot_hand_->Init()) {
    RCLCPP_ERROR(
      this->get_logger(),
      "Failed to initialize OmniHand 2025 USB device with ID %d on %s",
      device_id,
      uart_port.c_str());
    throw std::runtime_error("failed to initialize OmniHand 2025 USB device");
  }

  bool is_left = (hand_type == agilink::omnihand::HandType::LEFT);
  std::string topic_prefix = "";
  if (is_left) {
    topic_prefix = "/agihand/omnihand/left/";
  } else {
    topic_prefix = "/agihand/omnihand/right/";
  }

  // Initialize Publishers
  control_mode_publisher_ = this->create_publisher<omnihand_node_msgs::msg::ControlMode>(
    topic_prefix + "control_mode", 10);
  current_report_publisher_ = this->create_publisher<omnihand_node_msgs::msg::CurrentReport>(
    topic_prefix + "current_report", 10);
  current_threshold_publisher_ = this->create_publisher<omnihand_node_msgs::msg::CurrentThreshold>(
    topic_prefix + "current_threshold", 10);
  motor_error_report_publisher_ = this->create_publisher<omnihand_node_msgs::msg::MotorErrorReport>(
    topic_prefix + "motor_error_report", 10);
  motor_angle_publisher_ = this->create_publisher<omnihand_node_msgs::msg::MotorAngle>(
    topic_prefix + "motor_angle", 10);
  motor_pos_publisher_ = this->create_publisher<omnihand_node_msgs::msg::MotorPos>(
    topic_prefix + "motor_pos", 10);
  // motor_vel_publisher_ = this->create_publisher<omnihand_node_msgs::msg::MotorVel>(topic_prefix + "motor_vel", 10);
  tactile_sensor_publisher_ = this->create_publisher<omnihand_node_msgs::msg::TactileSensor>(
    topic_prefix + "tactile_sensor", 10);
  temperature_report_publisher_ =
    this->create_publisher<omnihand_node_msgs::msg::TemperatureReport>(
    topic_prefix + "temperature_report", 10);

  // Initialize Subscribers
  control_mode_subscriber_ = this->create_subscription<omnihand_node_msgs::msg::ControlMode>(
    topic_prefix + "control_mode_cmd", 10,
    std::bind(&OmniHandProNode::control_mode_callback, this, std::placeholders::_1));
  current_threshold_subscriber_ =
    this->create_subscription<omnihand_node_msgs::msg::CurrentThreshold>(
    topic_prefix + "current_threshold_cmd", 10,
    std::bind(&OmniHandProNode::current_threshold_callback, this, std::placeholders::_1));
  mix_control_subscriber_ = this->create_subscription<omnihand_node_msgs::msg::MixControl>(
    topic_prefix + "mix_control_cmd", 10,
    std::bind(&OmniHandProNode::mix_control_callback, this, std::placeholders::_1));
  motor_pos_subscriber_ = this->create_subscription<omnihand_node_msgs::msg::MotorPos>(
    topic_prefix + "motor_pos_cmd", 100,
    std::bind(&OmniHandProNode::motor_pos_callback, this, std::placeholders::_1));
  // motor_vel_subscriber_ = this->create_subscription<omnihand_node_msgs::msg::MotorVel>(
  //   topic_prefix + "motor_vel_cmd", 100, std::bind(&OmniHandProNode::motor_vel_callback, this, std::placeholders::_1));
  motor_angle_subscriber_ = this->create_subscription<omnihand_node_msgs::msg::MotorAngle>(
    topic_prefix + "motor_angle_cmd", 100,
    std::bind(&OmniHandProNode::motor_angle_callback, this, std::placeholders::_1));

  timer_1hz_ =
    this->create_wall_timer(
    std::chrono::milliseconds(1000),
    std::bind(&OmniHandProNode::timer_1hz_callback, this));

  timer_10hz_ = this->create_wall_timer(
    std::chrono::milliseconds(100),
    std::bind(&OmniHandProNode::timer_10hz_callback, this));

  RCLCPP_INFO(
    this->get_logger(),
    "OmniHand 2025 USB node initialized device with ID %d on %s at %d baud",
    device_id,
    uart_port.c_str(),
    baudrate);
}

OmniHandProNode::~OmniHandProNode()
{
  RCLCPP_INFO(this->get_logger(), "OmniHand 2025 USB node destroyed");
}

// Callback implementations
void OmniHandProNode::control_mode_callback(
  const omnihand_node_msgs::msg::ControlMode::SharedPtr msg)
{
  (void)msg;
  RCLCPP_WARN(
    this->get_logger(),
    "control_mode_cmd is retained for ROS interface compatibility but is not "
    "forwarded by the v1.1.8 USB bridge");
}

void OmniHandProNode::mix_control_callback(const omnihand_node_msgs::msg::MixControl::SharedPtr msg)
{
  (void)msg;
  RCLCPP_WARN(
    this->get_logger(),
    "mix_control_cmd is retained for ROS interface compatibility but its old "
    "packed format is not forwarded by the v1.1.8 USB bridge");
}

void OmniHandProNode::current_threshold_callback(
  const omnihand_node_msgs::msg::CurrentThreshold::SharedPtr msg)
{
  (void)msg;
  RCLCPP_WARN(
    this->get_logger(),
    "current_threshold_cmd is retained for ROS interface compatibility but is "
    "not forwarded until its safety units are revalidated for SDK v1.1.8");
}

void OmniHandProNode::motor_pos_callback(const omnihand_node_msgs::msg::MotorPos::SharedPtr msg)
{
  constexpr std::size_t kO10MotorCount = 10;
  constexpr int16_t kMinMotorPosition = 0;
  constexpr int16_t kMaxMotorPosition = 4096;

  if (msg->pos.size() != kO10MotorCount) {
    RCLCPP_ERROR(
      this->get_logger(),
      "Rejected motor position command: expected %zu values, received %zu",
      kO10MotorCount, msg->pos.size());
    return;
  }

  std::string log_str;
  std::vector<int16_t> vec_pos;
  for (auto pos : msg->pos) {
    if (pos < kMinMotorPosition || pos > kMaxMotorPosition) {
      RCLCPP_ERROR(
        this->get_logger(),
        "Rejected motor position command: value %d is outside [%d, %d]",
        static_cast<int>(pos), static_cast<int>(kMinMotorPosition),
        static_cast<int>(kMaxMotorPosition));
      return;
    }
    vec_pos.push_back(static_cast<int16_t>(pos));
    log_str += std::to_string(pos) + " ";
  }

  RCLCPP_INFO(
    this->get_logger(), "Received motor position command with %zu positions: %s",
    msg->pos.size(), log_str.c_str());
  std::lock_guard<std::mutex> lock(mutex_);
  const auto actual_positions = agibot_hand_->SetAllJointMotorPosi(vec_pos);
  if (actual_positions.size() != kO10MotorCount) {
    RCLCPP_ERROR(
      this->get_logger(),
      "SDK failed to apply motor position command: expected %zu feedback values, received %zu",
      kO10MotorCount, actual_positions.size());
  }
}

void OmniHandProNode::motor_vel_callback(const omnihand_node_msgs::msg::MotorVel::SharedPtr msg)
{
  constexpr std::size_t kO10MotorCount = 10;
  if (msg->vels.size() != kO10MotorCount) {
    RCLCPP_ERROR(
      this->get_logger(),
      "Rejected motor velocity command: expected %zu values, received %zu",
      kO10MotorCount, msg->vels.size());
    return;
  }

  RCLCPP_INFO(this->get_logger(), "Received motor velocity command");

  std::vector<int16_t> vec_velo;
  for (auto vel : msg->vels) {
    vec_velo.push_back(static_cast<int16_t>(vel));
  }

  std::lock_guard<std::mutex> lock(mutex_);
  agibot_hand_->SetAllJointMotorVelo(vec_velo);
}

void OmniHandProNode::motor_angle_callback(const omnihand_node_msgs::msg::MotorAngle::SharedPtr msg)
{
  const std::vector<double> vec_angle(msg->angles.begin(), msg->angles.end());
  if (!has_valid_left_joint_angles(vec_angle)) {
    RCLCPP_ERROR_THROTTLE(
      this->get_logger(), *this->get_clock(), 3000,
      "Rejected motor_angle_cmd: expected 10 finite left-hand angles within SDK v1.1.8 limits");
    return;
  }

  std::lock_guard<std::mutex> lock(mutex_);
  const auto applied_angles = agibot_hand_->SetAllActiveJointAngles(vec_angle);
  if (applied_angles.size() != kActiveJointCount) {
    RCLCPP_ERROR_THROTTLE(
      this->get_logger(), *this->get_clock(), 3000,
      "SDK SetAllActiveJointAngles failed: expected 10 returned angles, got %zu",
      applied_angles.size());
  }
}


// Timer callback implementations
void OmniHandProNode::timer_1hz_callback()
{
  std::lock_guard<std::mutex> lock(mutex_);
  publish_control_mode();
  publish_current_report();
  publish_motor_error_report();
  publish_temperature_report();
}

void OmniHandProNode::timer_10hz_callback()
{
  std::lock_guard<std::mutex> lock(mutex_);
  publish_motor_pos();
  // publish_motor_vel();
  publish_tactile_sensor();
  publish_motor_angle();
}

// Publisher implementations
void OmniHandProNode::publish_control_mode()
{
  auto msg = omnihand_node_msgs::msg::ControlMode();
  msg.header.stamp = this->now();
  msg.header.frame_id = "control_frame";
  control_mode_publisher_->publish(msg);
}

void OmniHandProNode::publish_current_report()
{
  auto msg = omnihand_node_msgs::msg::CurrentReport();
  msg.header.stamp = this->now();
  msg.header.frame_id = "current_frame";
  const auto reports = agibot_hand_->GetAllCurrentReport();
  msg.current_reports.reserve(reports.size());
  bool had_negative_value = false;
  for (const int16_t value : reports) {
    had_negative_value = had_negative_value || value < 0;
    msg.current_reports.push_back(
      value < 0 ? 0U : static_cast<uint16_t>(value));
  }
  if (had_negative_value) {
    RCLCPP_WARN_THROTTLE(
      this->get_logger(), *this->get_clock(), 5000,
      "Negative current report received; clamped to zero for the legacy uint16 ROS message");
  }
  current_report_publisher_->publish(msg);
}

void OmniHandProNode::publish_current_threshold()
{
  auto msg = omnihand_node_msgs::msg::CurrentThreshold();
  msg.header.stamp = this->now();
  msg.header.frame_id = "current_threshold_frame";
  auto thresholds = agibot_hand_->GetAllCurrentThreshold();
  msg.current_thresholds = thresholds;
  current_threshold_publisher_->publish(msg);
}

void OmniHandProNode::publish_motor_error_report()
{
  auto msg = omnihand_node_msgs::msg::MotorErrorReport();
  msg.header.stamp = this->now();
  msg.header.frame_id = "motor_error_frame";

  const auto error_reports = agibot_hand_->GetAllErrorReport();
  for (const auto & error_report : error_reports) {
    msg.error_reports.push_back(error_report.value_);
  }
  motor_error_report_publisher_->publish(msg);
}

void OmniHandProNode::publish_motor_pos()
{
  auto msg = omnihand_node_msgs::msg::MotorPos();
  msg.header.stamp = this->now();
  msg.header.frame_id = "motor_frame";
  auto positions = agibot_hand_->GetAllJointMotorPosi();
  msg.pos = positions;
  motor_pos_publisher_->publish(msg);
}

void OmniHandProNode::publish_motor_vel()
{
  auto msg = omnihand_node_msgs::msg::MotorVel();
  msg.header.stamp = this->now();
  msg.header.frame_id = "vel_frame";

  auto velocities = agibot_hand_->GetAllJointMotorVelo();

  msg.vels = velocities;
  motor_vel_publisher_->publish(msg);
}

void OmniHandProNode::publish_tactile_sensor()
{
  auto msg = omnihand_node_msgs::msg::TactileSensor();
  msg.header.stamp = this->now();
  msg.header.frame_id = "tactile_frame";

  const auto tactile_sensors = agibot_hand_->GetAllTactileSensorData();
  for (int i = 1; i <= 5; i++) {
    const auto finger = static_cast<agilink::omnihand::Finger>(i);
    const auto tactile_sensor = std::find_if(
      tactile_sensors.begin(), tactile_sensors.end(),
      [finger](const auto & data) {return data.sensor_id_ == finger;});
    auto msg_data = omnihand_node_msgs::msg::TactileSensorData();

    if (tactile_sensor != tactile_sensors.end()) {
      msg_data.tactiles = tactile_sensor->data_;
    }

    msg.tactile_datas.push_back(msg_data);
  }

  tactile_sensor_publisher_->publish(msg);
}

void OmniHandProNode::publish_temperature_report()
{
  auto msg = omnihand_node_msgs::msg::TemperatureReport();
  msg.header.stamp = this->now();
  msg.header.frame_id = "temperature_frame";

  const auto temperatures = agibot_hand_->GetAllTemperatureReport();
  msg.temperature_reports.reserve(temperatures.size());
  bool had_negative_value = false;
  for (const int16_t value : temperatures) {
    had_negative_value = had_negative_value || value < 0;
    msg.temperature_reports.push_back(
      value < 0 ? 0U : static_cast<uint16_t>(value));
  }
  if (had_negative_value) {
    RCLCPP_WARN_THROTTLE(
      this->get_logger(), *this->get_clock(), 5000,
      "Negative temperature report received; clamped to zero for the legacy uint16 ROS message");
  }
  temperature_report_publisher_->publish(msg);
}

void OmniHandProNode::publish_motor_angle()
{
  auto msg = omnihand_node_msgs::msg::MotorAngle();
  msg.header.stamp = this->now();
  msg.header.frame_id = "angle_frame";

  const auto angles = agibot_hand_->GetAllActiveJointAngles();
  if (angles.size() != kActiveJointCount ||
    !std::all_of(
      angles.begin(), angles.end(),
      [](double value) {return std::isfinite(value);}))
  {
    RCLCPP_WARN_THROTTLE(
      this->get_logger(), *this->get_clock(), 3000,
      "SDK returned invalid active-joint feedback: expected 10 finite angles, got %zu",
      angles.size());
    return;
  }
  msg.angles = angles;
  motor_angle_publisher_->publish(msg);
}

} // namespace omnihand
