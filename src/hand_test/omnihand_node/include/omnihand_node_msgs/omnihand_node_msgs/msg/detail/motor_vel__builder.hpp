// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from omnihand_node_msgs:msg/MotorVel.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__MOTOR_VEL__BUILDER_HPP_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__MOTOR_VEL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "omnihand_node_msgs/msg/detail/motor_vel__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace omnihand_node_msgs
{

namespace msg
{

namespace builder
{

class Init_MotorVel_vels
{
public:
  explicit Init_MotorVel_vels(::omnihand_node_msgs::msg::MotorVel & msg)
  : msg_(msg)
  {}
  ::omnihand_node_msgs::msg::MotorVel vels(::omnihand_node_msgs::msg::MotorVel::_vels_type arg)
  {
    msg_.vels = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omnihand_node_msgs::msg::MotorVel msg_;
};

class Init_MotorVel_header
{
public:
  Init_MotorVel_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorVel_vels header(::omnihand_node_msgs::msg::MotorVel::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MotorVel_vels(msg_);
  }

private:
  ::omnihand_node_msgs::msg::MotorVel msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::omnihand_node_msgs::msg::MotorVel>()
{
  return omnihand_node_msgs::msg::builder::Init_MotorVel_header();
}

}  // namespace omnihand_node_msgs

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__MOTOR_VEL__BUILDER_HPP_
