// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mocap_optitrack_interfaces:msg/Configuration.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mocap_optitrack_interfaces/msg/detail/configuration__rosidl_typesupport_introspection_c.h"
#include "mocap_optitrack_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mocap_optitrack_interfaces/msg/detail/configuration__functions.h"
#include "mocap_optitrack_interfaces/msg/detail/configuration__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void mocap_optitrack_interfaces__msg__Configuration__rosidl_typesupport_introspection_c__Configuration_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mocap_optitrack_interfaces__msg__Configuration__init(message_memory);
}

void mocap_optitrack_interfaces__msg__Configuration__rosidl_typesupport_introspection_c__Configuration_fini_function(void * message_memory)
{
  mocap_optitrack_interfaces__msg__Configuration__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember mocap_optitrack_interfaces__msg__Configuration__rosidl_typesupport_introspection_c__Configuration_message_member_array[3] = {
  {
    "delta_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mocap_optitrack_interfaces__msg__Configuration, delta_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "delta_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mocap_optitrack_interfaces__msg__Configuration, delta_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "delta_l",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mocap_optitrack_interfaces__msg__Configuration, delta_l),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mocap_optitrack_interfaces__msg__Configuration__rosidl_typesupport_introspection_c__Configuration_message_members = {
  "mocap_optitrack_interfaces__msg",  // message namespace
  "Configuration",  // message name
  3,  // number of fields
  sizeof(mocap_optitrack_interfaces__msg__Configuration),
  mocap_optitrack_interfaces__msg__Configuration__rosidl_typesupport_introspection_c__Configuration_message_member_array,  // message members
  mocap_optitrack_interfaces__msg__Configuration__rosidl_typesupport_introspection_c__Configuration_init_function,  // function to initialize message memory (memory has to be allocated)
  mocap_optitrack_interfaces__msg__Configuration__rosidl_typesupport_introspection_c__Configuration_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mocap_optitrack_interfaces__msg__Configuration__rosidl_typesupport_introspection_c__Configuration_message_type_support_handle = {
  0,
  &mocap_optitrack_interfaces__msg__Configuration__rosidl_typesupport_introspection_c__Configuration_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mocap_optitrack_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mocap_optitrack_interfaces, msg, Configuration)() {
  if (!mocap_optitrack_interfaces__msg__Configuration__rosidl_typesupport_introspection_c__Configuration_message_type_support_handle.typesupport_identifier) {
    mocap_optitrack_interfaces__msg__Configuration__rosidl_typesupport_introspection_c__Configuration_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mocap_optitrack_interfaces__msg__Configuration__rosidl_typesupport_introspection_c__Configuration_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
