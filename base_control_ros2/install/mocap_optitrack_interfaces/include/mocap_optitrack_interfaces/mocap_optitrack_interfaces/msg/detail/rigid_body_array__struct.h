// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mocap_optitrack_interfaces:msg/RigidBodyArray.idl
// generated code does not contain a copyright notice

#ifndef MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__RIGID_BODY_ARRAY__STRUCT_H_
#define MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__RIGID_BODY_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'rigid_bodies'
#include "mocap_optitrack_interfaces/msg/detail/rigid_body__struct.h"

/// Struct defined in msg/RigidBodyArray in the package mocap_optitrack_interfaces.
/**
  * Array of rigid bodies
 */
typedef struct mocap_optitrack_interfaces__msg__RigidBodyArray
{
  mocap_optitrack_interfaces__msg__RigidBody__Sequence rigid_bodies;
} mocap_optitrack_interfaces__msg__RigidBodyArray;

// Struct for a sequence of mocap_optitrack_interfaces__msg__RigidBodyArray.
typedef struct mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence
{
  mocap_optitrack_interfaces__msg__RigidBodyArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__RIGID_BODY_ARRAY__STRUCT_H_
