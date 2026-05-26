// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from omnihand_node_msgs:msg/TactileSensorData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "omnihand_node_msgs/msg/detail/tactile_sensor_data__struct.hpp"
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

void TactileSensorData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) omnihand_node_msgs::msg::TactileSensorData(_init);
}

void TactileSensorData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<omnihand_node_msgs::msg::TactileSensorData *>(message_memory);
  typed_message->~TactileSensorData();
}

size_t size_function__TactileSensorData__tactiles(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TactileSensorData__tactiles(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__TactileSensorData__tactiles(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__TactileSensorData__tactiles(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__TactileSensorData__tactiles(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__TactileSensorData__tactiles(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__TactileSensorData__tactiles(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

void resize_function__TactileSensorData__tactiles(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TactileSensorData_message_member_array[1] = {
  {
    "tactiles",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(omnihand_node_msgs::msg::TactileSensorData, tactiles),  // bytes offset in struct
    nullptr,  // default value
    size_function__TactileSensorData__tactiles,  // size() function pointer
    get_const_function__TactileSensorData__tactiles,  // get_const(index) function pointer
    get_function__TactileSensorData__tactiles,  // get(index) function pointer
    fetch_function__TactileSensorData__tactiles,  // fetch(index, &value) function pointer
    assign_function__TactileSensorData__tactiles,  // assign(index, value) function pointer
    resize_function__TactileSensorData__tactiles  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TactileSensorData_message_members = {
  "omnihand_node_msgs::msg",  // message namespace
  "TactileSensorData",  // message name
  1,  // number of fields
  sizeof(omnihand_node_msgs::msg::TactileSensorData),
  TactileSensorData_message_member_array,  // message members
  TactileSensorData_init_function,  // function to initialize message memory (memory has to be allocated)
  TactileSensorData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TactileSensorData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TactileSensorData_message_members,
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
get_message_type_support_handle<omnihand_node_msgs::msg::TactileSensorData>()
{
  return &::omnihand_node_msgs::msg::rosidl_typesupport_introspection_cpp::TactileSensorData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, omnihand_node_msgs, msg, TactileSensorData)() {
  return &::omnihand_node_msgs::msg::rosidl_typesupport_introspection_cpp::TactileSensorData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
