// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mocap_optitrack_interfaces:msg/RigidBody.idl
// generated code does not contain a copyright notice

#ifndef MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__RIGID_BODY__BUILDER_HPP_
#define MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__RIGID_BODY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mocap_optitrack_interfaces/msg/detail/rigid_body__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mocap_optitrack_interfaces
{

namespace msg
{

namespace builder
{

class Init_RigidBody_pose_stamped
{
public:
  explicit Init_RigidBody_pose_stamped(::mocap_optitrack_interfaces::msg::RigidBody & msg)
  : msg_(msg)
  {}
  ::mocap_optitrack_interfaces::msg::RigidBody pose_stamped(::mocap_optitrack_interfaces::msg::RigidBody::_pose_stamped_type arg)
  {
    msg_.pose_stamped = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mocap_optitrack_interfaces::msg::RigidBody msg_;
};

class Init_RigidBody_mean_error
{
public:
  explicit Init_RigidBody_mean_error(::mocap_optitrack_interfaces::msg::RigidBody & msg)
  : msg_(msg)
  {}
  Init_RigidBody_pose_stamped mean_error(::mocap_optitrack_interfaces::msg::RigidBody::_mean_error_type arg)
  {
    msg_.mean_error = std::move(arg);
    return Init_RigidBody_pose_stamped(msg_);
  }

private:
  ::mocap_optitrack_interfaces::msg::RigidBody msg_;
};

class Init_RigidBody_valid
{
public:
  explicit Init_RigidBody_valid(::mocap_optitrack_interfaces::msg::RigidBody & msg)
  : msg_(msg)
  {}
  Init_RigidBody_mean_error valid(::mocap_optitrack_interfaces::msg::RigidBody::_valid_type arg)
  {
    msg_.valid = std::move(arg);
    return Init_RigidBody_mean_error(msg_);
  }

private:
  ::mocap_optitrack_interfaces::msg::RigidBody msg_;
};

class Init_RigidBody_id
{
public:
  Init_RigidBody_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RigidBody_valid id(::mocap_optitrack_interfaces::msg::RigidBody::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_RigidBody_valid(msg_);
  }

private:
  ::mocap_optitrack_interfaces::msg::RigidBody msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mocap_optitrack_interfaces::msg::RigidBody>()
{
  return mocap_optitrack_interfaces::msg::builder::Init_RigidBody_id();
}

}  // namespace mocap_optitrack_interfaces

#endif  // MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__RIGID_BODY__BUILDER_HPP_
