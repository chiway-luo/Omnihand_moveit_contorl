// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from omnihand_node_msgs:msg/ControlMode.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "omnihand_node_msgs/msg/detail/control_mode__rosidl_typesupport_introspection_c.h"
#include "omnihand_node_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "omnihand_node_msgs/msg/detail/control_mode__functions.h"
#include "omnihand_node_msgs/msg/detail/control_mode__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `modes`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__ControlMode_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  omnihand_node_msgs__msg__ControlMode__init(message_memory);
}

void omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__ControlMode_fini_function(void * message_memory)
{
  omnihand_node_msgs__msg__ControlMode__fini(message_memory);
}

size_t omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__size_function__ControlMode__modes(
  const void * untyped_member)
{
  const rosidl_runtime_c__int8__Sequence * member =
    (const rosidl_runtime_c__int8__Sequence *)(untyped_member);
  return member->size;
}

const void * omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__get_const_function__ControlMode__modes(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int8__Sequence * member =
    (const rosidl_runtime_c__int8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__get_function__ControlMode__modes(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int8__Sequence * member =
    (rosidl_runtime_c__int8__Sequence *)(untyped_member);
  return &member->data[index];
}

void omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__fetch_function__ControlMode__modes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int8_t * item =
    ((const int8_t *)
    omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__get_const_function__ControlMode__modes(untyped_member, index));
  int8_t * value =
    (int8_t *)(untyped_value);
  *value = *item;
}

void omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__assign_function__ControlMode__modes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int8_t * item =
    ((int8_t *)
    omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__get_function__ControlMode__modes(untyped_member, index));
  const int8_t * value =
    (const int8_t *)(untyped_value);
  *item = *value;
}

bool omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__resize_function__ControlMode__modes(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int8__Sequence * member =
    (rosidl_runtime_c__int8__Sequence *)(untyped_member);
  rosidl_runtime_c__int8__Sequence__fini(member);
  return rosidl_runtime_c__int8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__ControlMode_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(omnihand_node_msgs__msg__ControlMode, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "modes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(omnihand_node_msgs__msg__ControlMode, modes),  // bytes offset in struct
    NULL,  // default value
    omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__size_function__ControlMode__modes,  // size() function pointer
    omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__get_const_function__ControlMode__modes,  // get_const(index) function pointer
    omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__get_function__ControlMode__modes,  // get(index) function pointer
    omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__fetch_function__ControlMode__modes,  // fetch(index, &value) function pointer
    omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__assign_function__ControlMode__modes,  // assign(index, value) function pointer
    omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__resize_function__ControlMode__modes  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__ControlMode_message_members = {
  "omnihand_node_msgs__msg",  // message namespace
  "ControlMode",  // message name
  2,  // number of fields
  sizeof(omnihand_node_msgs__msg__ControlMode),
  omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__ControlMode_message_member_array,  // message members
  omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__ControlMode_init_function,  // function to initialize message memory (memory has to be allocated)
  omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__ControlMode_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__ControlMode_message_type_support_handle = {
  0,
  &omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__ControlMode_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_omnihand_node_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, omnihand_node_msgs, msg, ControlMode)() {
  omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__ControlMode_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__ControlMode_message_type_support_handle.typesupport_identifier) {
    omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__ControlMode_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &omnihand_node_msgs__msg__ControlMode__rosidl_typesupport_introspection_c__ControlMode_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
