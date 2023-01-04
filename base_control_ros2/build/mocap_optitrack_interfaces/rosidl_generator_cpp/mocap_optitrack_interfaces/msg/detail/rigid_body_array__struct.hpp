// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mocap_optitrack_interfaces:msg/RigidBodyArray.idl
// generated code does not contain a copyright notice

#ifndef MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__RIGID_BODY_ARRAY__STRUCT_HPP_
#define MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__RIGID_BODY_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'rigid_bodies'
#include "mocap_optitrack_interfaces/msg/detail/rigid_body__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mocap_optitrack_interfaces__msg__RigidBodyArray __attribute__((deprecated))
#else
# define DEPRECATED__mocap_optitrack_interfaces__msg__RigidBodyArray __declspec(deprecated)
#endif

namespace mocap_optitrack_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RigidBodyArray_
{
  using Type = RigidBodyArray_<ContainerAllocator>;

  explicit RigidBodyArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit RigidBodyArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _rigid_bodies_type =
    std::vector<mocap_optitrack_interfaces::msg::RigidBody_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mocap_optitrack_interfaces::msg::RigidBody_<ContainerAllocator>>>;
  _rigid_bodies_type rigid_bodies;

  // setters for named parameter idiom
  Type & set__rigid_bodies(
    const std::vector<mocap_optitrack_interfaces::msg::RigidBody_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mocap_optitrack_interfaces::msg::RigidBody_<ContainerAllocator>>> & _arg)
  {
    this->rigid_bodies = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mocap_optitrack_interfaces::msg::RigidBodyArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const mocap_optitrack_interfaces::msg::RigidBodyArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mocap_optitrack_interfaces::msg::RigidBodyArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mocap_optitrack_interfaces::msg::RigidBodyArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mocap_optitrack_interfaces::msg::RigidBodyArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mocap_optitrack_interfaces::msg::RigidBodyArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mocap_optitrack_interfaces::msg::RigidBodyArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mocap_optitrack_interfaces::msg::RigidBodyArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mocap_optitrack_interfaces::msg::RigidBodyArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mocap_optitrack_interfaces::msg::RigidBodyArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mocap_optitrack_interfaces__msg__RigidBodyArray
    std::shared_ptr<mocap_optitrack_interfaces::msg::RigidBodyArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mocap_optitrack_interfaces__msg__RigidBodyArray
    std::shared_ptr<mocap_optitrack_interfaces::msg::RigidBodyArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RigidBodyArray_ & other) const
  {
    if (this->rigid_bodies != other.rigid_bodies) {
      return false;
    }
    return true;
  }
  bool operator!=(const RigidBodyArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RigidBodyArray_

// alias to use template instance with default allocator
using RigidBodyArray =
  mocap_optitrack_interfaces::msg::RigidBodyArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mocap_optitrack_interfaces

#endif  // MOCAP_OPTITRACK_INTERFACES__MSG__DETAIL__RIGID_BODY_ARRAY__STRUCT_HPP_
