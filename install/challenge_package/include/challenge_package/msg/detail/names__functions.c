// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from challenge_package:msg/Names.idl
// generated code does not contain a copyright notice
#include "challenge_package/msg/detail/names__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `names`
#include "rosidl_runtime_c/string_functions.h"

bool
challenge_package__msg__Names__init(challenge_package__msg__Names * msg)
{
  if (!msg) {
    return false;
  }
  // names
  if (!rosidl_runtime_c__String__Sequence__init(&msg->names, 0)) {
    challenge_package__msg__Names__fini(msg);
    return false;
  }
  return true;
}

void
challenge_package__msg__Names__fini(challenge_package__msg__Names * msg)
{
  if (!msg) {
    return;
  }
  // names
  rosidl_runtime_c__String__Sequence__fini(&msg->names);
}

bool
challenge_package__msg__Names__are_equal(const challenge_package__msg__Names * lhs, const challenge_package__msg__Names * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // names
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->names), &(rhs->names)))
  {
    return false;
  }
  return true;
}

bool
challenge_package__msg__Names__copy(
  const challenge_package__msg__Names * input,
  challenge_package__msg__Names * output)
{
  if (!input || !output) {
    return false;
  }
  // names
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->names), &(output->names)))
  {
    return false;
  }
  return true;
}

challenge_package__msg__Names *
challenge_package__msg__Names__create()
{
  challenge_package__msg__Names * msg = (challenge_package__msg__Names *)malloc(sizeof(challenge_package__msg__Names));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(challenge_package__msg__Names));
  bool success = challenge_package__msg__Names__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
challenge_package__msg__Names__destroy(challenge_package__msg__Names * msg)
{
  if (msg) {
    challenge_package__msg__Names__fini(msg);
  }
  free(msg);
}


bool
challenge_package__msg__Names__Sequence__init(challenge_package__msg__Names__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  challenge_package__msg__Names * data = NULL;
  if (size) {
    data = (challenge_package__msg__Names *)calloc(size, sizeof(challenge_package__msg__Names));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = challenge_package__msg__Names__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        challenge_package__msg__Names__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
challenge_package__msg__Names__Sequence__fini(challenge_package__msg__Names__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      challenge_package__msg__Names__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

challenge_package__msg__Names__Sequence *
challenge_package__msg__Names__Sequence__create(size_t size)
{
  challenge_package__msg__Names__Sequence * array = (challenge_package__msg__Names__Sequence *)malloc(sizeof(challenge_package__msg__Names__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = challenge_package__msg__Names__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
challenge_package__msg__Names__Sequence__destroy(challenge_package__msg__Names__Sequence * array)
{
  if (array) {
    challenge_package__msg__Names__Sequence__fini(array);
  }
  free(array);
}

bool
challenge_package__msg__Names__Sequence__are_equal(const challenge_package__msg__Names__Sequence * lhs, const challenge_package__msg__Names__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!challenge_package__msg__Names__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
challenge_package__msg__Names__Sequence__copy(
  const challenge_package__msg__Names__Sequence * input,
  challenge_package__msg__Names__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(challenge_package__msg__Names);
    challenge_package__msg__Names * data =
      (challenge_package__msg__Names *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!challenge_package__msg__Names__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          challenge_package__msg__Names__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!challenge_package__msg__Names__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
