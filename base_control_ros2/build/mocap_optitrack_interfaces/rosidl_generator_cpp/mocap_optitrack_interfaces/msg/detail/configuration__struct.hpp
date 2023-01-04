// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mocap_optitrack_interfaces:msg/Configuration.idl
// generated code does not contain a copyright notice

#ifndef MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION__STRUCT_HPP_
#define MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mocap_optitrack_interfaces__msg__Configuration __attribute__((deprecated))
#else
# define DEPRECATED__mocap_optitrack_interfaces__msg__Configuration __declspec(deprecated)
#endif

namespace mocap_optitrack_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Configuration_
{
  using Type = Configuration_<ContainerAllocator>;

  explicit Configuration_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->delta_x = 0.0;
      this->delta_y = 0.0;
      this->delta_l = 0.0;
    }
  }

  explicit Configuration_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->delta_x = 0.0;
      this->delta_y = 0.0;
      this->delta_l = 0.0;
    }
  }

  // field types and members
  using _delta_x_type =
    double;
  _delta_x_type delta_x;
  using _delta_y_type =
    double;
  _delta_y_type delta_y;
  using _delta_l_type =
    double;
  _delta_l_type delta_l;

  // setters for named parameter idiom
  Type & set__delta_x(
    const double & _arg)
  {
    this->delta_x = _arg;
    return *this;
  }
  Type & set__delta_y(
    const double & _arg)
  {
    this->delta_y = _arg;
    return *this;
  }
  Type & set__delta_l(
    const double & _arg)
  {
    this->delta_l = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mocap_optitrack_interfaces::msg::Configuration_<ContainerAllocator> *;
  using ConstRawPtr =
    const mocap_optitrack_interfaces::msg::Configuration_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mocap_optitrack_interfaces::msg::Configuration_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mocap_optitrack_interfaces::msg::Configuration_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mocap_optitrack_interfaces::msg::Configuration_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mocap_optitrack_interfaces::msg::Configuration_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mocap_optitrack_interfaces::msg::Configuration_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mocap_optitrack_interfaces::msg::Configuration_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mocap_optitrack_interfaces::msg::Configuration_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mocap_optitrack_interfaces::msg::Configuration_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mocap_optitrack_interfaces__msg__Configuration
    std::shared_ptr<mocap_optitrack_interfaces::msg::Configuration_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mocap_optitrack_interfaces__msg__Configuration
    std::shared_ptr<mocap_optitrack_interfaces::msg::Configuration_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Configuration_ & other) const
  {
    if (this->delta_x != other.delta_x) {
      return false;
    }
    if (this->delta_y != other.delta_y) {
      return false;
    }
    if (this->delta_l != other.delta_l) {
      return false;
    }
    return true;
  }
  bool operator!=(const Configuration_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Configuration_

// alias to use template instance with default allocator
using Configuration =
  mocap_optitrack_interfaces::msg::Configuration_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mocap_optitrack_interfaces

#endif  // MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__CONFIGURATION__STRUCT_HPP_
