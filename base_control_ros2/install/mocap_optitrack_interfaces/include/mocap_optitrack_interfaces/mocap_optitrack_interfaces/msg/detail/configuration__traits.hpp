// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mocap_optitrack_interfaces:msg/Configuration.idl
// generated code does not contain a copyright notice

#ifndef MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION__TRAITS_HPP_
#define MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mocap_optitrack_interfaces/msg/detail/configuration__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mocap_optitrack_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Configuration & msg,
  std::ostream & out)
{
  out << "{";
  // member: delta_x
  {
    out << "delta_x: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_x, out);
    out << ", ";
  }

  // member: delta_y
  {
    out << "delta_y: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_y, out);
    out << ", ";
  }

  // member: delta_l
  {
    out << "delta_l: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_l, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Configuration & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: delta_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "delta_x: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_x, out);
    out << "\n";
  }

  // member: delta_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "delta_y: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_y, out);
    out << "\n";
  }

  // member: delta_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "delta_l: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_l, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Configuration & msg, bool use_flow_style = false)
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
  const mocap_optitrack_interfaces::msg::Configuration & msg,
  std::ostream & out, size_t indentation = 0)
{
  mocap_optitrack_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mocap_optitrack_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const mocap_optitrack_interfaces::msg::Configuration & msg)
{
  return mocap_optitrack_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mocap_optitrack_interfaces::msg::Configuration>()
{
  return "mocap_optitrack_interfaces::msg::Configuration";
}

template<>
inline const char * name<mocap_optitrack_interfaces::msg::Configuration>()
{
  return "mocap_optitrack_interfaces/msg/Configuration";
}

template<>
struct has_fixed_size<mocap_optitrack_interfaces::msg::Configuration>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mocap_optitrack_interfaces::msg::Configuration>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mocap_optitrack_interfaces::msg::Configuration>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION__TRAITS_HPP_
