cmake_minimum_required(VERSION 2.8.3)
project(software_training_assignment)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp turtlesim std_msgs message_generation actionlib_msgs)

## Declare ROS messages and services
add_service_files(FILES ResetTurtle.srv)

##Declare ROS action files
##add_action_files(DIRECTORY action FILES Fibonacci.action)

## Generate added messages and services
##generate_messages(DEPENDENCIES actionlib_msgs std_msgs)
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
## catkin_package(CATKIN_DEPENDS actionlib_msgs message_runtime)
catkin_package(CATKIN_DEPENDS message_runtime)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(ResetTurtle_server src/ResetTurtle_server.cpp)
target_link_libraries(ResetTurtle_server ${catkin_LIBRARIES})
add_dependencies(ResetTurtle_server software_training_assignment_gencpp)

add_executable(TurtleMsg_pub1 src/TurtleMsg_pub1.cpp)
target_link_libraries(TurtleMsg_pub1 ${catkin_LIBRARIES})
add_dependencies(TurtleMsg_pub1 software_training_assignment_generate_messages_cpp)
