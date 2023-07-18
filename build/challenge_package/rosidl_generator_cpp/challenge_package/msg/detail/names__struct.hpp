// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from challenge_package:msg/Names.idl
// generated code does not contain a copyright notice

#ifndef CHALLENGE_PACKAGE__MSG__DETAIL__NAMES__STRUCT_HPP_
#define CHALLENGE_PACKAGE__MSG__DETAIL__NAMES__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__challenge_package__msg__Names __attribute__((deprecated))
#else
# define DEPRECATED__challenge_package__msg__Names __declspec(deprecated)
#endif

namespace challenge_package
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Names_
{
  using Type = Names_<ContainerAllocator>;

  explicit Names_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Names_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _names_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _names_type names;

  // setters for named parameter idiom
  Type & set__names(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->names = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    challenge_package::msg::Names_<ContainerAllocator> *;
  using ConstRawPtr =
    const challenge_package::msg::Names_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<challenge_package::msg::Names_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<challenge_package::msg::Names_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      challenge_package::msg::Names_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<challenge_package::msg::Names_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      challenge_package::msg::Names_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<challenge_package::msg::Names_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<challenge_package::msg::Names_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<challenge_package::msg::Names_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__challenge_package__msg__Names
    std::shared_ptr<challenge_package::msg::Names_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__challenge_package__msg__Names
    std::shared_ptr<challenge_package::msg::Names_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Names_ & other) const
  {
    if (this->names != other.names) {
      return false;
    }
    return true;
  }
  bool operator!=(const Names_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Names_

// alias to use template instance with default allocator
using Names =
  challenge_package::msg::Names_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace challenge_package

#endif  // CHALLENGE_PACKAGE__MSG__DETAIL__NAMES__STRUCT_HPP_
