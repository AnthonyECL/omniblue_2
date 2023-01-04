// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mocap_optitrack_interfaces:msg/RigidBodyArray.idl
// generated code does not contain a copyright notice
#include "mocap_optitrack_interfaces/msg/detail/rigid_body_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `rigid_bodies`
#include "mocap_optitrack_interfaces/msg/detail/rigid_body__functions.h"

bool
mocap_optitrack_interfaces__msg__RigidBodyArray__init(mocap_optitrack_interfaces__msg__RigidBodyArray * msg)
{
  if (!msg) {
    return false;
  }
  // rigid_bodies
  if (!mocap_optitrack_interfaces__msg__RigidBody__Sequence__init(&msg->rigid_bodies, 0)) {
    mocap_optitrack_interfaces__msg__RigidBodyArray__fini(msg);
    return false;
  }
  return true;
}

void
mocap_optitrack_interfaces__msg__RigidBodyArray__fini(mocap_optitrack_interfaces__msg__RigidBodyArray * msg)
{
  if (!msg) {
    return;
  }
  // rigid_bodies
  mocap_optitrack_interfaces__msg__RigidBody__Sequence__fini(&msg->rigid_bodies);
}

bool
mocap_optitrack_interfaces__msg__RigidBodyArray__are_equal(const mocap_optitrack_interfaces__msg__RigidBodyArray * lhs, const mocap_optitrack_interfaces__msg__RigidBodyArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // rigid_bodies
  if (!mocap_optitrack_interfaces__msg__RigidBody__Sequence__are_equal(
      &(lhs->rigid_bodies), &(rhs->rigid_bodies)))
  {
    return false;
  }
  return true;
}

bool
mocap_optitrack_interfaces__msg__RigidBodyArray__copy(
  const mocap_optitrack_interfaces__msg__RigidBodyArray * input,
  mocap_optitrack_interfaces__msg__RigidBodyArray * output)
{
  if (!input || !output) {
    return false;
  }
  // rigid_bodies
  if (!mocap_optitrack_interfaces__msg__RigidBody__Sequence__copy(
      &(input->rigid_bodies), &(output->rigid_bodies)))
  {
    return false;
  }
  return true;
}

mocap_optitrack_interfaces__msg__RigidBodyArray *
mocap_optitrack_interfaces__msg__RigidBodyArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mocap_optitrack_interfaces__msg__RigidBodyArray * msg = (mocap_optitrack_interfaces__msg__RigidBodyArray *)allocator.allocate(sizeof(mocap_optitrack_interfaces__msg__RigidBodyArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mocap_optitrack_interfaces__msg__RigidBodyArray));
  bool success = mocap_optitrack_interfaces__msg__RigidBodyArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mocap_optitrack_interfaces__msg__RigidBodyArray__destroy(mocap_optitrack_interfaces__msg__RigidBodyArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mocap_optitrack_interfaces__msg__RigidBodyArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence__init(mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mocap_optitrack_interfaces__msg__RigidBodyArray * data = NULL;

  if (size) {
    data = (mocap_optitrack_interfaces__msg__RigidBodyArray *)allocator.zero_allocate(size, sizeof(mocap_optitrack_interfaces__msg__RigidBodyArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mocap_optitrack_interfaces__msg__RigidBodyArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mocap_optitrack_interfaces__msg__RigidBodyArray__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence__fini(mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mocap_optitrack_interfaces__msg__RigidBodyArray__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence *
mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence * array = (mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence *)allocator.allocate(sizeof(mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence__destroy(mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence__are_equal(const mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence * lhs, const mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mocap_optitrack_interfaces__msg__RigidBodyArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence__copy(
  const mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence * input,
  mocap_optitrack_interfaces__msg__RigidBodyArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mocap_optitrack_interfaces__msg__RigidBodyArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mocap_optitrack_interfaces__msg__RigidBodyArray * data =
      (mocap_optitrack_interfaces__msg__RigidBodyArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mocap_optitrack_interfaces__msg__RigidBodyArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mocap_optitrack_interfaces__msg__RigidBodyArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mocap_optitrack_interfaces__msg__RigidBodyArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
