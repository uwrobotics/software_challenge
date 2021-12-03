// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from software_training_assingment:srv/ResetTurtle.idl
// generated code does not contain a copyright notice

#ifndef SOFTWARE_TRAINING_ASSINGMENT__SRV__DETAIL__RESET_TURTLE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define SOFTWARE_TRAINING_ASSINGMENT__SRV__DETAIL__RESET_TURTLE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "software_training_assingment/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "software_training_assingment/srv/detail/reset_turtle__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace software_training_assingment
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_software_training_assingment
cdr_serialize(
  const software_training_assingment::srv::ResetTurtle_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_software_training_assingment
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  software_training_assingment::srv::ResetTurtle_Request & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_software_training_assingment
get_serialized_size(
  const software_training_assingment::srv::ResetTurtle_Request & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_software_training_assingment
max_serialized_size_ResetTurtle_Request(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace software_training_assingment

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_software_training_assingment
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, software_training_assingment, srv, ResetTurtle_Request)();

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "software_training_assingment/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
// already included above
// #include "software_training_assingment/srv/detail/reset_turtle__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// already included above
// #include "fastcdr/Cdr.h"

namespace software_training_assingment
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_software_training_assingment
cdr_serialize(
  const software_training_assingment::srv::ResetTurtle_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_software_training_assingment
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  software_training_assingment::srv::ResetTurtle_Response & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_software_training_assingment
get_serialized_size(
  const software_training_assingment::srv::ResetTurtle_Response & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_software_training_assingment
max_serialized_size_ResetTurtle_Response(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace software_training_assingment

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_software_training_assingment
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, software_training_assingment, srv, ResetTurtle_Response)();

#ifdef __cplusplus
}
#endif

#include "rmw/types.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "software_training_assingment/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_software_training_assingment
const rosidl_service_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, software_training_assingment, srv, ResetTurtle)();

#ifdef __cplusplus
}
#endif

#endif  // SOFTWARE_TRAINING_ASSINGMENT__SRV__DETAIL__RESET_TURTLE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
