// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from omnihand_node_msgs:msg/MotorErrorReport.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__MOTOR_ERROR_REPORT__BUILDER_HPP_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__MOTOR_ERROR_REPORT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "omnihand_node_msgs/msg/detail/motor_error_report__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace omnihand_node_msgs
{

namespace msg
{

namespace builder
{

class Init_MotorErrorReport_error_reports
{
public:
  explicit Init_MotorErrorReport_error_reports(::omnihand_node_msgs::msg::MotorErrorReport & msg)
  : msg_(msg)
  {}
  ::omnihand_node_msgs::msg::MotorErrorReport error_reports(::omnihand_node_msgs::msg::MotorErrorReport::_error_reports_type arg)
  {
    msg_.error_reports = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omnihand_node_msgs::msg::MotorErrorReport msg_;
};

class Init_MotorErrorReport_header
{
public:
  Init_MotorErrorReport_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorErrorReport_error_reports header(::omnihand_node_msgs::msg::MotorErrorReport::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MotorErrorReport_error_reports(msg_);
  }

private:
  ::omnihand_node_msgs::msg::MotorErrorReport msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::omnihand_node_msgs::msg::MotorErrorReport>()
{
  return omnihand_node_msgs::msg::builder::Init_MotorErrorReport_header();
}

}  // namespace omnihand_node_msgs

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__MOTOR_ERROR_REPORT__BUILDER_HPP_
