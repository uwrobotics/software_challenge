// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from challenge_package:msg/Names.idl
// generated code does not contain a copyright notice

#ifndef CHALLENGE_PACKAGE__MSG__DETAIL__NAMES__BUILDER_HPP_
#define CHALLENGE_PACKAGE__MSG__DETAIL__NAMES__BUILDER_HPP_

#include "challenge_package/msg/detail/names__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace challenge_package
{

namespace msg
{

namespace builder
{

class Init_Names_names
{
public:
  Init_Names_names()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::challenge_package::msg::Names names(::challenge_package::msg::Names::_names_type arg)
  {
    msg_.names = std::move(arg);
    return std::move(msg_);
  }

private:
  ::challenge_package::msg::Names msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::challenge_package::msg::Names>()
{
  return challenge_package::msg::builder::Init_Names_names();
}

}  // namespace challenge_package

#endif  // CHALLENGE_PACKAGE__MSG__DETAIL__NAMES__BUILDER_HPP_
