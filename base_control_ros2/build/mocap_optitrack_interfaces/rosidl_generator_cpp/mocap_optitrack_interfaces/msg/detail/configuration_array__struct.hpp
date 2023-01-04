// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mocap_optitrack_interfaces:msg/ConfigurationArray.idl
// generated code does not contain a copyright notice

#ifndef MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION_ARRAY__STRUCT_HPP_
#define MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'configurations'
#include "mocap_optitrack_interfaces/msg/detail/configuration__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mocap_optitrack_interfaces__msg__ConfigurationArray __attribute__((deprecated))
#else
# define DEPRECATED__mocap_optitrack_interfaces__msg__ConfigurationArray __declspec(deprecated)
#endif

namespace mocap_optitrack_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ConfigurationArray_
{
  using Type = ConfigurationArray_<ContainerAllocator>;

  explicit ConfigurationArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit ConfigurationArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _configurations_type =
    std::vector<mocap_optitrack_interfaces::msg::Configuration_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mocap_optitrack_interfaces::msg::Configuration_<ContainerAllocator>>>;
  _configurations_type configurations;

  // setters for named parameter idiom
  Type & set__configurations(
    const std::vector<mocap_optitrack_interfaces::msg::Configuration_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mocap_optitrack_interfaces::msg::Configuration_<ContainerAllocator>>> & _arg)
  {
    this->configurations = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mocap_optitrack_interfaces::msg::ConfigurationArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const mocap_optitrack_interfaces::msg::ConfigurationArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mocap_optitrack_interfaces::msg::ConfigurationArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mocap_optitrack_interfaces::msg::ConfigurationArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mocap_optitrack_interfaces::msg::ConfigurationArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mocap_optitrack_interfaces::msg::ConfigurationArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mocap_optitrack_interfaces::msg::ConfigurationArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mocap_optitrack_interfaces::msg::ConfigurationArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mocap_optitrack_interfaces::msg::ConfigurationArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mocap_optitrack_interfaces::msg::ConfigurationArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mocap_optitrack_interfaces__msg__ConfigurationArray
    std::shared_ptr<mocap_optitrack_interfaces::msg::ConfigurationArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mocap_optitrack_interfaces__msg__ConfigurationArray
    std::shared_ptr<mocap_optitrack_interfaces::msg::ConfigurationArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConfigurationArray_ & other) const
  {
    if (this->configurations != other.configurations) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConfigurationArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConfigurationArray_

// alias to use template instance with default allocator
using ConfigurationArray =
  mocap_optitrack_interfaces::msg::ConfigurationArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mocap_optitrack_interfaces

#endif  // MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION_ARRAY__STRUCT_HPP_
