// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mocap_optitrack_interfaces:msg/ConfigurationArray.idl
// generated code does not contain a copyright notice

#ifndef MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION_ARRAY__TRAITS_HPP_
#define MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mocap_optitrack_interfaces/msg/detail/configuration_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'configurations'
#include "mocap_optitrack_interfaces/msg/detail/configuration__traits.hpp"

namespace mocap_optitrack_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ConfigurationArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: configurations
  {
    if (msg.configurations.size() == 0) {
      out << "configurations: []";
    } else {
      out << "configurations: [";
      size_t pending_items = msg.configurations.size();
      for (auto item : msg.configurations) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ConfigurationArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: configurations
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.configurations.size() == 0) {
      out << "configurations: []\n";
    } else {
      out << "configurations:\n";
      for (auto item : msg.configurations) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ConfigurationArray & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace mocap_optitrack_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mocap_optitrack_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mocap_optitrack_interfaces::msg::ConfigurationArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  mocap_optitrack_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mocap_optitrack_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const mocap_optitrack_interfaces::msg::ConfigurationArray & msg)
{
  return mocap_optitrack_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mocap_optitrack_interfaces::msg::ConfigurationArray>()
{
  return "mocap_optitrack_interfaces::msg::ConfigurationArray";
}

template<>
inline const char * name<mocap_optitrack_interfaces::msg::ConfigurationArray>()
{
  return "mocap_optitrack_interfaces/msg/ConfigurationArray";
}

template<>
struct has_fixed_size<mocap_optitrack_interfaces::msg::ConfigurationArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mocap_optitrack_interfaces::msg::ConfigurationArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<mocap_optitrack_interfaces::msg::ConfigurationArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION_ARRAY__TRAITS_HPP_
