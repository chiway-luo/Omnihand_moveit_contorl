// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from omnihand_node_msgs:msg/MotorErrorReport.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__MOTOR_ERROR_REPORT__STRUCT_H_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__MOTOR_ERROR_REPORT__STRUCT_H_

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
// Member 'error_reports'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/MotorErrorReport in the package omnihand_node_msgs.
typedef struct omnihand_node_msgs__msg__MotorErrorReport
{
  std_msgs__msg__Header header;
  /// unsigned char stalled_ : 1;      // 堵转标志
  /// unsigned char overheat_ : 1;     // 过热标志
  /// unsigned char over_current_ : 1; // 过流标志
  /// unsigned char motor_except_ : 1; // 电机异常
  /// unsigned char commu_except_ : 1; // 通信异常
  /// unsigned char res1_ : 3;         // 保留位
  /// unsigned char res2_;             // 保留字节
  rosidl_runtime_c__uint16__Sequence error_reports;
} omnihand_node_msgs__msg__MotorErrorReport;

// Struct for a sequence of omnihand_node_msgs__msg__MotorErrorReport.
typedef struct omnihand_node_msgs__msg__MotorErrorReport__Sequence
{
  omnihand_node_msgs__msg__MotorErrorReport * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} omnihand_node_msgs__msg__MotorErrorReport__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__MOTOR_ERROR_REPORT__STRUCT_H_
