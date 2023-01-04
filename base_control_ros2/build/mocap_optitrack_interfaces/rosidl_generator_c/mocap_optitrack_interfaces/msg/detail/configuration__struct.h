// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mocap_optitrack_interfaces:msg/Configuration.idl
// generated code does not contain a copyright notice

#ifndef MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION__STRUCT_H_
#define MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Configuration in the package mocap_optitrack_interfaces.
/**
  * Message to send the configuration of a PCC segment
 */
typedef struct mocap_optitrack_interfaces__msg__Configuration
{
  double delta_x;
  double delta_y;
  double delta_l;
} mocap_optitrack_interfaces__msg__Configuration;

// Struct for a sequence of mocap_optitrack_interfaces__msg__Configuration.
typedef struct mocap_optitrack_interfaces__msg__Configuration__Sequence
{
  mocap_optitrack_interfaces__msg__Configuration * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mocap_optitrack_interfaces__msg__Configuration__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION__STRUCT_H_
