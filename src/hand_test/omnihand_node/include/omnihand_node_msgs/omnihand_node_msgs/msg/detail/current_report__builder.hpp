// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from omnihand_node_msgs:msg/CurrentReport.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__CURRENT_REPORT__BUILDER_HPP_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__CURRENT_REPORT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "omnihand_node_msgs/msg/detail/current_report__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace omnihand_node_msgs
{

namespace msg
{

namespace builder
{

class Init_CurrentReport_current_reports
{
public:
  explicit Init_CurrentReport_current_reports(::omnihand_node_msgs::msg::CurrentReport & msg)
  : msg_(msg)
  {}
  ::omnihand_node_msgs::msg::CurrentReport current_reports(::omnihand_node_msgs::msg::CurrentReport::_current_reports_type arg)
  {
    msg_.current_reports = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omnihand_node_msgs::msg::CurrentReport msg_;
};

class Init_CurrentReport_header
{
public:
  Init_CurrentReport_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CurrentReport_current_reports header(::omnihand_node_msgs::msg::CurrentReport::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_CurrentReport_current_reports(msg_);
  }

private:
  ::omnihand_node_msgs::msg::CurrentReport msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::omnihand_node_msgs::msg::CurrentReport>()
{
  return omnihand_node_msgs::msg::builder::Init_CurrentReport_header();
}

}  // namespace omnihand_node_msgs

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__CURRENT_REPORT__BUILDER_HPP_
