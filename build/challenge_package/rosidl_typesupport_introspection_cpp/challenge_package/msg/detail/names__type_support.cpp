// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from challenge_package:msg/Names.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "challenge_package/msg/detail/names__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace challenge_package
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Names_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) challenge_package::msg::Names(_init);
}

void Names_fini_function(void * message_memory)
{
  auto typed_message = static_cast<challenge_package::msg::Names *>(message_memory);
  typed_message->~Names();
}

size_t size_function__Names__names(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Names__names(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__Names__names(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void resize_function__Names__names(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Names_message_member_array[1] = {
  {
    "names",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(challenge_package::msg::Names, names),  // bytes offset in struct
    nullptr,  // default value
    size_function__Names__names,  // size() function pointer
    get_const_function__Names__names,  // get_const(index) function pointer
    get_function__Names__names,  // get(index) function pointer
    resize_function__Names__names  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Names_message_members = {
  "challenge_package::msg",  // message namespace
  "Names",  // message name
  1,  // number of fields
  sizeof(challenge_package::msg::Names),
  Names_message_member_array,  // message members
  Names_init_function,  // function to initialize message memory (memory has to be allocated)
  Names_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Names_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Names_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace challenge_package


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<challenge_package::msg::Names>()
{
  return &::challenge_package::msg::rosidl_typesupport_introspection_cpp::Names_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, challenge_package, msg, Names)() {
  return &::challenge_package::msg::rosidl_typesupport_introspection_cpp::Names_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
