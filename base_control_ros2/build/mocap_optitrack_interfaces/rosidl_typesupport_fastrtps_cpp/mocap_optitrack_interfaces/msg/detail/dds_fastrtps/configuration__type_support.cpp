// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from mocap_optitrack_interfaces:msg/Configuration.idl
// generated code does not contain a copyright notice
#include "mocap_optitrack_interfaces/msg/detail/configuration__rosidl_typesupport_fastrtps_cpp.hpp"
#include "mocap_optitrack_interfaces/msg/detail/configuration__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace mocap_optitrack_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mocap_optitrack_interfaces
cdr_serialize(
  const mocap_optitrack_interfaces::msg::Configuration & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: delta_x
  cdr << ros_message.delta_x;
  // Member: delta_y
  cdr << ros_message.delta_y;
  // Member: delta_l
  cdr << ros_message.delta_l;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mocap_optitrack_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  mocap_optitrack_interfaces::msg::Configuration & ros_message)
{
  // Member: delta_x
  cdr >> ros_message.delta_x;

  // Member: delta_y
  cdr >> ros_message.delta_y;

  // Member: delta_l
  cdr >> ros_message.delta_l;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mocap_optitrack_interfaces
get_serialized_size(
  const mocap_optitrack_interfaces::msg::Configuration & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: delta_x
  {
    size_t item_size = sizeof(ros_message.delta_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: delta_y
  {
    size_t item_size = sizeof(ros_message.delta_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: delta_l
  {
    size_t item_size = sizeof(ros_message.delta_l);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mocap_optitrack_interfaces
max_serialized_size_Configuration(
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


  // Member: delta_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: delta_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: delta_l
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _Configuration__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const mocap_optitrack_interfaces::msg::Configuration *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Configuration__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<mocap_optitrack_interfaces::msg::Configuration *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Configuration__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const mocap_optitrack_interfaces::msg::Configuration *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Configuration__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Configuration(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Configuration__callbacks = {
  "mocap_optitrack_interfaces::msg",
  "Configuration",
  _Configuration__cdr_serialize,
  _Configuration__cdr_deserialize,
  _Configuration__get_serialized_size,
  _Configuration__max_serialized_size
};

static rosidl_message_type_support_t _Configuration__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Configuration__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace mocap_optitrack_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_mocap_optitrack_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<mocap_optitrack_interfaces::msg::Configuration>()
{
  return &mocap_optitrack_interfaces::msg::typesupport_fastrtps_cpp::_Configuration__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, mocap_optitrack_interfaces, msg, Configuration)() {
  return &mocap_optitrack_interfaces::msg::typesupport_fastrtps_cpp::_Configuration__handle;
}

#ifdef __cplusplus
}
#endif
