cmake_minimum_required(VERSION 3.0.2)
project(turtlesim_editor)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  turtlesim
  std_msgs
  message_generation
  actionlib
  actionlib_msgs
)

find_package(Boost REQUIRED COMPONENTS system)

add_action_files(
  DIRECTORY action
  FILES turtlesim.action
)

add_message_files(
  FILES
  distance.msg
)

add_service_files(
  FILES
  moveback.srv
)

generate_messages(
  DEPENDENCIES
  actionlib_msgs
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime actionlib_msgs
)

add_library(turtle src/turtle.cpp)
target_link_libraries(turtle ${catkin_LIBRARIES})

include_directories(include ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

add_executable(turtlesim_clear_node src/turtlesim_clear.cpp)
target_link_libraries(turtlesim_clear_node ${catkin_LIBRARIES})
add_dependencies(turtlesim_clear_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(turtlesim_spawn_node src/turtlesim_spawn.cpp)
target_link_libraries(turtlesim_spawn_node ${catkin_LIBRARIES})
add_dependencies(turtlesim_spawn_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(turtlesim_moveback_node src/turtlesim_moveback.cpp)
target_link_libraries(turtlesim_moveback_node ${catkin_LIBRARIES})
add_dependencies(turtlesim_moveback_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(turtlesim_distance_node src/turtlesim_distance.cpp)
target_link_libraries(turtlesim_distance_node ${catkin_LIBRARIES} turtle)
add_dependencies(turtlesim_distance_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(turtlesim_move_node src/turtlesim_move.cpp)
target_link_libraries(turtlesim_move_node ${catkin_LIBRARIES} turtle)
add_dependencies(turtlesim_move_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})