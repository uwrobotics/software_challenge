// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from software_training_assingment:srv/ResetTurtle.idl
// generated code does not contain a copyright notice

#ifndef SOFTWARE_TRAINING_ASSINGMENT__SRV__DETAIL__RESET_TURTLE__STRUCT_H_
#define SOFTWARE_TRAINING_ASSINGMENT__SRV__DETAIL__RESET_TURTLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/ResetTurtle in the package software_training_assingment.
typedef struct software_training_assingment__srv__ResetTurtle_Request
{
  uint8_t structure_needs_at_least_one_member;
} software_training_assingment__srv__ResetTurtle_Request;

// Struct for a sequence of software_training_assingment__srv__ResetTurtle_Request.
typedef struct software_training_assingment__srv__ResetTurtle_Request__Sequence
{
  software_training_assingment__srv__ResetTurtle_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} software_training_assingment__srv__ResetTurtle_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/ResetTurtle in the package software_training_assingment.
typedef struct software_training_assingment__srv__ResetTurtle_Response
{
  bool success;
} software_training_assingment__srv__ResetTurtle_Response;

// Struct for a sequence of software_training_assingment__srv__ResetTurtle_Response.
typedef struct software_training_assingment__srv__ResetTurtle_Response__Sequence
{
  software_training_assingment__srv__ResetTurtle_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} software_training_assingment__srv__ResetTurtle_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SOFTWARE_TRAINING_ASSINGMENT__SRV__DETAIL__RESET_TURTLE__STRUCT_H_
