// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from omnihand_node_msgs:msg/TemperatureReport.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__TEMPERATURE_REPORT__TRAITS_HPP_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__TEMPERATURE_REPORT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "omnihand_node_msgs/msg/detail/temperature_report__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace omnihand_node_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TemperatureReport & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: temperature_reports
  {
    if (msg.temperature_reports.size() == 0) {
      out << "temperature_reports: []";
    } else {
      out << "temperature_reports: [";
      size_t pending_items = msg.temperature_reports.size();
      for (auto item : msg.temperature_reports) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TemperatureReport & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: temperature_reports
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.temperature_reports.size() == 0) {
      out << "temperature_reports: []\n";
    } else {
      out << "temperature_reports:\n";
      for (auto item : msg.temperature_reports) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TemperatureReport & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace omnihand_node_msgs

namespace rosidl_generator_traits
{

[[deprecated("use omnihand_node_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const omnihand_node_msgs::msg::TemperatureReport & msg,
  std::ostream & out, size_t indentation = 0)
{
  omnihand_node_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use omnihand_node_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const omnihand_node_msgs::msg::TemperatureReport & msg)
{
  return omnihand_node_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<omnihand_node_msgs::msg::TemperatureReport>()
{
  return "omnihand_node_msgs::msg::TemperatureReport";
}

template<>
inline const char * name<omnihand_node_msgs::msg::TemperatureReport>()
{
  return "omnihand_node_msgs/msg/TemperatureReport";
}

template<>
struct has_fixed_size<omnihand_node_msgs::msg::TemperatureReport>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<omnihand_node_msgs::msg::TemperatureReport>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<omnihand_node_msgs::msg::TemperatureReport>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__TEMPERATURE_REPORT__TRAITS_HPP_
