cmake_minimum_required(VERSION 3.0.2)
project(software_training)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
  actionlib_msgs
  actionlib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


## Generate messages in the 'msg' folder
 add_message_files(
   FILES
   software_training_message.msg

 )

## Generate services in the 'srv' folder
 add_service_files(
   FILES
   reset_service.srv

 )

## Generate actions in the 'action' folder
 add_action_files(
   FILES
   software_training_action.action

 )

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs
   actionlib_msgs
   #reset_service
 )




catkin_package(
  CATKIN_DEPENDS 
  roscpp 
  std_msgs
  message_runtime
  actionlib_msgs

)


add_executable(software_training_node src/software_training_node.cpp)
target_link_libraries(software_training_node ${catkin_LIBRARIES})
add_dependencies(software_training_node software_training_generate_messages_cpp)

add_executable(moving_turtle_service src/moving_turtle_service.cpp)
target_link_libraries(moving_turtle_service ${catkin_LIBRARIES})
add_dependencies(moving_turtle_service software_training_generate_messages_cpp)

add_executable(moving_turtle_action_node src/moving_turtle_action_node.cpp)
target_link_libraries(moving_turtle_action_node ${catkin_LIBRARIES})
add_dependencies(moving_turtle_action_node software_training_generate_messages_cpp)