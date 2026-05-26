// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from omnihand_node_msgs:msg/TemperatureReport.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__TEMPERATURE_REPORT__BUILDER_HPP_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__TEMPERATURE_REPORT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "omnihand_node_msgs/msg/detail/temperature_report__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace omnihand_node_msgs
{

namespace msg
{

namespace builder
{

class Init_TemperatureReport_temperature_reports
{
public:
  explicit Init_TemperatureReport_temperature_reports(::omnihand_node_msgs::msg::TemperatureReport & msg)
  : msg_(msg)
  {}
  ::omnihand_node_msgs::msg::TemperatureReport temperature_reports(::omnihand_node_msgs::msg::TemperatureReport::_temperature_reports_type arg)
  {
    msg_.temperature_reports = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omnihand_node_msgs::msg::TemperatureReport msg_;
};

class Init_TemperatureReport_header
{
public:
  Init_TemperatureReport_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TemperatureReport_temperature_reports header(::omnihand_node_msgs::msg::TemperatureReport::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TemperatureReport_temperature_reports(msg_);
  }

private:
  ::omnihand_node_msgs::msg::TemperatureReport msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::omnihand_node_msgs::msg::TemperatureReport>()
{
  return omnihand_node_msgs::msg::builder::Init_TemperatureReport_header();
}

}  // namespace omnihand_node_msgs

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__TEMPERATURE_REPORT__BUILDER_HPP_
