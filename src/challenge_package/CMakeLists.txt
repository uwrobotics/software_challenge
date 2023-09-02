# compiles C++ packages
cmake_minimum_required(VERSION 3.8)
project(challenge_package)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(turtlesim REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(rcutils REQUIRED)
find_package(rcl REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# need to import msg files like this (from tutorial of https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Single-Package-Define-And-Use-Interface.html)
set(msg_files "msg/Names.msg")
set(act_files "action/Move.action")

rosidl_generate_interfaces(${PROJECT_NAME}
    ${msg_files}
    ${act_files}
)

include_directories(include)
ament_export_dependencies(rosidl_default_runtime)


add_executable(clear_turtle_listener src/clear_turtles.cpp)
add_executable(circle_turtle_service src/move_circle.cpp)
add_executable(spawn_turtle_service src/spawn_turtles.cpp)
add_executable(reset_turtle_service src/reset_turtle.cpp)
add_executable(dist_publisher src/publisher_dist.cpp)
add_executable(move_action_server src/move_action_server.cpp)
add_executable(move_action_client src/move_action_client.cpp)

# bc msg folder in the same package, so you need to link them with this
rosidl_target_interfaces(clear_turtle_listener ${PROJECT_NAME} "rosidl_typesupport_cpp")
rosidl_target_interfaces(move_action_server ${PROJECT_NAME} "rosidl_typesupport_cpp")
rosidl_target_interfaces(move_action_client ${PROJECT_NAME} "rosidl_typesupport_cpp")

# check how msg files are imported here and do the same for action files



# link the dependencies of clear_turtle_listener with relevant libraries that are mentioned in the file itself
ament_target_dependencies(clear_turtle_listener rclcpp std_msgs turtlesim)
ament_target_dependencies(circle_turtle_service rclcpp std_srvs geometry_msgs)
ament_target_dependencies(spawn_turtle_service rclcpp std_srvs turtlesim)
ament_target_dependencies(reset_turtle_service rclcpp std_srvs turtlesim)
ament_target_dependencies(dist_publisher rclcpp geometry_msgs turtlesim)
ament_target_dependencies(move_action_server rclcpp rclcpp_action geometry_msgs turtlesim)
ament_target_dependencies(move_action_client rclcpp rclcpp_action geometry_msgs turtlesim)



install(TARGETS
  clear_turtle_listener
  circle_turtle_service
  spawn_turtle_service
  reset_turtle_service
  dist_publisher
  move_action_server
  move_action_client
  DESTINATION lib/${PROJECT_NAME})




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

ament_package()
