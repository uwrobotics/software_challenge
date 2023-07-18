// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from challenge_package:msg/Names.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "challenge_package/msg/detail/names__rosidl_typesupport_introspection_c.h"
#include "challenge_package/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "challenge_package/msg/detail/names__functions.h"
#include "challenge_package/msg/detail/names__struct.h"


// Include directives for member types
// Member `names`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Names__rosidl_typesupport_introspection_c__Names_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  challenge_package__msg__Names__init(message_memory);
}

void Names__rosidl_typesupport_introspection_c__Names_fini_function(void * message_memory)
{
  challenge_package__msg__Names__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Names__rosidl_typesupport_introspection_c__Names_message_member_array[1] = {
  {
    "names",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(challenge_package__msg__Names, names),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Names__rosidl_typesupport_introspection_c__Names_message_members = {
  "challenge_package__msg",  // message namespace
  "Names",  // message name
  1,  // number of fields
  sizeof(challenge_package__msg__Names),
  Names__rosidl_typesupport_introspection_c__Names_message_member_array,  // message members
  Names__rosidl_typesupport_introspection_c__Names_init_function,  // function to initialize message memory (memory has to be allocated)
  Names__rosidl_typesupport_introspection_c__Names_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Names__rosidl_typesupport_introspection_c__Names_message_type_support_handle = {
  0,
  &Names__rosidl_typesupport_introspection_c__Names_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_challenge_package
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, challenge_package, msg, Names)() {
  if (!Names__rosidl_typesupport_introspection_c__Names_message_type_support_handle.typesupport_identifier) {
    Names__rosidl_typesupport_introspection_c__Names_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Names__rosidl_typesupport_introspection_c__Names_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
