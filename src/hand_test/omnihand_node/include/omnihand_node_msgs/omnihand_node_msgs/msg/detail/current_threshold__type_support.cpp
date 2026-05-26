// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from omnihand_node_msgs:msg/CurrentThreshold.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "omnihand_node_msgs/msg/detail/current_threshold__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace omnihand_node_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void CurrentThreshold_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) omnihand_node_msgs::msg::CurrentThreshold(_init);
}

void CurrentThreshold_fini_function(void * message_memory)
{
  auto typed_message = static_cast<omnihand_node_msgs::msg::CurrentThreshold *>(message_memory);
  typed_message->~CurrentThreshold();
}

size_t size_function__CurrentThreshold__current_thresholds(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int16_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CurrentThreshold__current_thresholds(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int16_t> *>(untyped_member);
  return &member[index];
}

void * get_function__CurrentThreshold__current_thresholds(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int16_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__CurrentThreshold__current_thresholds(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int16_t *>(
    get_const_function__CurrentThreshold__current_thresholds(untyped_member, index));
  auto & value = *reinterpret_cast<int16_t *>(untyped_value);
  value = item;
}

void assign_function__CurrentThreshold__current_thresholds(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int16_t *>(
    get_function__CurrentThreshold__current_thresholds(untyped_member, index));
  const auto & value = *reinterpret_cast<const int16_t *>(untyped_value);
  item = value;
}

void resize_function__CurrentThreshold__current_thresholds(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int16_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CurrentThreshold_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(omnihand_node_msgs::msg::CurrentThreshold, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "current_thresholds",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(omnihand_node_msgs::msg::CurrentThreshold, current_thresholds),  // bytes offset in struct
    nullptr,  // default value
    size_function__CurrentThreshold__current_thresholds,  // size() function pointer
    get_const_function__CurrentThreshold__current_thresholds,  // get_const(index) function pointer
    get_function__CurrentThreshold__current_thresholds,  // get(index) function pointer
    fetch_function__CurrentThreshold__current_thresholds,  // fetch(index, &value) function pointer
    assign_function__CurrentThreshold__current_thresholds,  // assign(index, value) function pointer
    resize_function__CurrentThreshold__current_thresholds  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CurrentThreshold_message_members = {
  "omnihand_node_msgs::msg",  // message namespace
  "CurrentThreshold",  // message name
  2,  // number of fields
  sizeof(omnihand_node_msgs::msg::CurrentThreshold),
  CurrentThreshold_message_member_array,  // message members
  CurrentThreshold_init_function,  // function to initialize message memory (memory has to be allocated)
  CurrentThreshold_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CurrentThreshold_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CurrentThreshold_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace omnihand_node_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<omnihand_node_msgs::msg::CurrentThreshold>()
{
  return &::omnihand_node_msgs::msg::rosidl_typesupport_introspection_cpp::CurrentThreshold_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, omnihand_node_msgs, msg, CurrentThreshold)() {
  return &::omnihand_node_msgs::msg::rosidl_typesupport_introspection_cpp::CurrentThreshold_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
