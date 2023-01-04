# generated from rosidl_generator_py/resource/_idl.py.em
# with input from mocap_optitrack_interfaces:msg/ConfigurationArray.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ConfigurationArray(type):
    """Metaclass of message 'ConfigurationArray'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mocap_optitrack_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mocap_optitrack_interfaces.msg.ConfigurationArray')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__configuration_array
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__configuration_array
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__configuration_array
            cls._TYPE_SUPPORT = module.type_support_msg__msg__configuration_array
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__configuration_array

            from mocap_optitrack_interfaces.msg import Configuration
            if Configuration.__class__._TYPE_SUPPORT is None:
                Configuration.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ConfigurationArray(metaclass=Metaclass_ConfigurationArray):
    """Message class 'ConfigurationArray'."""

    __slots__ = [
        '_configurations',
    ]

    _fields_and_field_types = {
        'configurations': 'sequence<mocap_optitrack_interfaces/Configuration>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['mocap_optitrack_interfaces', 'msg'], 'Configuration')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.configurations = kwargs.get('configurations', [])

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.configurations != other.configurations:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def configurations(self):
        """Message field 'configurations'."""
        return self._configurations

    @configurations.setter
    def configurations(self, value):
        if __debug__:
            from mocap_optitrack_interfaces.msg import Configuration
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Configuration) for v in value) and
                 True), \
                "The 'configurations' field must be a set or sequence and each value of type 'Configuration'"
        self._configurations = value
