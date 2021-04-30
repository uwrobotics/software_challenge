cmake_minimum_required(VERSION 3.5)
project(onboarding_assignment)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(motion_interfaces REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(turtlesim REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rclcpp_components REQUIRED)

add_executable(distance_publisher src/DistancePublisher.cpp)
ament_target_dependencies(distance_publisher rclcpp turtlesim motion_interfaces)

add_executable(main_node src/MainNode.cpp)
ament_target_dependencies(main_node rclcpp rclcpp_action rclcpp_components turtlesim motion_interfaces)

add_executable(server src/ResetServer.cpp)
ament_target_dependencies(server
rclcpp motion_interfaces turtlesim)

install(TARGETS
  distance_publisher
  main_node
  server 
  DESTINATION lib/${PROJECT_NAME})

ament_package()
