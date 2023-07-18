// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from challenge_package:msg/Names.idl
// generated code does not contain a copyright notice

#ifndef CHALLENGE_PACKAGE__MSG__DETAIL__NAMES__FUNCTIONS_H_
#define CHALLENGE_PACKAGE__MSG__DETAIL__NAMES__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "challenge_package/msg/rosidl_generator_c__visibility_control.h"

#include "challenge_package/msg/detail/names__struct.h"

/// Initialize msg/Names message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * challenge_package__msg__Names
 * )) before or use
 * challenge_package__msg__Names__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_challenge_package
bool
challenge_package__msg__Names__init(challenge_package__msg__Names * msg);

/// Finalize msg/Names message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_challenge_package
void
challenge_package__msg__Names__fini(challenge_package__msg__Names * msg);

/// Create msg/Names message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * challenge_package__msg__Names__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_challenge_package
challenge_package__msg__Names *
challenge_package__msg__Names__create();

/// Destroy msg/Names message.
/**
 * It calls
 * challenge_package__msg__Names__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_challenge_package
void
challenge_package__msg__Names__destroy(challenge_package__msg__Names * msg);

/// Check for msg/Names message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_challenge_package
bool
challenge_package__msg__Names__are_equal(const challenge_package__msg__Names * lhs, const challenge_package__msg__Names * rhs);

/// Copy a msg/Names message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_challenge_package
bool
challenge_package__msg__Names__copy(
  const challenge_package__msg__Names * input,
  challenge_package__msg__Names * output);

/// Initialize array of msg/Names messages.
/**
 * It allocates the memory for the number of elements and calls
 * challenge_package__msg__Names__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_challenge_package
bool
challenge_package__msg__Names__Sequence__init(challenge_package__msg__Names__Sequence * array, size_t size);

/// Finalize array of msg/Names messages.
/**
 * It calls
 * challenge_package__msg__Names__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_challenge_package
void
challenge_package__msg__Names__Sequence__fini(challenge_package__msg__Names__Sequence * array);

/// Create array of msg/Names messages.
/**
 * It allocates the memory for the array and calls
 * challenge_package__msg__Names__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_challenge_package
challenge_package__msg__Names__Sequence *
challenge_package__msg__Names__Sequence__create(size_t size);

/// Destroy array of msg/Names messages.
/**
 * It calls
 * challenge_package__msg__Names__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_challenge_package
void
challenge_package__msg__Names__Sequence__destroy(challenge_package__msg__Names__Sequence * array);

/// Check for msg/Names message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_challenge_package
bool
challenge_package__msg__Names__Sequence__are_equal(const challenge_package__msg__Names__Sequence * lhs, const challenge_package__msg__Names__Sequence * rhs);

/// Copy an array of msg/Names messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_challenge_package
bool
challenge_package__msg__Names__Sequence__copy(
  const challenge_package__msg__Names__Sequence * input,
  challenge_package__msg__Names__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CHALLENGE_PACKAGE__MSG__DETAIL__NAMES__FUNCTIONS_H_
