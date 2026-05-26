// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from omnihand_node_msgs:msg/CurrentThreshold.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__CURRENT_THRESHOLD__TRAITS_HPP_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__CURRENT_THRESHOLD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "omnihand_node_msgs/msg/detail/current_threshold__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace omnihand_node_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CurrentThreshold & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: current_thresholds
  {
    if (msg.current_thresholds.size() == 0) {
      out << "current_thresholds: []";
    } else {
      out << "current_thresholds: [";
      size_t pending_items = msg.current_thresholds.size();
      for (auto item : msg.current_thresholds) {
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
  const CurrentThreshold & msg,
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

  // member: current_thresholds
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.current_thresholds.size() == 0) {
      out << "current_thresholds: []\n";
    } else {
      out << "current_thresholds:\n";
      for (auto item : msg.current_thresholds) {
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

inline std::string to_yaml(const CurrentThreshold & msg, bool use_flow_style = false)
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
  const omnihand_node_msgs::msg::CurrentThreshold & msg,
  std::ostream & out, size_t indentation = 0)
{
  omnihand_node_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use omnihand_node_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const omnihand_node_msgs::msg::CurrentThreshold & msg)
{
  return omnihand_node_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<omnihand_node_msgs::msg::CurrentThreshold>()
{
  return "omnihand_node_msgs::msg::CurrentThreshold";
}

template<>
inline const char * name<omnihand_node_msgs::msg::CurrentThreshold>()
{
  return "omnihand_node_msgs/msg/CurrentThreshold";
}

template<>
struct has_fixed_size<omnihand_node_msgs::msg::CurrentThreshold>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<omnihand_node_msgs::msg::CurrentThreshold>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<omnihand_node_msgs::msg::CurrentThreshold>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__CURRENT_THRESHOLD__TRAITS_HPP_
