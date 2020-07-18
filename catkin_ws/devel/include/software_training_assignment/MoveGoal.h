// Generated by gencpp from file software_training_assignment/MoveGoal.msg
// DO NOT EDIT!


#ifndef SOFTWARE_TRAINING_ASSIGNMENT_MESSAGE_MOVEGOAL_H
#define SOFTWARE_TRAINING_ASSIGNMENT_MESSAGE_MOVEGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace software_training_assignment
{
template <class ContainerAllocator>
struct MoveGoal_
{
  typedef MoveGoal_<ContainerAllocator> Type;

  MoveGoal_()
    : absolutePos()  {
    }
  MoveGoal_(const ContainerAllocator& _alloc)
    : absolutePos(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _absolutePos_type;
  _absolutePos_type absolutePos;





  typedef boost::shared_ptr< ::software_training_assignment::MoveGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::software_training_assignment::MoveGoal_<ContainerAllocator> const> ConstPtr;

}; // struct MoveGoal_

typedef ::software_training_assignment::MoveGoal_<std::allocator<void> > MoveGoal;

typedef boost::shared_ptr< ::software_training_assignment::MoveGoal > MoveGoalPtr;
typedef boost::shared_ptr< ::software_training_assignment::MoveGoal const> MoveGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::software_training_assignment::MoveGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::software_training_assignment::MoveGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::software_training_assignment::MoveGoal_<ContainerAllocator1> & lhs, const ::software_training_assignment::MoveGoal_<ContainerAllocator2> & rhs)
{
  return lhs.absolutePos == rhs.absolutePos;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::software_training_assignment::MoveGoal_<ContainerAllocator1> & lhs, const ::software_training_assignment::MoveGoal_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace software_training_assignment

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::software_training_assignment::MoveGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::software_training_assignment::MoveGoal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::software_training_assignment::MoveGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::software_training_assignment::MoveGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::software_training_assignment::MoveGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::software_training_assignment::MoveGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::software_training_assignment::MoveGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a38e046c785f40d93c6a1dd61ea8c2b5";
  }

  static const char* value(const ::software_training_assignment::MoveGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa38e046c785f40d9ULL;
  static const uint64_t static_value2 = 0x3c6a1dd61ea8c2b5ULL;
};

template<class ContainerAllocator>
struct DataType< ::software_training_assignment::MoveGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "software_training_assignment/MoveGoal";
  }

  static const char* value(const ::software_training_assignment::MoveGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::software_training_assignment::MoveGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"#goal definition\n"
"float32[] absolutePos\n"
;
  }

  static const char* value(const ::software_training_assignment::MoveGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::software_training_assignment::MoveGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.absolutePos);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MoveGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::software_training_assignment::MoveGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::software_training_assignment::MoveGoal_<ContainerAllocator>& v)
  {
    s << indent << "absolutePos[]" << std::endl;
    for (size_t i = 0; i < v.absolutePos.size(); ++i)
    {
      s << indent << "  absolutePos[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.absolutePos[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // SOFTWARE_TRAINING_ASSIGNMENT_MESSAGE_MOVEGOAL_H
