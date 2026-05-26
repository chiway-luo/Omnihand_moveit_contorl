// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from omnihand_node_msgs:msg/MotorAngle.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__MOTOR_ANGLE__BUILDER_HPP_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__MOTOR_ANGLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "omnihand_node_msgs/msg/detail/motor_angle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace omnihand_node_msgs
{

namespace msg
{

namespace builder
{

class Init_MotorAngle_angles
{
public:
  explicit Init_MotorAngle_angles(::omnihand_node_msgs::msg::MotorAngle & msg)
  : msg_(msg)
  {}
  ::omnihand_node_msgs::msg::MotorAngle angles(::omnihand_node_msgs::msg::MotorAngle::_angles_type arg)
  {
    msg_.angles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omnihand_node_msgs::msg::MotorAngle msg_;
};

class Init_MotorAngle_header
{
public:
  Init_MotorAngle_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorAngle_angles header(::omnihand_node_msgs::msg::MotorAngle::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MotorAngle_angles(msg_);
  }

private:
  ::omnihand_node_msgs::msg::MotorAngle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::omnihand_node_msgs::msg::MotorAngle>()
{
  return omnihand_node_msgs::msg::builder::Init_MotorAngle_header();
}

}  // namespace omnihand_node_msgs

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__MOTOR_ANGLE__BUILDER_HPP_
