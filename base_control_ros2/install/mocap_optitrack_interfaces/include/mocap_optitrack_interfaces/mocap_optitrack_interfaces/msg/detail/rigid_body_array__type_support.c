// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mocap_optitrack_interfaces:msg/RigidBodyArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mocap_optitrack_interfaces/msg/detail/rigid_body_array__rosidl_typesupport_introspection_c.h"
#include "mocap_optitrack_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mocap_optitrack_interfaces/msg/detail/rigid_body_array__functions.h"
#include "mocap_optitrack_interfaces/msg/detail/rigid_body_array__struct.h"


// Include directives for member types
// Member `rigid_bodies`
#include "mocap_optitrack_interfaces/msg/rigid_body.h"
// Member `rigid_bodies`
#include "mocap_optitrack_interfaces/msg/detail/rigid_body__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__RigidBodyArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mocap_optitrack_interfaces__msg__RigidBodyArray__init(message_memory);
}

void mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__RigidBodyArray_fini_function(void * message_memory)
{
  mocap_optitrack_interfaces__msg__RigidBodyArray__fini(message_memory);
}

size_t mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__size_function__RigidBodyArray__rigid_bodies(
  const void * untyped_member)
{
  const mocap_optitrack_interfaces__msg__RigidBody__Sequence * member =
    (const mocap_optitrack_interfaces__msg__RigidBody__Sequence *)(untyped_member);
  return member->size;
}

const void * mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__get_const_function__RigidBodyArray__rigid_bodies(
  const void * untyped_member, size_t index)
{
  const mocap_optitrack_interfaces__msg__RigidBody__Sequence * member =
    (const mocap_optitrack_interfaces__msg__RigidBody__Sequence *)(untyped_member);
  return &member->data[index];
}

void * mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__get_function__RigidBodyArray__rigid_bodies(
  void * untyped_member, size_t index)
{
  mocap_optitrack_interfaces__msg__RigidBody__Sequence * member =
    (mocap_optitrack_interfaces__msg__RigidBody__Sequence *)(untyped_member);
  return &member->data[index];
}

void mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__fetch_function__RigidBodyArray__rigid_bodies(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const mocap_optitrack_interfaces__msg__RigidBody * item =
    ((const mocap_optitrack_interfaces__msg__RigidBody *)
    mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__get_const_function__RigidBodyArray__rigid_bodies(untyped_member, index));
  mocap_optitrack_interfaces__msg__RigidBody * value =
    (mocap_optitrack_interfaces__msg__RigidBody *)(untyped_value);
  *value = *item;
}

void mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__assign_function__RigidBodyArray__rigid_bodies(
  void * untyped_member, size_t index, const void * untyped_value)
{
  mocap_optitrack_interfaces__msg__RigidBody * item =
    ((mocap_optitrack_interfaces__msg__RigidBody *)
    mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__get_function__RigidBodyArray__rigid_bodies(untyped_member, index));
  const mocap_optitrack_interfaces__msg__RigidBody * value =
    (const mocap_optitrack_interfaces__msg__RigidBody *)(untyped_value);
  *item = *value;
}

bool mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__resize_function__RigidBodyArray__rigid_bodies(
  void * untyped_member, size_t size)
{
  mocap_optitrack_interfaces__msg__RigidBody__Sequence * member =
    (mocap_optitrack_interfaces__msg__RigidBody__Sequence *)(untyped_member);
  mocap_optitrack_interfaces__msg__RigidBody__Sequence__fini(member);
  return mocap_optitrack_interfaces__msg__RigidBody__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__RigidBodyArray_message_member_array[1] = {
  {
    "rigid_bodies",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mocap_optitrack_interfaces__msg__RigidBodyArray, rigid_bodies),  // bytes offset in struct
    NULL,  // default value
    mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__size_function__RigidBodyArray__rigid_bodies,  // size() function pointer
    mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__get_const_function__RigidBodyArray__rigid_bodies,  // get_const(index) function pointer
    mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__get_function__RigidBodyArray__rigid_bodies,  // get(index) function pointer
    mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__fetch_function__RigidBodyArray__rigid_bodies,  // fetch(index, &value) function pointer
    mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__assign_function__RigidBodyArray__rigid_bodies,  // assign(index, value) function pointer
    mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__resize_function__RigidBodyArray__rigid_bodies  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__RigidBodyArray_message_members = {
  "mocap_optitrack_interfaces__msg",  // message namespace
  "RigidBodyArray",  // message name
  1,  // number of fields
  sizeof(mocap_optitrack_interfaces__msg__RigidBodyArray),
  mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__RigidBodyArray_message_member_array,  // message members
  mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__RigidBodyArray_init_function,  // function to initialize message memory (memory has to be allocated)
  mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__RigidBodyArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__RigidBodyArray_message_type_support_handle = {
  0,
  &mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__RigidBodyArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mocap_optitrack_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mocap_optitrack_interfaces, msg, RigidBodyArray)() {
  mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__RigidBodyArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mocap_optitrack_interfaces, msg, RigidBody)();
  if (!mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__RigidBodyArray_message_type_support_handle.typesupport_identifier) {
    mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__RigidBodyArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mocap_optitrack_interfaces__msg__RigidBodyArray__rosidl_typesupport_introspection_c__RigidBodyArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
