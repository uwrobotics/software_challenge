// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from software_training_assingment:srv/ResetTurtle.idl
// generated code does not contain a copyright notice

#ifndef SOFTWARE_TRAINING_ASSINGMENT__SRV__DETAIL__RESET_TURTLE__BUILDER_HPP_
#define SOFTWARE_TRAINING_ASSINGMENT__SRV__DETAIL__RESET_TURTLE__BUILDER_HPP_

#include "software_training_assingment/srv/detail/reset_turtle__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace software_training_assingment
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::software_training_assingment::srv::ResetTurtle_Request>()
{
  return ::software_training_assingment::srv::ResetTurtle_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace software_training_assingment


namespace software_training_assingment
{

namespace srv
{

namespace builder
{

class Init_ResetTurtle_Response_success
{
public:
  Init_ResetTurtle_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::software_training_assingment::srv::ResetTurtle_Response success(::software_training_assingment::srv::ResetTurtle_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::software_training_assingment::srv::ResetTurtle_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::software_training_assingment::srv::ResetTurtle_Response>()
{
  return software_training_assingment::srv::builder::Init_ResetTurtle_Response_success();
}

}  // namespace software_training_assingment

#endif  // SOFTWARE_TRAINING_ASSINGMENT__SRV__DETAIL__RESET_TURTLE__BUILDER_HPP_
