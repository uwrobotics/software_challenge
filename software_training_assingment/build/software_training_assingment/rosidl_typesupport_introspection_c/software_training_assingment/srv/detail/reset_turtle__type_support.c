// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from software_training_assingment:srv/ResetTurtle.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "software_training_assingment/srv/detail/reset_turtle__rosidl_typesupport_introspection_c.h"
#include "software_training_assingment/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "software_training_assingment/srv/detail/reset_turtle__functions.h"
#include "software_training_assingment/srv/detail/reset_turtle__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ResetTurtle_Request__rosidl_typesupport_introspection_c__ResetTurtle_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  software_training_assingment__srv__ResetTurtle_Request__init(message_memory);
}

void ResetTurtle_Request__rosidl_typesupport_introspection_c__ResetTurtle_Request_fini_function(void * message_memory)
{
  software_training_assingment__srv__ResetTurtle_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ResetTurtle_Request__rosidl_typesupport_introspection_c__ResetTurtle_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(software_training_assingment__srv__ResetTurtle_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ResetTurtle_Request__rosidl_typesupport_introspection_c__ResetTurtle_Request_message_members = {
  "software_training_assingment__srv",  // message namespace
  "ResetTurtle_Request",  // message name
  1,  // number of fields
  sizeof(software_training_assingment__srv__ResetTurtle_Request),
  ResetTurtle_Request__rosidl_typesupport_introspection_c__ResetTurtle_Request_message_member_array,  // message members
  ResetTurtle_Request__rosidl_typesupport_introspection_c__ResetTurtle_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ResetTurtle_Request__rosidl_typesupport_introspection_c__ResetTurtle_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ResetTurtle_Request__rosidl_typesupport_introspection_c__ResetTurtle_Request_message_type_support_handle = {
  0,
  &ResetTurtle_Request__rosidl_typesupport_introspection_c__ResetTurtle_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_software_training_assingment
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, software_training_assingment, srv, ResetTurtle_Request)() {
  if (!ResetTurtle_Request__rosidl_typesupport_introspection_c__ResetTurtle_Request_message_type_support_handle.typesupport_identifier) {
    ResetTurtle_Request__rosidl_typesupport_introspection_c__ResetTurtle_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ResetTurtle_Request__rosidl_typesupport_introspection_c__ResetTurtle_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "software_training_assingment/srv/detail/reset_turtle__rosidl_typesupport_introspection_c.h"
// already included above
// #include "software_training_assingment/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "software_training_assingment/srv/detail/reset_turtle__functions.h"
// already included above
// #include "software_training_assingment/srv/detail/reset_turtle__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ResetTurtle_Response__rosidl_typesupport_introspection_c__ResetTurtle_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  software_training_assingment__srv__ResetTurtle_Response__init(message_memory);
}

void ResetTurtle_Response__rosidl_typesupport_introspection_c__ResetTurtle_Response_fini_function(void * message_memory)
{
  software_training_assingment__srv__ResetTurtle_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ResetTurtle_Response__rosidl_typesupport_introspection_c__ResetTurtle_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(software_training_assingment__srv__ResetTurtle_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ResetTurtle_Response__rosidl_typesupport_introspection_c__ResetTurtle_Response_message_members = {
  "software_training_assingment__srv",  // message namespace
  "ResetTurtle_Response",  // message name
  1,  // number of fields
  sizeof(software_training_assingment__srv__ResetTurtle_Response),
  ResetTurtle_Response__rosidl_typesupport_introspection_c__ResetTurtle_Response_message_member_array,  // message members
  ResetTurtle_Response__rosidl_typesupport_introspection_c__ResetTurtle_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ResetTurtle_Response__rosidl_typesupport_introspection_c__ResetTurtle_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ResetTurtle_Response__rosidl_typesupport_introspection_c__ResetTurtle_Response_message_type_support_handle = {
  0,
  &ResetTurtle_Response__rosidl_typesupport_introspection_c__ResetTurtle_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_software_training_assingment
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, software_training_assingment, srv, ResetTurtle_Response)() {
  if (!ResetTurtle_Response__rosidl_typesupport_introspection_c__ResetTurtle_Response_message_type_support_handle.typesupport_identifier) {
    ResetTurtle_Response__rosidl_typesupport_introspection_c__ResetTurtle_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ResetTurtle_Response__rosidl_typesupport_introspection_c__ResetTurtle_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "software_training_assingment/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "software_training_assingment/srv/detail/reset_turtle__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers software_training_assingment__srv__detail__reset_turtle__rosidl_typesupport_introspection_c__ResetTurtle_service_members = {
  "software_training_assingment__srv",  // service namespace
  "ResetTurtle",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // software_training_assingment__srv__detail__reset_turtle__rosidl_typesupport_introspection_c__ResetTurtle_Request_message_type_support_handle,
  NULL  // response message
  // software_training_assingment__srv__detail__reset_turtle__rosidl_typesupport_introspection_c__ResetTurtle_Response_message_type_support_handle
};

static rosidl_service_type_support_t software_training_assingment__srv__detail__reset_turtle__rosidl_typesupport_introspection_c__ResetTurtle_service_type_support_handle = {
  0,
  &software_training_assingment__srv__detail__reset_turtle__rosidl_typesupport_introspection_c__ResetTurtle_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, software_training_assingment, srv, ResetTurtle_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, software_training_assingment, srv, ResetTurtle_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_software_training_assingment
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, software_training_assingment, srv, ResetTurtle)() {
  if (!software_training_assingment__srv__detail__reset_turtle__rosidl_typesupport_introspection_c__ResetTurtle_service_type_support_handle.typesupport_identifier) {
    software_training_assingment__srv__detail__reset_turtle__rosidl_typesupport_introspection_c__ResetTurtle_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)software_training_assingment__srv__detail__reset_turtle__rosidl_typesupport_introspection_c__ResetTurtle_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, software_training_assingment, srv, ResetTurtle_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, software_training_assingment, srv, ResetTurtle_Response)()->data;
  }

  return &software_training_assingment__srv__detail__reset_turtle__rosidl_typesupport_introspection_c__ResetTurtle_service_type_support_handle;
}
