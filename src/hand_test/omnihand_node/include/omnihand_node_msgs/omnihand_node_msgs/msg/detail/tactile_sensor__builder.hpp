// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from omnihand_node_msgs:msg/TactileSensor.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__TACTILE_SENSOR__BUILDER_HPP_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__TACTILE_SENSOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "omnihand_node_msgs/msg/detail/tactile_sensor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace omnihand_node_msgs
{

namespace msg
{

namespace builder
{

class Init_TactileSensor_tactile_datas
{
public:
  explicit Init_TactileSensor_tactile_datas(::omnihand_node_msgs::msg::TactileSensor & msg)
  : msg_(msg)
  {}
  ::omnihand_node_msgs::msg::TactileSensor tactile_datas(::omnihand_node_msgs::msg::TactileSensor::_tactile_datas_type arg)
  {
    msg_.tactile_datas = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omnihand_node_msgs::msg::TactileSensor msg_;
};

class Init_TactileSensor_header
{
public:
  Init_TactileSensor_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TactileSensor_tactile_datas header(::omnihand_node_msgs::msg::TactileSensor::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TactileSensor_tactile_datas(msg_);
  }

private:
  ::omnihand_node_msgs::msg::TactileSensor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::omnihand_node_msgs::msg::TactileSensor>()
{
  return omnihand_node_msgs::msg::builder::Init_TactileSensor_header();
}

}  // namespace omnihand_node_msgs

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__TACTILE_SENSOR__BUILDER_HPP_
