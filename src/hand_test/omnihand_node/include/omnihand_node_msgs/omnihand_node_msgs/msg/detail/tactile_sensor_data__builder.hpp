// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from omnihand_node_msgs:msg/TactileSensorData.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__TACTILE_SENSOR_DATA__BUILDER_HPP_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__TACTILE_SENSOR_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "omnihand_node_msgs/msg/detail/tactile_sensor_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace omnihand_node_msgs
{

namespace msg
{

namespace builder
{

class Init_TactileSensorData_tactiles
{
public:
  Init_TactileSensorData_tactiles()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::omnihand_node_msgs::msg::TactileSensorData tactiles(::omnihand_node_msgs::msg::TactileSensorData::_tactiles_type arg)
  {
    msg_.tactiles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omnihand_node_msgs::msg::TactileSensorData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::omnihand_node_msgs::msg::TactileSensorData>()
{
  return omnihand_node_msgs::msg::builder::Init_TactileSensorData_tactiles();
}

}  // namespace omnihand_node_msgs

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__TACTILE_SENSOR_DATA__BUILDER_HPP_
