cmake_minimum_required(VERSION 3.0.2)
project(software_training_assignment)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
  turtlesim
  actionlib
  actionlib_msgs
)

find_package(Boost REQUIRED COMPONENTS system)

## Generate messages in the 'msg' folder
 add_message_files(
   FILES
   Position.msg
 )

## Generate actions in the 'action' folder
 add_action_files(
   FILES
   Goto.action
 )

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs
   actionlib_msgs
 )

catkin_package(
	 CATKIN_DEPENDS message_runtime actionlib_msgs
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)

 install(DIRECTORY include/${PROJECT_NAME}/
   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
   FILES_MATCHING PATTERN "*.h"
   PATTERN ".svn" EXCLUDE
 )




add_executable(spawnturtle src/spawnturtle.cpp)
target_link_libraries(spawnturtle ${catkin_LIBRARIES})
# add_dependencies(spawnturtle software_training_assignment_gencpp)

add_executable(testing src/testing.cpp)
target_link_libraries(testing ${catkin_LIBRARIES})
