// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from mocap_optitrack_interfaces:msg/ConfigurationArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "mocap_optitrack_interfaces/msg/detail/configuration_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace mocap_optitrack_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ConfigurationArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) mocap_optitrack_interfaces::msg::ConfigurationArray(_init);
}

void ConfigurationArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<mocap_optitrack_interfaces::msg::ConfigurationArray *>(message_memory);
  typed_message->~ConfigurationArray();
}

size_t size_function__ConfigurationArray__configurations(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<mocap_optitrack_interfaces::msg::Configuration> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ConfigurationArray__configurations(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<mocap_optitrack_interfaces::msg::Configuration> *>(untyped_member);
  return &member[index];
}

void * get_function__ConfigurationArray__configurations(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<mocap_optitrack_interfaces::msg::Configuration> *>(untyped_member);
  return &member[index];
}

void fetch_function__ConfigurationArray__configurations(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const mocap_optitrack_interfaces::msg::Configuration *>(
    get_const_function__ConfigurationArray__configurations(untyped_member, index));
  auto & value = *reinterpret_cast<mocap_optitrack_interfaces::msg::Configuration *>(untyped_value);
  value = item;
}

void assign_function__ConfigurationArray__configurations(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<mocap_optitrack_interfaces::msg::Configuration *>(
    get_function__ConfigurationArray__configurations(untyped_member, index));
  const auto & value = *reinterpret_cast<const mocap_optitrack_interfaces::msg::Configuration *>(untyped_value);
  item = value;
}

void resize_function__ConfigurationArray__configurations(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<mocap_optitrack_interfaces::msg::Configuration> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ConfigurationArray_message_member_array[1] = {
  {
    "configurations",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<mocap_optitrack_interfaces::msg::Configuration>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mocap_optitrack_interfaces::msg::ConfigurationArray, configurations),  // bytes offset in struct
    nullptr,  // default value
    size_function__ConfigurationArray__configurations,  // size() function pointer
    get_const_function__ConfigurationArray__configurations,  // get_const(index) function pointer
    get_function__ConfigurationArray__configurations,  // get(index) function pointer
    fetch_function__ConfigurationArray__configurations,  // fetch(index, &value) function pointer
    assign_function__ConfigurationArray__configurations,  // assign(index, value) function pointer
    resize_function__ConfigurationArray__configurations  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ConfigurationArray_message_members = {
  "mocap_optitrack_interfaces::msg",  // message namespace
  "ConfigurationArray",  // message name
  1,  // number of fields
  sizeof(mocap_optitrack_interfaces::msg::ConfigurationArray),
  ConfigurationArray_message_member_array,  // message members
  ConfigurationArray_init_function,  // function to initialize message memory (memory has to be allocated)
  ConfigurationArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ConfigurationArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ConfigurationArray_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace mocap_optitrack_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<mocap_optitrack_interfaces::msg::ConfigurationArray>()
{
  return &::mocap_optitrack_interfaces::msg::rosidl_typesupport_introspection_cpp::ConfigurationArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, mocap_optitrack_interfaces, msg, ConfigurationArray)() {
  return &::mocap_optitrack_interfaces::msg::rosidl_typesupport_introspection_cpp::ConfigurationArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
