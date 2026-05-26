// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from omnihand_node_msgs:msg/MotorPos.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "omnihand_node_msgs/msg/detail/motor_pos__rosidl_typesupport_introspection_c.h"
#include "omnihand_node_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "omnihand_node_msgs/msg/detail/motor_pos__functions.h"
#include "omnihand_node_msgs/msg/detail/motor_pos__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `pos`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__MotorPos_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  omnihand_node_msgs__msg__MotorPos__init(message_memory);
}

void omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__MotorPos_fini_function(void * message_memory)
{
  omnihand_node_msgs__msg__MotorPos__fini(message_memory);
}

size_t omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__size_function__MotorPos__pos(
  const void * untyped_member)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return member->size;
}

const void * omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__get_const_function__MotorPos__pos(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void * omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__get_function__MotorPos__pos(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__fetch_function__MotorPos__pos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int16_t * item =
    ((const int16_t *)
    omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__get_const_function__MotorPos__pos(untyped_member, index));
  int16_t * value =
    (int16_t *)(untyped_value);
  *value = *item;
}

void omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__assign_function__MotorPos__pos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int16_t * item =
    ((int16_t *)
    omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__get_function__MotorPos__pos(untyped_member, index));
  const int16_t * value =
    (const int16_t *)(untyped_value);
  *item = *value;
}

bool omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__resize_function__MotorPos__pos(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  rosidl_runtime_c__int16__Sequence__fini(member);
  return rosidl_runtime_c__int16__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__MotorPos_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(omnihand_node_msgs__msg__MotorPos, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(omnihand_node_msgs__msg__MotorPos, pos),  // bytes offset in struct
    NULL,  // default value
    omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__size_function__MotorPos__pos,  // size() function pointer
    omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__get_const_function__MotorPos__pos,  // get_const(index) function pointer
    omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__get_function__MotorPos__pos,  // get(index) function pointer
    omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__fetch_function__MotorPos__pos,  // fetch(index, &value) function pointer
    omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__assign_function__MotorPos__pos,  // assign(index, value) function pointer
    omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__resize_function__MotorPos__pos  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__MotorPos_message_members = {
  "omnihand_node_msgs__msg",  // message namespace
  "MotorPos",  // message name
  2,  // number of fields
  sizeof(omnihand_node_msgs__msg__MotorPos),
  omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__MotorPos_message_member_array,  // message members
  omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__MotorPos_init_function,  // function to initialize message memory (memory has to be allocated)
  omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__MotorPos_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__MotorPos_message_type_support_handle = {
  0,
  &omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__MotorPos_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_omnihand_node_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, omnihand_node_msgs, msg, MotorPos)() {
  omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__MotorPos_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__MotorPos_message_type_support_handle.typesupport_identifier) {
    omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__MotorPos_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &omnihand_node_msgs__msg__MotorPos__rosidl_typesupport_introspection_c__MotorPos_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
