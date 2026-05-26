// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from omnihand_node_msgs:msg/TemperatureReport.idl
// generated code does not contain a copyright notice

#ifndef OMNIHAND_NODE_MSGS__MSG__DETAIL__TEMPERATURE_REPORT__FUNCTIONS_H_
#define OMNIHAND_NODE_MSGS__MSG__DETAIL__TEMPERATURE_REPORT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "omnihand_node_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "omnihand_node_msgs/msg/detail/temperature_report__struct.h"

/// Initialize msg/TemperatureReport message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * omnihand_node_msgs__msg__TemperatureReport
 * )) before or use
 * omnihand_node_msgs__msg__TemperatureReport__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_omnihand_node_msgs
bool
omnihand_node_msgs__msg__TemperatureReport__init(omnihand_node_msgs__msg__TemperatureReport * msg);

/// Finalize msg/TemperatureReport message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_omnihand_node_msgs
void
omnihand_node_msgs__msg__TemperatureReport__fini(omnihand_node_msgs__msg__TemperatureReport * msg);

/// Create msg/TemperatureReport message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * omnihand_node_msgs__msg__TemperatureReport__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_omnihand_node_msgs
omnihand_node_msgs__msg__TemperatureReport *
omnihand_node_msgs__msg__TemperatureReport__create();

/// Destroy msg/TemperatureReport message.
/**
 * It calls
 * omnihand_node_msgs__msg__TemperatureReport__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_omnihand_node_msgs
void
omnihand_node_msgs__msg__TemperatureReport__destroy(omnihand_node_msgs__msg__TemperatureReport * msg);

/// Check for msg/TemperatureReport message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_omnihand_node_msgs
bool
omnihand_node_msgs__msg__TemperatureReport__are_equal(const omnihand_node_msgs__msg__TemperatureReport * lhs, const omnihand_node_msgs__msg__TemperatureReport * rhs);

/// Copy a msg/TemperatureReport message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_omnihand_node_msgs
bool
omnihand_node_msgs__msg__TemperatureReport__copy(
  const omnihand_node_msgs__msg__TemperatureReport * input,
  omnihand_node_msgs__msg__TemperatureReport * output);

/// Initialize array of msg/TemperatureReport messages.
/**
 * It allocates the memory for the number of elements and calls
 * omnihand_node_msgs__msg__TemperatureReport__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_omnihand_node_msgs
bool
omnihand_node_msgs__msg__TemperatureReport__Sequence__init(omnihand_node_msgs__msg__TemperatureReport__Sequence * array, size_t size);

/// Finalize array of msg/TemperatureReport messages.
/**
 * It calls
 * omnihand_node_msgs__msg__TemperatureReport__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_omnihand_node_msgs
void
omnihand_node_msgs__msg__TemperatureReport__Sequence__fini(omnihand_node_msgs__msg__TemperatureReport__Sequence * array);

/// Create array of msg/TemperatureReport messages.
/**
 * It allocates the memory for the array and calls
 * omnihand_node_msgs__msg__TemperatureReport__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_omnihand_node_msgs
omnihand_node_msgs__msg__TemperatureReport__Sequence *
omnihand_node_msgs__msg__TemperatureReport__Sequence__create(size_t size);

/// Destroy array of msg/TemperatureReport messages.
/**
 * It calls
 * omnihand_node_msgs__msg__TemperatureReport__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_omnihand_node_msgs
void
omnihand_node_msgs__msg__TemperatureReport__Sequence__destroy(omnihand_node_msgs__msg__TemperatureReport__Sequence * array);

/// Check for msg/TemperatureReport message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_omnihand_node_msgs
bool
omnihand_node_msgs__msg__TemperatureReport__Sequence__are_equal(const omnihand_node_msgs__msg__TemperatureReport__Sequence * lhs, const omnihand_node_msgs__msg__TemperatureReport__Sequence * rhs);

/// Copy an array of msg/TemperatureReport messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_omnihand_node_msgs
bool
omnihand_node_msgs__msg__TemperatureReport__Sequence__copy(
  const omnihand_node_msgs__msg__TemperatureReport__Sequence * input,
  omnihand_node_msgs__msg__TemperatureReport__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // OMNIHAND_NODE_MSGS__MSG__DETAIL__TEMPERATURE_REPORT__FUNCTIONS_H_
