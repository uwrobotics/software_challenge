cmake_minimum_required(VERSION 3.5)
project(software_training_assignment)

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

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(turtlesim REQUIRED)
find_package(geometry_msgs REQUIRED)

find_package(rclcpp_action REQUIRED)

find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)

include_directories(include)

set(node_plugins "")

# custom services and messages and actions
rosidl_generate_interfaces(${PROJECT_NAME}
	"srv/ExampleService.srv"
  "msg/Position.msg"
  "action/MoveTo.action"
	DEPENDENCIES std_msgs geometry_msgs builtin_interfaces)
ament_export_dependencies(rosidl_default_runtime)

#spawn turtles 
add_library(spawn_turtle SHARED
  src/spawn_turtle.cpp)
target_include_directories(spawn_turtle PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_definitions(spawn_turtle
  PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(spawn_turtle
  "turtlesim"
  "rclcpp"
  "rclcpp_components")
rclcpp_components_register_node(spawn_turtle PLUGIN "composition::SpawnTurtle" EXECUTABLE spawn)

#clear turtles
add_library(clear SHARED
  src/clear_turtle.cpp)
target_include_directories(clear PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_definitions(clear
  PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(clear
  "turtlesim"
  "rclcpp"
  "rclcpp_components")
rclcpp_components_register_node(clear PLUGIN "composition::ClearTurtle" EXECUTABLE clear_turtle)

#rotate turtle 1
add_library(rotate SHARED
  src/rotate_turtle1.cpp)
target_include_directories(rotate PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_definitions(rotate
  PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(rotate
  "turtlesim"
  "rclcpp"
  "rclcpp_components"
  "geometry_msgs")
rclcpp_components_register_node(rotate PLUGIN "composition::RotateTurtle" EXECUTABLE rotate_turtle)

#reset turtle service
add_library(reset SHARED
  src/reset_moving.cpp)
target_include_directories(reset PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_definitions(reset
  PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(reset
  "turtlesim"
  "rclcpp"
  "rclcpp_components")
rosidl_target_interfaces(reset ${PROJECT_NAME} "rosidl_typesupport_cpp")
rclcpp_components_register_node(reset PLUGIN "composition::ResetMoving" EXECUTABLE reset_turtle)

#stationary position publisher
add_library(pos_pub SHARED
  src/stationary_position_publisher.cpp)
target_include_directories(pos_pub PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_definitions(pos_pub
  PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(pos_pub
  "turtlesim"
  "rclcpp"
  "rclcpp_components")
rosidl_target_interfaces(pos_pub ${PROJECT_NAME} "rosidl_typesupport_cpp")
rclcpp_components_register_node(pos_pub PLUGIN "composition::StationaryPosPublisher" EXECUTABLE stationary_publisher)

#move turtle server
add_library(move_server SHARED
  src/move_turtle_server.cpp)
target_include_directories(move_server PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_definitions(move_server
  PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(move_server
  "turtlesim"
  "rclcpp"
  "rclcpp_components"
  "rclcpp_action")
rosidl_target_interfaces(move_server ${PROJECT_NAME} "rosidl_typesupport_cpp")
rclcpp_components_register_node(move_server PLUGIN "composition::MoveTurtleServer" EXECUTABLE move_turtle)


install(TARGETS
  spawn_turtle
  clear
  rotate
  reset
  pos_pub
  move_server
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin) 

# Install launch files.
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)


ament_package()




