// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from omnihand_node_msgs:msg/TemperatureReport.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__TEMPERATURE_REPORT__STRUCT_HPP_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__TEMPERATURE_REPORT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__omnihand_node_msgs__msg__TemperatureReport __attribute__((deprecated))
#else
# define DEPRECATED__omnihand_node_msgs__msg__TemperatureReport __declspec(deprecated)
#endif

namespace omnihand_node_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TemperatureReport_
{
  using Type = TemperatureReport_<ContainerAllocator>;

  explicit TemperatureReport_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit TemperatureReport_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _temperature_reports_type =
    std::vector<uint16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint16_t>>;
  _temperature_reports_type temperature_reports;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__temperature_reports(
    const std::vector<uint16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint16_t>> & _arg)
  {
    this->temperature_reports = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    omnihand_node_msgs::msg::TemperatureReport_<ContainerAllocator> *;
  using ConstRawPtr =
    const omnihand_node_msgs::msg::TemperatureReport_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<omnihand_node_msgs::msg::TemperatureReport_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<omnihand_node_msgs::msg::TemperatureReport_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      omnihand_node_msgs::msg::TemperatureReport_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<omnihand_node_msgs::msg::TemperatureReport_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      omnihand_node_msgs::msg::TemperatureReport_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<omnihand_node_msgs::msg::TemperatureReport_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<omnihand_node_msgs::msg::TemperatureReport_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<omnihand_node_msgs::msg::TemperatureReport_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__omnihand_node_msgs__msg__TemperatureReport
    std::shared_ptr<omnihand_node_msgs::msg::TemperatureReport_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__omnihand_node_msgs__msg__TemperatureReport
    std::shared_ptr<omnihand_node_msgs::msg::TemperatureReport_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TemperatureReport_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->temperature_reports != other.temperature_reports) {
      return false;
    }
    return true;
  }
  bool operator!=(const TemperatureReport_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TemperatureReport_

// alias to use template instance with default allocator
using TemperatureReport =
  omnihand_node_msgs::msg::TemperatureReport_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace omnihand_node_msgs

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__TEMPERATURE_REPORT__STRUCT_HPP_
