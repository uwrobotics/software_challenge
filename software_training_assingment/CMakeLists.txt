cmake_minimum_required(VERSION 3.5)
project(software_training_assingment)

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
find_package(rclcpp_action REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(turtlesim REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
#find_package(software_training_assingment REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Distance.msg"
  "srv/ResetTurtle.srv"
  "action/Wayward.action"
  
 )

add_executable(client src/clear_turtles.cpp)
ament_target_dependencies(client
  rclcpp turtlesim)
add_executable(create_turtles src/spawn_turtles.cpp)
ament_target_dependencies(create_turtles
  rclcpp turtlesim)
add_executable(reset_turtles src/reset_moving_turtle.cpp)
ament_target_dependencies(reset_turtles
  rclcpp turtlesim)
add_executable(rel_dist src/turtle_dist.cpp)
ament_target_dependencies(rel_dist 
rclcpp turtlesim)
add_executable(circ_motion src/circ_motion.cpp)
ament_target_dependencies(circ_motion 
rclcpp turtlesim geometry_msgs)


add_library(action_server SHARED
  src/wayward.cpp)
target_include_directories(action_server PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_definitions(action_server
  PRIVATE "ACTION_TUTORIALS_CPP_BUILDING_DLL")
ament_target_dependencies(action_server
  "rclcpp"
  "rclcpp_action"
  "rclcpp_components"
  "turtlesim"
  "geometry_msgs"
  )
rclcpp_components_register_node(action_server PLUGIN "software_training_assingment::WaywardActionServer" EXECUTABLE wayward)
install(TARGETS
  action_server
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)






# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
ament_export_dependencies(rosidl_default_runtime)

install(TARGETS
  client
  circ_motion
  create_turtles
  reset_turtles
  rel_dist
  DESTINATION lib/${PROJECT_NAME})
 
rosidl_target_interfaces(reset_turtles
  ${PROJECT_NAME} "rosidl_typesupport_cpp")
  
rosidl_target_interfaces(rel_dist
  ${PROJECT_NAME} "rosidl_typesupport_cpp")
rosidl_target_interfaces(action_server
  ${PROJECT_NAME} "rosidl_typesupport_cpp")
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
