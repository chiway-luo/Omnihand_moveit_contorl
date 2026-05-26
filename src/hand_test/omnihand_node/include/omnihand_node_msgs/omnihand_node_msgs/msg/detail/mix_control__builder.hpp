// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from omnihand_node_msgs:msg/MixControl.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__MIX_CONTROL__BUILDER_HPP_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__MIX_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "omnihand_node_msgs/msg/detail/mix_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace omnihand_node_msgs
{

namespace msg
{

namespace builder
{

class Init_MixControl_mix_controls
{
public:
  explicit Init_MixControl_mix_controls(::omnihand_node_msgs::msg::MixControl & msg)
  : msg_(msg)
  {}
  ::omnihand_node_msgs::msg::MixControl mix_controls(::omnihand_node_msgs::msg::MixControl::_mix_controls_type arg)
  {
    msg_.mix_controls = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omnihand_node_msgs::msg::MixControl msg_;
};

class Init_MixControl_header
{
public:
  Init_MixControl_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MixControl_mix_controls header(::omnihand_node_msgs::msg::MixControl::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MixControl_mix_controls(msg_);
  }

private:
  ::omnihand_node_msgs::msg::MixControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::omnihand_node_msgs::msg::MixControl>()
{
  return omnihand_node_msgs::msg::builder::Init_MixControl_header();
}

}  // namespace omnihand_node_msgs

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__MIX_CONTROL__BUILDER_HPP_
