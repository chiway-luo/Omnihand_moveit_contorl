// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from omnihand_node_msgs:msg/MotorVel.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__MOTOR_VEL__STRUCT_H_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__MOTOR_VEL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'vels'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/MotorVel in the package omnihand_node_msgs.
typedef struct omnihand_node_msgs__msg__MotorVel
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__int16__Sequence vels;
} omnihand_node_msgs__msg__MotorVel;

// Struct for a sequence of omnihand_node_msgs__msg__MotorVel.
typedef struct omnihand_node_msgs__msg__MotorVel__Sequence
{
  omnihand_node_msgs__msg__MotorVel * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} omnihand_node_msgs__msg__MotorVel__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__MOTOR_VEL__STRUCT_H_
