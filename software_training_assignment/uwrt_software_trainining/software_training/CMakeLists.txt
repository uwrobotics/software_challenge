cmake_minimum_required(VERSION 3.5)
project(software_training)

# default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# default to C++ 14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(turtlesim REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rcutils REQUIRED)
find_package(rcl REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)

include_directories(include)

rosidl_generate_interfaces(${PROJECT_NAME}
	"msg/Software.msg"
	"srv/Software.srv"
	"action/Software.action"
	DEPENDENCIES std_msgs geometry_msgs builtin_interfaces
)
ament_export_dependencies(rosidl_default_runtime)

set(node_plugins "")

add_library(turtle_request SHARED src/turtle_neutralize.cpp)
target_compile_definitions(turtle_request PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(turtle_request "rclcpp" "rclcpp_components" "turtlesim" "std_msgs")
rclcpp_components_register_nodes(turtle_request "composition::turtle_service_request_node")
set(node_plugins "${node_plugins}composition::turtle_service_request_node;\\$<TARGET_FILE:turtle_request>\n")

add_library(turtle_spawn SHARED src/spawn_turtle_nodelet.cpp)
target_compile_definitions(turtle_spawn PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(turtle_spawn "rclcpp" "rclcpp_components" "turtlesim" "std_msgs")
rclcpp_components_register_nodes(turtle_spawn "composition::spawn_turtle_nodelet")
set(node_plugins "${node_plugins}composition::spawn_turtle_nodelet;\\$<TARGET_FILE:turtle_spawn>\n")

add_library(turtle_pub SHARED src/turtle_publisher.cpp)
target_compile_definitions(turtle_pub PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(turtle_pub "rclcpp" "rclcpp_components" "turtlesim" "std_msgs")
rosidl_target_interfaces(turtle_pub ${PROJECT_NAME} "rosidl_typesupport_cpp")
rclcpp_components_register_nodes(turtle_pub "composition::turtle_publisher")
set(node_plugins "${node_plugins}composition::turtle_publisher;\\$<TARGET_FILE:turtle_pub>\n")

add_library(turtle_service SHARED src/reset_moving_turtle_service.cpp)
target_compile_definitions(turtle_service PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(turtle_service "rclcpp" "rclcpp_components" "turtlesim" "std_msgs")
rosidl_target_interfaces(turtle_service ${PROJECT_NAME} "rosidl_typesupport_cpp") 
rclcpp_components_register_nodes(turtle_service "composition::reset_moving_turtle_service")
set(node_plugins "${node_plugins}composition::reset_moving_turtle_service;\\$<TARGET_FILE:turtle_service>\n")

add_library(cmd_vel_publisher SHARED src/cmd_vel_moving_turt_publisher.cpp)
target_compile_definitions(cmd_vel_publisher PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(cmd_vel_publisher "rclcpp" "rclcpp_components" "turtlesim" "geometry_msgs" "std_msgs")
rclcpp_components_register_nodes(cmd_vel_publisher "composition::cmd_vel_moving_turt_publisher")
set(node_plugins "${node_plugins}composition::cmd_vel_moving_turt_publisher;\\$<TARGET_FILE:cmd_vel_publisher>\n")

add_library(turtle_action_server SHARED src/moving_turtle_action_server.cpp)
target_compile_definitions(turtle_action_server PRIVATE "SOFTWARE_TRAINING_DLL")
ament_target_dependencies(turtle_action_server "rclcpp" "rclcpp_components" "turtlesim" "rclcpp_action" "std_msgs" "geometry_msgs")
rosidl_target_interfaces(turtle_action_server ${PROJECT_NAME} "rosidl_typesupport_cpp")
rclcpp_components_register_node(turtle_action_server PLUGIN "composition::moving_turtle_action_server" EXECUTABLE moving_action_server)

install(TARGETS
	turtle_request
	turtle_spawn
	turtle_pub
	turtle_service
	turtle_action_server
	cmd_vel_publisher
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib 
	RUNTIME DESTINATION bin)

install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})

ament_package()