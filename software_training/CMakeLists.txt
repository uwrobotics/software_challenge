cmake_minimum_required(VERSION 3.5)
project(software_training)

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
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(turtlesim REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rcutils REQUIRED)
find_package(rosidl_default_generators REQUIRED)

include_directories(include)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/Success.srv"
  "msg/Distance.msg"
  "action/Waypoint.action"
)
ament_export_dependencies(rosidl_default_runtime)

set(node_plugins "")

# clear turtles service component
add_library(clear_turtles_server SHARED
  src/clear_turtles_server.cpp)
target_compile_definitions(clear_turtles_server
  PRIVATE "SOFTWARE_TRAINING_BUILDING_DLL")
ament_target_dependencies(clear_turtles_server
  "rclcpp"
  "rclcpp_components"
  "turtlesim"
)
rosidl_target_interfaces(clear_turtles_server ${PROJECT_NAME} "rosidl_typesupport_cpp")
rclcpp_components_register_nodes(clear_turtles_server "software_training::clear_turtles_server")
set(node_plugins "${node_plugins}software_training::clear_turtles_server;$<TARGET_FILE:clear_turtles_server>\n")

# move turtle1 in circle publisher component
add_library(move_turtle1_in_circle_publisher SHARED
  src/move_turtle1_in_circle_publisher.cpp)
target_compile_definitions(move_turtle1_in_circle_publisher
  PRIVATE "SOFTWARE_TRAINING_BUILDING_DLL")
ament_target_dependencies(move_turtle1_in_circle_publisher
  "rclcpp"
  "rclcpp_components"
  "turtlesim"
  "geometry_msgs"
)
rosidl_target_interfaces(move_turtle1_in_circle_publisher ${PROJECT_NAME} "rosidl_typesupport_cpp")
rclcpp_components_register_nodes(move_turtle1_in_circle_publisher "software_training::move_turtle1_in_circle_publisher")
set(node_plugins "${node_plugins}software_training::move_turtle1_in_circle_publisher;$<TARGET_FILE:move_turtle1_in_circle_publisher>\n")

# spawn turtles service component
add_library(spawn_turtles_server SHARED
  src/spawn_turtles_server.cpp)
target_compile_definitions(spawn_turtles_server
  PRIVATE "SOFTWARE_TRAINING_BUILDING_DLL")
ament_target_dependencies(spawn_turtles_server
  "rclcpp"
  "rclcpp_components"
  "turtlesim"
)
rosidl_target_interfaces(spawn_turtles_server ${PROJECT_NAME} "rosidl_typesupport_cpp")
rclcpp_components_register_nodes(spawn_turtles_server "software_training::spawn_turtles_server")
set(node_plugins "${node_plugins}software_training::spawn_turtles_server;$<TARGET_FILE:spawn_turtles_server>\n")

# reset moving turtle service component
add_library(reset_moving_turtle_server SHARED
  src/reset_moving_turtle_server.cpp)
target_compile_definitions(reset_moving_turtle_server
  PRIVATE "SOFTWARE_TRAINING_BUILDING_DLL")
ament_target_dependencies(reset_moving_turtle_server
  "rclcpp"
  "rclcpp_components"
  "turtlesim"
)
rosidl_target_interfaces(reset_moving_turtle_server ${PROJECT_NAME} "rosidl_typesupport_cpp")
rclcpp_components_register_nodes(reset_moving_turtle_server "software_training::reset_moving_turtle_server")
set(node_plugins "${node_plugins}software_training::reset_moving_turtle_server;$<TARGET_FILE:reset_moving_turtle_server>\n")

# turtle distance publisher component
add_library(turtle_distance_publisher SHARED
  src/turtle_distance_publisher.cpp)
target_compile_definitions(turtle_distance_publisher
  PRIVATE "SOFTWARE_TRAINING_BUILDING_DLL")
ament_target_dependencies(turtle_distance_publisher
  "rclcpp"
  "rclcpp_components"
  "turtlesim"
)
rosidl_target_interfaces(turtle_distance_publisher ${PROJECT_NAME} "rosidl_typesupport_cpp")
rclcpp_components_register_nodes(turtle_distance_publisher "software_training::turtle_distance_publisher")
set(node_plugins "${node_plugins}software_training::turtle_distance_publisher;$<TARGET_FILE:turtle_distance_publisher>\n")

# move to waypoint action service component
add_library(move_to_waypoint_action_server SHARED
  src/move_to_waypoint_action_server.cpp)
target_compile_definitions(move_to_waypoint_action_server
  PRIVATE "SOFTWARE_TRAINING_BUILDING_DLL")
ament_target_dependencies(move_to_waypoint_action_server
  "rclcpp"
  "rclcpp_components"
  "rclcpp_action"
  "turtlesim"
  "geometry_msgs"
)
rosidl_target_interfaces(move_to_waypoint_action_server ${PROJECT_NAME} "rosidl_typesupport_cpp")
rclcpp_components_register_nodes(move_to_waypoint_action_server "software_training::move_to_waypoint_action_server")
set(node_plugins "${node_plugins}software_training::move_to_waypoint_action_server;$<TARGET_FILE:move_to_waypoint_action_server>\n")

install(TARGETS
  clear_turtles_server
  move_turtle1_in_circle_publisher
  spawn_turtles_server
  reset_moving_turtle_server
  turtle_distance_publisher
  move_to_waypoint_action_server
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
