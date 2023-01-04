// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mocap_optitrack_interfaces:msg/RigidBody.idl
// generated code does not contain a copyright notice

#ifndef MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__RIGID_BODY__TRAITS_HPP_
#define MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__RIGID_BODY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mocap_optitrack_interfaces/msg/detail/rigid_body__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose_stamped'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace mocap_optitrack_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RigidBody & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: valid
  {
    out << "valid: ";
    rosidl_generator_traits::value_to_yaml(msg.valid, out);
    out << ", ";
  }

  // member: mean_error
  {
    out << "mean_error: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_error, out);
    out << ", ";
  }

  // member: pose_stamped
  {
    out << "pose_stamped: ";
    to_flow_style_yaml(msg.pose_stamped, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RigidBody & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "valid: ";
    rosidl_generator_traits::value_to_yaml(msg.valid, out);
    out << "\n";
  }

  // member: mean_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mean_error: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_error, out);
    out << "\n";
  }

  // member: pose_stamped
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_stamped:\n";
    to_block_style_yaml(msg.pose_stamped, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RigidBody & msg, bool use_flow_style = false)
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
  const mocap_optitrack_interfaces::msg::RigidBody & msg,
  std::ostream & out, size_t indentation = 0)
{
  mocap_optitrack_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mocap_optitrack_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const mocap_optitrack_interfaces::msg::RigidBody & msg)
{
  return mocap_optitrack_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mocap_optitrack_interfaces::msg::RigidBody>()
{
  return "mocap_optitrack_interfaces::msg::RigidBody";
}

template<>
inline const char * name<mocap_optitrack_interfaces::msg::RigidBody>()
{
  return "mocap_optitrack_interfaces/msg/RigidBody";
}

template<>
struct has_fixed_size<mocap_optitrack_interfaces::msg::RigidBody>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct has_bounded_size<mocap_optitrack_interfaces::msg::RigidBody>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct is_message<mocap_optitrack_interfaces::msg::RigidBody>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__RIGID_BODY__TRAITS_HPP_
