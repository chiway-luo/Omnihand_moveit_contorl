// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from omnihand_node_msgs:msg/MotorPos.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__MOTOR_POS__BUILDER_HPP_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__MOTOR_POS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "omnihand_node_msgs/msg/detail/motor_pos__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace omnihand_node_msgs
{

namespace msg
{

namespace builder
{

class Init_MotorPos_pos
{
public:
  explicit Init_MotorPos_pos(::omnihand_node_msgs::msg::MotorPos & msg)
  : msg_(msg)
  {}
  ::omnihand_node_msgs::msg::MotorPos pos(::omnihand_node_msgs::msg::MotorPos::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omnihand_node_msgs::msg::MotorPos msg_;
};

class Init_MotorPos_header
{
public:
  Init_MotorPos_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorPos_pos header(::omnihand_node_msgs::msg::MotorPos::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MotorPos_pos(msg_);
  }

private:
  ::omnihand_node_msgs::msg::MotorPos msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::omnihand_node_msgs::msg::MotorPos>()
{
  return omnihand_node_msgs::msg::builder::Init_MotorPos_header();
}

}  // namespace omnihand_node_msgs

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__MOTOR_POS__BUILDER_HPP_
