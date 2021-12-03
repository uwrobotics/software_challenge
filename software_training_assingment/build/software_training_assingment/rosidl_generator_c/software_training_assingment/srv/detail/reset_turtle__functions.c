// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from software_training_assingment:srv/ResetTurtle.idl
// generated code does not contain a copyright notice
#include "software_training_assingment/srv/detail/reset_turtle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool
software_training_assingment__srv__ResetTurtle_Request__init(software_training_assingment__srv__ResetTurtle_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
software_training_assingment__srv__ResetTurtle_Request__fini(software_training_assingment__srv__ResetTurtle_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

software_training_assingment__srv__ResetTurtle_Request *
software_training_assingment__srv__ResetTurtle_Request__create()
{
  software_training_assingment__srv__ResetTurtle_Request * msg = (software_training_assingment__srv__ResetTurtle_Request *)malloc(sizeof(software_training_assingment__srv__ResetTurtle_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(software_training_assingment__srv__ResetTurtle_Request));
  bool success = software_training_assingment__srv__ResetTurtle_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
software_training_assingment__srv__ResetTurtle_Request__destroy(software_training_assingment__srv__ResetTurtle_Request * msg)
{
  if (msg) {
    software_training_assingment__srv__ResetTurtle_Request__fini(msg);
  }
  free(msg);
}


bool
software_training_assingment__srv__ResetTurtle_Request__Sequence__init(software_training_assingment__srv__ResetTurtle_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  software_training_assingment__srv__ResetTurtle_Request * data = NULL;
  if (size) {
    data = (software_training_assingment__srv__ResetTurtle_Request *)calloc(size, sizeof(software_training_assingment__srv__ResetTurtle_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = software_training_assingment__srv__ResetTurtle_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        software_training_assingment__srv__ResetTurtle_Request__fini(&data[i - 1]);
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
software_training_assingment__srv__ResetTurtle_Request__Sequence__fini(software_training_assingment__srv__ResetTurtle_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      software_training_assingment__srv__ResetTurtle_Request__fini(&array->data[i]);
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

software_training_assingment__srv__ResetTurtle_Request__Sequence *
software_training_assingment__srv__ResetTurtle_Request__Sequence__create(size_t size)
{
  software_training_assingment__srv__ResetTurtle_Request__Sequence * array = (software_training_assingment__srv__ResetTurtle_Request__Sequence *)malloc(sizeof(software_training_assingment__srv__ResetTurtle_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = software_training_assingment__srv__ResetTurtle_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
software_training_assingment__srv__ResetTurtle_Request__Sequence__destroy(software_training_assingment__srv__ResetTurtle_Request__Sequence * array)
{
  if (array) {
    software_training_assingment__srv__ResetTurtle_Request__Sequence__fini(array);
  }
  free(array);
}


bool
software_training_assingment__srv__ResetTurtle_Response__init(software_training_assingment__srv__ResetTurtle_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
software_training_assingment__srv__ResetTurtle_Response__fini(software_training_assingment__srv__ResetTurtle_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

software_training_assingment__srv__ResetTurtle_Response *
software_training_assingment__srv__ResetTurtle_Response__create()
{
  software_training_assingment__srv__ResetTurtle_Response * msg = (software_training_assingment__srv__ResetTurtle_Response *)malloc(sizeof(software_training_assingment__srv__ResetTurtle_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(software_training_assingment__srv__ResetTurtle_Response));
  bool success = software_training_assingment__srv__ResetTurtle_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
software_training_assingment__srv__ResetTurtle_Response__destroy(software_training_assingment__srv__ResetTurtle_Response * msg)
{
  if (msg) {
    software_training_assingment__srv__ResetTurtle_Response__fini(msg);
  }
  free(msg);
}


bool
software_training_assingment__srv__ResetTurtle_Response__Sequence__init(software_training_assingment__srv__ResetTurtle_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  software_training_assingment__srv__ResetTurtle_Response * data = NULL;
  if (size) {
    data = (software_training_assingment__srv__ResetTurtle_Response *)calloc(size, sizeof(software_training_assingment__srv__ResetTurtle_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = software_training_assingment__srv__ResetTurtle_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        software_training_assingment__srv__ResetTurtle_Response__fini(&data[i - 1]);
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
software_training_assingment__srv__ResetTurtle_Response__Sequence__fini(software_training_assingment__srv__ResetTurtle_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      software_training_assingment__srv__ResetTurtle_Response__fini(&array->data[i]);
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

software_training_assingment__srv__ResetTurtle_Response__Sequence *
software_training_assingment__srv__ResetTurtle_Response__Sequence__create(size_t size)
{
  software_training_assingment__srv__ResetTurtle_Response__Sequence * array = (software_training_assingment__srv__ResetTurtle_Response__Sequence *)malloc(sizeof(software_training_assingment__srv__ResetTurtle_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = software_training_assingment__srv__ResetTurtle_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
software_training_assingment__srv__ResetTurtle_Response__Sequence__destroy(software_training_assingment__srv__ResetTurtle_Response__Sequence * array)
{
  if (array) {
    software_training_assingment__srv__ResetTurtle_Response__Sequence__fini(array);
  }
  free(array);
}
