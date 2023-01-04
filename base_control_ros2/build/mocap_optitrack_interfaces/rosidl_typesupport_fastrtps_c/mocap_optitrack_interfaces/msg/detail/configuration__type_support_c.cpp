// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from mocap_optitrack_interfaces:msg/Configuration.idl
// generated code does not contain a copyright notice
#include "mocap_optitrack_interfaces/msg/detail/configuration__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "mocap_optitrack_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "mocap_optitrack_interfaces/msg/detail/configuration__struct.h"
#include "mocap_optitrack_interfaces/msg/detail/configuration__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Configuration__ros_msg_type = mocap_optitrack_interfaces__msg__Configuration;

static bool _Configuration__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Configuration__ros_msg_type * ros_message = static_cast<const _Configuration__ros_msg_type *>(untyped_ros_message);
  // Field name: delta_x
  {
    cdr << ros_message->delta_x;
  }

  // Field name: delta_y
  {
    cdr << ros_message->delta_y;
  }

  // Field name: delta_l
  {
    cdr << ros_message->delta_l;
  }

  return true;
}

static bool _Configuration__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Configuration__ros_msg_type * ros_message = static_cast<_Configuration__ros_msg_type *>(untyped_ros_message);
  // Field name: delta_x
  {
    cdr >> ros_message->delta_x;
  }

  // Field name: delta_y
  {
    cdr >> ros_message->delta_y;
  }

  // Field name: delta_l
  {
    cdr >> ros_message->delta_l;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mocap_optitrack_interfaces
size_t get_serialized_size_mocap_optitrack_interfaces__msg__Configuration(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Configuration__ros_msg_type * ros_message = static_cast<const _Configuration__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name delta_x
  {
    size_t item_size = sizeof(ros_message->delta_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name delta_y
  {
    size_t item_size = sizeof(ros_message->delta_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name delta_l
  {
    size_t item_size = sizeof(ros_message->delta_l);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Configuration__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_mocap_optitrack_interfaces__msg__Configuration(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mocap_optitrack_interfaces
size_t max_serialized_size_mocap_optitrack_interfaces__msg__Configuration(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: delta_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: delta_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: delta_l
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Configuration__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_mocap_optitrack_interfaces__msg__Configuration(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Configuration = {
  "mocap_optitrack_interfaces::msg",
  "Configuration",
  _Configuration__cdr_serialize,
  _Configuration__cdr_deserialize,
  _Configuration__get_serialized_size,
  _Configuration__max_serialized_size
};

static rosidl_message_type_support_t _Configuration__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Configuration,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mocap_optitrack_interfaces, msg, Configuration)() {
  return &_Configuration__type_support;
}

#if defined(__cplusplus)
}
#endif
