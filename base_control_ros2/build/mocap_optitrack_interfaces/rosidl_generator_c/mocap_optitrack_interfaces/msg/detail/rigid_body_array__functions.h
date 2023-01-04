// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from mocap_optitrack_interfaces:msg/RigidBodyArray.idl
// generated code does not contain a copyright notice

#ifndef MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__RIGID_BODY_ARRAY__FUNCTIONS_H_
#define MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__RIGID_BODY_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "mocap_optitrack_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "mocap_optitrack_interfaces/msg/detail/rigid_body_array__struct.h"

/// Initialize msg/RigidBodyArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mocap_optitrack_interfaces__msg__RigidBodyArray
 * )) before or use
 * mocap_optitrack_interfaces__msg__RigidBodyArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mocap_optitrack_interfaces
bool
mocap_optitrack_interfaces__msg__RigidBodyArray__init(mocap_optitrack_interfaces__msg__RigidBodyArray * msg);

/// Finalize msg/RigidBodyArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mocap_optitrack_interfaces
void
mocap_optitrack_interfaces__msg__RigidBodyArray__fini(mocap_optitrack_interfaces__msg__RigidBodyArray * msg);

/// Create msg/RigidBodyArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mocap_optitrack_interfaces__msg__RigidBodyArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mocap_optitrack_interfaces
mocap_optitrack_interfaces__msg__RigidBodyArray *
mocap_optitrack_interfaces__msg__RigidBodyArray__create();

/// Destroy msg/RigidBodyArray message.
/**
 * It calls
 * mocap_optitrack_interfaces__msg__RigidBodyArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mocap_optitrack_interfaces
void
mocap_optitrack_interfaces__msg__RigidBodyArray__destroy(mocap_optitrack_interfaces__msg__RigidBodyArray * msg);

/// Check for msg/RigidBodyArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mocap_optitrack_interfaces
bool
mocap_optitrack_interfaces__msg__RigidBodyArray__are_equal(const mocap_optitrack_interfaces__msg__RigidBodyArray * lhs, const mocap_optitrack_interfaces__msg__RigidBodyArray * rhs);

/// Copy a msg/RigidBodyArray message.
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
ROSIDL_GENERATOR_C_PUBLIC_mocap_optitrack_interfaces
bool
mocap_optitrack_interfaces__msg__RigidBodyArray__copy(
  const mocap_optitrack_interfaces__msg__RigidBodyArray * input,
  mocap_optitrack_interfaces__msg__RigidBodyArray * output);

/// Initialize array of msg/RigidBodyArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * mocap_optitrack_interfaces__msg__RigidBodyArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mocap_optitrack_interfaces
bool
mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence__init(mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence * array, size_t size);

/// Finalize array of msg/RigidBodyArray messages.
/**
 * It calls
 * mocap_optitrack_interfaces__msg__RigidBodyArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mocap_optitrack_interfaces
void
mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence__fini(mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence * array);

/// Create array of msg/RigidBodyArray messages.
/**
 * It allocates the memory for the array and calls
 * mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mocap_optitrack_interfaces
mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence *
mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence__create(size_t size);

/// Destroy array of msg/RigidBodyArray messages.
/**
 * It calls
 * mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mocap_optitrack_interfaces
void
mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence__destroy(mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence * array);

/// Check for msg/RigidBodyArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mocap_optitrack_interfaces
bool
mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence__are_equal(const mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence * lhs, const mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence * rhs);

/// Copy an array of msg/RigidBodyArray messages.
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
ROSIDL_GENERATOR_C_PUBLIC_mocap_optitrack_interfaces
bool
mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence__copy(
  const mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence * input,
  mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__RIGID_BODY_ARRAY__FUNCTIONS_H_
