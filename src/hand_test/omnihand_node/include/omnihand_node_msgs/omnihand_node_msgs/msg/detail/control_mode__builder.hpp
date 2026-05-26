// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from omnihand_node_msgs:msg/ControlMode.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__CONTROL_MODE__BUILDER_HPP_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__CONTROL_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "omnihand_node_msgs/msg/detail/control_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace omnihand_node_msgs
{

namespace msg
{

namespace builder
{

class Init_ControlMode_modes
{
public:
  explicit Init_ControlMode_modes(::omnihand_node_msgs::msg::ControlMode & msg)
  : msg_(msg)
  {}
  ::omnihand_node_msgs::msg::ControlMode modes(::omnihand_node_msgs::msg::ControlMode::_modes_type arg)
  {
    msg_.modes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omnihand_node_msgs::msg::ControlMode msg_;
};

class Init_ControlMode_header
{
public:
  Init_ControlMode_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ControlMode_modes header(::omnihand_node_msgs::msg::ControlMode::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ControlMode_modes(msg_);
  }

private:
  ::omnihand_node_msgs::msg::ControlMode msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::omnihand_node_msgs::msg::ControlMode>()
{
  return omnihand_node_msgs::msg::builder::Init_ControlMode_header();
}

}  // namespace omnihand_node_msgs

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__CONTROL_MODE__BUILDER_HPP_
