// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from omnihand_node_msgs:msg/CurrentThreshold.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__CURRENT_THRESHOLD__BUILDER_HPP_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__CURRENT_THRESHOLD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "omnihand_node_msgs/msg/detail/current_threshold__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace omnihand_node_msgs
{

namespace msg
{

namespace builder
{

class Init_CurrentThreshold_current_thresholds
{
public:
  explicit Init_CurrentThreshold_current_thresholds(::omnihand_node_msgs::msg::CurrentThreshold & msg)
  : msg_(msg)
  {}
  ::omnihand_node_msgs::msg::CurrentThreshold current_thresholds(::omnihand_node_msgs::msg::CurrentThreshold::_current_thresholds_type arg)
  {
    msg_.current_thresholds = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omnihand_node_msgs::msg::CurrentThreshold msg_;
};

class Init_CurrentThreshold_header
{
public:
  Init_CurrentThreshold_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CurrentThreshold_current_thresholds header(::omnihand_node_msgs::msg::CurrentThreshold::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_CurrentThreshold_current_thresholds(msg_);
  }

private:
  ::omnihand_node_msgs::msg::CurrentThreshold msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::omnihand_node_msgs::msg::CurrentThreshold>()
{
  return omnihand_node_msgs::msg::builder::Init_CurrentThreshold_header();
}

}  // namespace omnihand_node_msgs

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__CURRENT_THRESHOLD__BUILDER_HPP_
