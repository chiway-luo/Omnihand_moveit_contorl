// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from omnihand_node_msgs:msg/TactileSensor.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__TACTILE_SENSOR__STRUCT_H_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__TACTILE_SENSOR__STRUCT_H_

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
// Member 'tactile_datas'
#include "omnihand_node_msgs/msg/detail/tactile_sensor_data__struct.h"

/// Struct defined in msg/TactileSensor in the package omnihand_node_msgs.
typedef struct omnihand_node_msgs__msg__TactileSensor
{
  std_msgs__msg__Header header;
  omnihand_node_msgs__msg__TactileSensorData__Sequence tactile_datas;
} omnihand_node_msgs__msg__TactileSensor;

// Struct for a sequence of omnihand_node_msgs__msg__TactileSensor.
typedef struct omnihand_node_msgs__msg__TactileSensor__Sequence
{
  omnihand_node_msgs__msg__TactileSensor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} omnihand_node_msgs__msg__TactileSensor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__TACTILE_SENSOR__STRUCT_H_
