cmake_minimum_required(VERSION 3.0.2)
project(software_training_assignment)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
	roscpp
	rospy
	turtlesim
	std_msgs
	message_generation
	actionlib
	actionlib_msgs
)

################################################
## Declare ROS messages, services and actions ##
################################################

## Generate messages in the 'msg' folder
add_message_files(
  FILES
  Distance.msg
)

## Generate services in the 'srv' folder
add_service_files(
  FILES
  ResetMovingTurtle.srv
)

## Generate actions in the 'action' folder
add_action_files(
  FILES
  MoveTurtle.action
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
  actionlib_msgs
)

###################################
## catkin specific configuration ##
###################################

catkin_package(
	# INCLUDE_DIRS include
	# LIBRARIES software_training_assignment
	CATKIN_DEPENDS message_runtime actionlib_msgs
	# DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
include_directories(
    include
    /src
    ${catkin_INCLUDE_DIRS}
)

set(SOURCE_FILES
  src/main.cpp
  src/Turtle.cpp
  src/StationaryTurtle.cpp
  src/MovingTurtle.cpp
  src/DistancePublisher.cpp
)

add_executable(my_turtle ${SOURCE_FILES})
target_link_libraries(my_turtle ${catkin_LIBRARIES})
add_dependencies(my_turtle software_training_assignment_generate_messages_cpp)

add_executable(MoveTurtleActionTester src/MoveTurtleActionTester.cpp)
target_link_libraries(MoveTurtleActionTester ${catkin_LIBRARIES})
add_dependencies(MoveTurtleActionTester software_training_assignment_generate_messages_cpp)
