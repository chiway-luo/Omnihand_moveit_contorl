// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from omnihand_node_msgs:msg/TactileSensorData.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__TACTILE_SENSOR_DATA__STRUCT_H_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__TACTILE_SENSOR_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'tactiles'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/TactileSensorData in the package omnihand_node_msgs.
typedef struct omnihand_node_msgs__msg__TactileSensorData
{
  rosidl_runtime_c__uint8__Sequence tactiles;
} omnihand_node_msgs__msg__TactileSensorData;

// Struct for a sequence of omnihand_node_msgs__msg__TactileSensorData.
typedef struct omnihand_node_msgs__msg__TactileSensorData__Sequence
{
  omnihand_node_msgs__msg__TactileSensorData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} omnihand_node_msgs__msg__TactileSensorData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__TACTILE_SENSOR_DATA__STRUCT_H_
