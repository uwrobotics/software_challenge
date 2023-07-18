// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from challenge_package:msg/Names.idl
// generated code does not contain a copyright notice

#ifndef CHALLENGE_PACKAGE__MSG__DETAIL__NAMES__STRUCT_H_
#define CHALLENGE_PACKAGE__MSG__DETAIL__NAMES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'names'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/Names in the package challenge_package.
typedef struct challenge_package__msg__Names
{
  rosidl_runtime_c__String__Sequence names;
} challenge_package__msg__Names;

// Struct for a sequence of challenge_package__msg__Names.
typedef struct challenge_package__msg__Names__Sequence
{
  challenge_package__msg__Names * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} challenge_package__msg__Names__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CHALLENGE_PACKAGE__MSG__DETAIL__NAMES__STRUCT_H_
