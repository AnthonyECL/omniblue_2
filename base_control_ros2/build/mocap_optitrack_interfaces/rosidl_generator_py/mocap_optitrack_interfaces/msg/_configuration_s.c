// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from mocap_optitrack_interfaces:msg/Configuration.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "mocap_optitrack_interfaces/msg/detail/configuration__struct.h"
#include "mocap_optitrack_interfaces/msg/detail/configuration__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool mocap_optitrack_interfaces__msg__configuration__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[60];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("mocap_optitrack_interfaces.msg._configuration.Configuration", full_classname_dest, 59) == 0);
  }
  mocap_optitrack_interfaces__msg__Configuration * ros_message = _ros_message;
  {  // delta_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "delta_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->delta_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // delta_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "delta_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->delta_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // delta_l
    PyObject * field = PyObject_GetAttrString(_pymsg, "delta_l");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->delta_l = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * mocap_optitrack_interfaces__msg__configuration__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Configuration */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("mocap_optitrack_interfaces.msg._configuration");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Configuration");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  mocap_optitrack_interfaces__msg__Configuration * ros_message = (mocap_optitrack_interfaces__msg__Configuration *)raw_ros_message;
  {  // delta_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->delta_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "delta_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // delta_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->delta_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "delta_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // delta_l
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->delta_l);
    {
      int rc = PyObject_SetAttrString(_pymessage, "delta_l", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
