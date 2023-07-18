// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from challenge_package:msg/Names.idl
// generated code does not contain a copyright notice

#ifndef CHALLENGE_PACKAGE__MSG__DETAIL__NAMES__TRAITS_HPP_
#define CHALLENGE_PACKAGE__MSG__DETAIL__NAMES__TRAITS_HPP_

#include "challenge_package/msg/detail/names__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const challenge_package::msg::Names & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: names
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.names.size() == 0) {
      out << "names: []\n";
    } else {
      out << "names:\n";
      for (auto item : msg.names) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const challenge_package::msg::Names & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<challenge_package::msg::Names>()
{
  return "challenge_package::msg::Names";
}

template<>
inline const char * name<challenge_package::msg::Names>()
{
  return "challenge_package/msg/Names";
}

template<>
struct has_fixed_size<challenge_package::msg::Names>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<challenge_package::msg::Names>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<challenge_package::msg::Names>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CHALLENGE_PACKAGE__MSG__DETAIL__NAMES__TRAITS_HPP_
