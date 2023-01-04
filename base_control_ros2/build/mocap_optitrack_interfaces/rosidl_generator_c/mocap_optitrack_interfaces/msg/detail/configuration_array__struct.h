// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mocap_optitrack_interfaces:msg/ConfigurationArray.idl
// generated code does not contain a copyright notice

#ifndef MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION_ARRAY__STRUCT_H_
#define MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'configurations'
#include "mocap_optitrack_interfaces/msg/detail/configuration__struct.h"

/// Struct defined in msg/ConfigurationArray in the package mocap_optitrack_interfaces.
/**
  * Array of configuration vectors
 */
typedef struct mocap_optitrack_interfaces__msg__ConfigurationArray
{
  mocap_optitrack_interfaces__msg__Configuration__Sequence configurations;
} mocap_optitrack_interfaces__msg__ConfigurationArray;

// Struct for a sequence of mocap_optitrack_interfaces__msg__ConfigurationArray.
typedef struct mocap_optitrack_interfaces__msg__ConfigurationArray__Sequence
{
  mocap_optitrack_interfaces__msg__ConfigurationArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mocap_optitrack_interfaces__msg__ConfigurationArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION_ARRAY__STRUCT_H_
