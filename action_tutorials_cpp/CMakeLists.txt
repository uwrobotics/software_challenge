cmake_minimum_required(VERSION 3.5)
project(action_tutorials_cpp)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(action_tutorials_interfaces REQUIRED)
find_package(motion_interfaces REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(turtlesim REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp_components REQUIRED)

include_directories(include)

add_library(action_tutorials SHARED
  src/waypoint_action_server.cpp)

rclcpp_components_register_node(action_tutorials PLUGIN "action_tutorials_cpp::WaypointActionServer" EXECUTABLE waypoint_action_server)
target_compile_definitions(action_tutorials
  PRIVATE "ACTION_TUTORIALS_CPP_BUILDING_DLL")
ament_target_dependencies(action_tutorials
  "action_tutorials_interfaces"
  "rclcpp"
  "rclcpp_action"
  "motion_interfaces"
  "rclcpp_components"
  "turtlesim"
  "geometry_msgs")

install(TARGETS
  action_tutorials
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()