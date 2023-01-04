# generated from rosidl_generator_py/resource/_idl.py.em
# with input from mocap_optitrack_interfaces:msg/Configuration.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Configuration(type):
    """Metaclass of message 'Configuration'."""

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
                'mocap_optitrack_interfaces.msg.Configuration')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__configuration
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__configuration
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__configuration
            cls._TYPE_SUPPORT = module.type_support_msg__msg__configuration
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__configuration

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Configuration(metaclass=Metaclass_Configuration):
    """Message class 'Configuration'."""

    __slots__ = [
        '_delta_x',
        '_delta_y',
        '_delta_l',
    ]

    _fields_and_field_types = {
        'delta_x': 'double',
        'delta_y': 'double',
        'delta_l': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.delta_x = kwargs.get('delta_x', float())
        self.delta_y = kwargs.get('delta_y', float())
        self.delta_l = kwargs.get('delta_l', float())

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
        if self.delta_x != other.delta_x:
            return False
        if self.delta_y != other.delta_y:
            return False
        if self.delta_l != other.delta_l:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def delta_x(self):
        """Message field 'delta_x'."""
        return self._delta_x

    @delta_x.setter
    def delta_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'delta_x' field must be of type 'float'"
            assert value >= -1.7976931348623157e+308 and value <= 1.7976931348623157e+308, \
                "The 'delta_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._delta_x = value

    @builtins.property
    def delta_y(self):
        """Message field 'delta_y'."""
        return self._delta_y

    @delta_y.setter
    def delta_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'delta_y' field must be of type 'float'"
            assert value >= -1.7976931348623157e+308 and value <= 1.7976931348623157e+308, \
                "The 'delta_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._delta_y = value

    @builtins.property
    def delta_l(self):
        """Message field 'delta_l'."""
        return self._delta_l

    @delta_l.setter
    def delta_l(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'delta_l' field must be of type 'float'"
            assert value >= -1.7976931348623157e+308 and value <= 1.7976931348623157e+308, \
                "The 'delta_l' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._delta_l = value
