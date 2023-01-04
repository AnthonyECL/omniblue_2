// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mocap_optitrack_interfaces:msg/RigidBody.idl
// generated code does not contain a copyright notice

#ifndef MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__RIGID_BODY__STRUCT_H_
#define MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__RIGID_BODY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose_stamped'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in msg/RigidBody in the package mocap_optitrack_interfaces.
/**
  * Message for a RigidBody of the NatNet server
  * Unique ID of the RigidBody, assigned by the the server
 */
typedef struct mocap_optitrack_interfaces__msg__RigidBody
{
  int64_t id;
  /// true if the rigid body was correctly tracked, false otherwise
  bool valid;
  /// mean error of the estimate
  double mean_error;
  /// Pose of the body
  geometry_msgs__msg__PoseStamped pose_stamped;
} mocap_optitrack_interfaces__msg__RigidBody;

// Struct for a sequence of mocap_optitrack_interfaces__msg__RigidBody.
typedef struct mocap_optitrack_interfaces__msg__RigidBody__Sequence
{
  mocap_optitrack_interfaces__msg__RigidBody * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mocap_optitrack_interfaces__msg__RigidBody__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__RIGID_BODY__STRUCT_H_
