// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mocap_optitrack_interfaces:msg/ConfigurationArray.idl
// generated code does not contain a copyright notice

#ifndef MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION_ARRAY__BUILDER_HPP_
#define MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mocap_optitrack_interfaces/msg/detail/configuration_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mocap_optitrack_interfaces
{

namespace msg
{

namespace builder
{

class Init_ConfigurationArray_configurations
{
public:
  Init_ConfigurationArray_configurations()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mocap_optitrack_interfaces::msg::ConfigurationArray configurations(::mocap_optitrack_interfaces::msg::ConfigurationArray::_configurations_type arg)
  {
    msg_.configurations = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mocap_optitrack_interfaces::msg::ConfigurationArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mocap_optitrack_interfaces::msg::ConfigurationArray>()
{
  return mocap_optitrack_interfaces::msg::builder::Init_ConfigurationArray_configurations();
}

}  // namespace mocap_optitrack_interfaces

#endif  // MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION_ARRAY__BUILDER_HPP_
