// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from software_training_assingment:srv/ResetTurtle.idl
// generated code does not contain a copyright notice

#ifndef SOFTWARE_TRAINING_ASSINGMENT__SRV__DETAIL__RESET_TURTLE__STRUCT_HPP_
#define SOFTWARE_TRAINING_ASSINGMENT__SRV__DETAIL__RESET_TURTLE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__software_training_assingment__srv__ResetTurtle_Request __attribute__((deprecated))
#else
# define DEPRECATED__software_training_assingment__srv__ResetTurtle_Request __declspec(deprecated)
#endif

namespace software_training_assingment
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ResetTurtle_Request_
{
  using Type = ResetTurtle_Request_<ContainerAllocator>;

  explicit ResetTurtle_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit ResetTurtle_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    software_training_assingment::srv::ResetTurtle_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const software_training_assingment::srv::ResetTurtle_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<software_training_assingment::srv::ResetTurtle_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<software_training_assingment::srv::ResetTurtle_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      software_training_assingment::srv::ResetTurtle_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<software_training_assingment::srv::ResetTurtle_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      software_training_assingment::srv::ResetTurtle_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<software_training_assingment::srv::ResetTurtle_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<software_training_assingment::srv::ResetTurtle_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<software_training_assingment::srv::ResetTurtle_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__software_training_assingment__srv__ResetTurtle_Request
    std::shared_ptr<software_training_assingment::srv::ResetTurtle_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__software_training_assingment__srv__ResetTurtle_Request
    std::shared_ptr<software_training_assingment::srv::ResetTurtle_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ResetTurtle_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const ResetTurtle_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ResetTurtle_Request_

// alias to use template instance with default allocator
using ResetTurtle_Request =
  software_training_assingment::srv::ResetTurtle_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace software_training_assingment


#ifndef _WIN32
# define DEPRECATED__software_training_assingment__srv__ResetTurtle_Response __attribute__((deprecated))
#else
# define DEPRECATED__software_training_assingment__srv__ResetTurtle_Response __declspec(deprecated)
#endif

namespace software_training_assingment
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ResetTurtle_Response_
{
  using Type = ResetTurtle_Response_<ContainerAllocator>;

  explicit ResetTurtle_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit ResetTurtle_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    software_training_assingment::srv::ResetTurtle_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const software_training_assingment::srv::ResetTurtle_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<software_training_assingment::srv::ResetTurtle_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<software_training_assingment::srv::ResetTurtle_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      software_training_assingment::srv::ResetTurtle_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<software_training_assingment::srv::ResetTurtle_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      software_training_assingment::srv::ResetTurtle_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<software_training_assingment::srv::ResetTurtle_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<software_training_assingment::srv::ResetTurtle_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<software_training_assingment::srv::ResetTurtle_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__software_training_assingment__srv__ResetTurtle_Response
    std::shared_ptr<software_training_assingment::srv::ResetTurtle_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__software_training_assingment__srv__ResetTurtle_Response
    std::shared_ptr<software_training_assingment::srv::ResetTurtle_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ResetTurtle_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const ResetTurtle_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ResetTurtle_Response_

// alias to use template instance with default allocator
using ResetTurtle_Response =
  software_training_assingment::srv::ResetTurtle_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace software_training_assingment

namespace software_training_assingment
{

namespace srv
{

struct ResetTurtle
{
  using Request = software_training_assingment::srv::ResetTurtle_Request;
  using Response = software_training_assingment::srv::ResetTurtle_Response;
};

}  // namespace srv

}  // namespace software_training_assingment

#endif  // SOFTWARE_TRAINING_ASSINGMENT__SRV__DETAIL__RESET_TURTLE__STRUCT_HPP_
