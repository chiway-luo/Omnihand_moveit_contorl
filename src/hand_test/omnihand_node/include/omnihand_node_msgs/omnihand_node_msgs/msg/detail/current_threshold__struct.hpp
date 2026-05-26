// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from omnihand_node_msgs:msg/CurrentThreshold.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__CURRENT_THRESHOLD__STRUCT_HPP_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__CURRENT_THRESHOLD__STRUCT_HPP_

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
# define DEPRECATED__omnihand_node_msgs__msg__CurrentThreshold __attribute__((deprecated))
#else
# define DEPRECATED__omnihand_node_msgs__msg__CurrentThreshold __declspec(deprecated)
#endif

namespace omnihand_node_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CurrentThreshold_
{
  using Type = CurrentThreshold_<ContainerAllocator>;

  explicit CurrentThreshold_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit CurrentThreshold_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _current_thresholds_type =
    std::vector<int16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int16_t>>;
  _current_thresholds_type current_thresholds;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__current_thresholds(
    const std::vector<int16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int16_t>> & _arg)
  {
    this->current_thresholds = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    omnihand_node_msgs::msg::CurrentThreshold_<ContainerAllocator> *;
  using ConstRawPtr =
    const omnihand_node_msgs::msg::CurrentThreshold_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<omnihand_node_msgs::msg::CurrentThreshold_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<omnihand_node_msgs::msg::CurrentThreshold_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      omnihand_node_msgs::msg::CurrentThreshold_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<omnihand_node_msgs::msg::CurrentThreshold_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      omnihand_node_msgs::msg::CurrentThreshold_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<omnihand_node_msgs::msg::CurrentThreshold_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<omnihand_node_msgs::msg::CurrentThreshold_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<omnihand_node_msgs::msg::CurrentThreshold_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__omnihand_node_msgs__msg__CurrentThreshold
    std::shared_ptr<omnihand_node_msgs::msg::CurrentThreshold_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__omnihand_node_msgs__msg__CurrentThreshold
    std::shared_ptr<omnihand_node_msgs::msg::CurrentThreshold_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CurrentThreshold_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->current_thresholds != other.current_thresholds) {
      return false;
    }
    return true;
  }
  bool operator!=(const CurrentThreshold_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CurrentThreshold_

// alias to use template instance with default allocator
using CurrentThreshold =
  omnihand_node_msgs::msg::CurrentThreshold_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace omnihand_node_msgs

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__CURRENT_THRESHOLD__STRUCT_HPP_
