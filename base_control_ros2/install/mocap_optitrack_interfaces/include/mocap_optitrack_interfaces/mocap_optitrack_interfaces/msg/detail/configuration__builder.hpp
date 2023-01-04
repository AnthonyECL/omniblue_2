// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mocap_optitrack_interfaces:msg/Configuration.idl
// generated code does not contain a copyright notice

#ifndef MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION__BUILDER_HPP_
#define MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mocap_optitrack_interfaces/msg/detail/configuration__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mocap_optitrack_interfaces
{

namespace msg
{

namespace builder
{

class Init_Configuration_delta_l
{
public:
  explicit Init_Configuration_delta_l(::mocap_optitrack_interfaces::msg::Configuration & msg)
  : msg_(msg)
  {}
  ::mocap_optitrack_interfaces::msg::Configuration delta_l(::mocap_optitrack_interfaces::msg::Configuration::_delta_l_type arg)
  {
    msg_.delta_l = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mocap_optitrack_interfaces::msg::Configuration msg_;
};

class Init_Configuration_delta_y
{
public:
  explicit Init_Configuration_delta_y(::mocap_optitrack_interfaces::msg::Configuration & msg)
  : msg_(msg)
  {}
  Init_Configuration_delta_l delta_y(::mocap_optitrack_interfaces::msg::Configuration::_delta_y_type arg)
  {
    msg_.delta_y = std::move(arg);
    return Init_Configuration_delta_l(msg_);
  }

private:
  ::mocap_optitrack_interfaces::msg::Configuration msg_;
};

class Init_Configuration_delta_x
{
public:
  Init_Configuration_delta_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Configuration_delta_y delta_x(::mocap_optitrack_interfaces::msg::Configuration::_delta_x_type arg)
  {
    msg_.delta_x = std::move(arg);
    return Init_Configuration_delta_y(msg_);
  }

private:
  ::mocap_optitrack_interfaces::msg::Configuration msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mocap_optitrack_interfaces::msg::Configuration>()
{
  return mocap_optitrack_interfaces::msg::builder::Init_Configuration_delta_x();
}

}  // namespace mocap_optitrack_interfaces

#endif  // MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION__BUILDER_HPP_
