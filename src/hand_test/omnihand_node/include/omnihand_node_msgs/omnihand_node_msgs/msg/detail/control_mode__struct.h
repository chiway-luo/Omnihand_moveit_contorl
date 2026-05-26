// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from omnihand_node_msgs:msg/ControlMode.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__CONTROL_MODE__STRUCT_H_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__CONTROL_MODE__STRUCT_H_

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
// Member 'modes'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/ControlMode in the package omnihand_node_msgs.
typedef struct omnihand_node_msgs__msg__ControlMode
{
  std_msgs__msg__Header header;
  /// ePosi = 0,                    // 位置控制
  /// eVelo = 1,                    // 速度控制
  /// eTorque = 2,                  // 力矩控制
  /// ePosiTorque = 3,              // 位置-力矩混合控制
  /// eVeloTorque = 4,              // 速度-力矩混合控制
  /// ePosiVeloTorque = 5,          // 位置-速度-力矩混合控制
  /// eUnknown = 10                 // 未知模式
  rosidl_runtime_c__int8__Sequence modes;
} omnihand_node_msgs__msg__ControlMode;

// Struct for a sequence of omnihand_node_msgs__msg__ControlMode.
typedef struct omnihand_node_msgs__msg__ControlMode__Sequence
{
  omnihand_node_msgs__msg__ControlMode * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} omnihand_node_msgs__msg__ControlMode__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__CONTROL_MODE__STRUCT_H_
