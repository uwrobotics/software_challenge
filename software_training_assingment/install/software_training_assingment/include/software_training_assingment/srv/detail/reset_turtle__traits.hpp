// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from software_training_assingment:srv/ResetTurtle.idl
// generated code does not contain a copyright notice

#ifndef SOFTWARE_TRAINING_ASSINGMENT__SRV__DETAIL__RESET_TURTLE__TRAITS_HPP_
#define SOFTWARE_TRAINING_ASSINGMENT__SRV__DETAIL__RESET_TURTLE__TRAITS_HPP_

#include "software_training_assingment/srv/detail/reset_turtle__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<software_training_assingment::srv::ResetTurtle_Request>()
{
  return "software_training_assingment::srv::ResetTurtle_Request";
}

template<>
inline const char * name<software_training_assingment::srv::ResetTurtle_Request>()
{
  return "software_training_assingment/srv/ResetTurtle_Request";
}

template<>
struct has_fixed_size<software_training_assingment::srv::ResetTurtle_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<software_training_assingment::srv::ResetTurtle_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<software_training_assingment::srv::ResetTurtle_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<software_training_assingment::srv::ResetTurtle_Response>()
{
  return "software_training_assingment::srv::ResetTurtle_Response";
}

template<>
inline const char * name<software_training_assingment::srv::ResetTurtle_Response>()
{
  return "software_training_assingment/srv/ResetTurtle_Response";
}

template<>
struct has_fixed_size<software_training_assingment::srv::ResetTurtle_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<software_training_assingment::srv::ResetTurtle_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<software_training_assingment::srv::ResetTurtle_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<software_training_assingment::srv::ResetTurtle>()
{
  return "software_training_assingment::srv::ResetTurtle";
}

template<>
inline const char * name<software_training_assingment::srv::ResetTurtle>()
{
  return "software_training_assingment/srv/ResetTurtle";
}

template<>
struct has_fixed_size<software_training_assingment::srv::ResetTurtle>
  : std::integral_constant<
    bool,
    has_fixed_size<software_training_assingment::srv::ResetTurtle_Request>::value &&
    has_fixed_size<software_training_assingment::srv::ResetTurtle_Response>::value
  >
{
};

template<>
struct has_bounded_size<software_training_assingment::srv::ResetTurtle>
  : std::integral_constant<
    bool,
    has_bounded_size<software_training_assingment::srv::ResetTurtle_Request>::value &&
    has_bounded_size<software_training_assingment::srv::ResetTurtle_Response>::value
  >
{
};

template<>
struct is_service<software_training_assingment::srv::ResetTurtle>
  : std::true_type
{
};

template<>
struct is_service_request<software_training_assingment::srv::ResetTurtle_Request>
  : std::true_type
{
};

template<>
struct is_service_response<software_training_assingment::srv::ResetTurtle_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SOFTWARE_TRAINING_ASSINGMENT__SRV__DETAIL__RESET_TURTLE__TRAITS_HPP_
