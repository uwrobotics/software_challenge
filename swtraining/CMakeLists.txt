cmake_minimum_required(VERSION 3.5)
project(swtraining)

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
find_package(geometry_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(turtlesim REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(rcutils REQUIRED)

#include the "include" directory
include_directories(include)

rosidl_generate_interfaces(${PROJECT_NAME}
  "action/Waypt.action"
  "srv/Status.srv"
  "msg/Distance.msg"
)

ament_export_dependencies(rosidl_default_runtime)
set(node_plugins "")

add_library(clearturtles SHARED src/clearturtles.cpp)
target_compile_definitions(clearturtles PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(clearturtles 
  "rclcpp"
  "rclcpp_components"
  "turtlesim"
)
rosidl_target_interfaces(clearturtles ${PROJECT_NAME} "rosidl_typesupport_cpp")
rclcpp_components_register_nodes(clearturtles "composition::clearturtles")
set(node_plugins "${node_plugins}compose::clearturtles;$<TARGET_FILE:clearturtles\n>")

add_library(drawCircle SHARED src/drawCircle.cpp)
target_compile_definitions(drawCircle PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(drawCircle 
  "rclcpp"
  "rclcpp_components"
  "turtlesim"
  "geometry_msgs"
)
rosidl_target_interfaces(drawCircle ${PROJECT_NAME} "rosidl_typesupport_cpp")
rclcpp_components_register_nodes(drawCircle "composition::drawCircle")
set(node_plugins "${node_plugins}composition::drawCircle;$<TARGET_FILE:drawCircle\n>")

add_library(resetturtle SHARED src/resetturtle.cpp)
target_compile_definitions(resetturtle PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(resetturtle
  "rclcpp"
  "rclcpp_components"
  "turtlesim"
)
rosidl_target_interfaces(resetturtle ${PROJECT_NAME} "rosidl_typesupport_cpp")
rclcpp_components_register_nodes(resetturtle "composition::resetturtle")
set(node_plugins "${node_plugins}composition::resetturtle;$<TARGET_FILE:resetturtle\n>")

add_library(spawnturtles SHARED src/spawnturtles.cpp)
target_compile_definitions(spawnturtles PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(spawnturtles 
  "rclcpp"
  "rclcpp_components"
  "turtlesim"
)
rosidl_target_interfaces(spawnturtles ${PROJECT_NAME} "rosidl_typesupport_cpp")
rclcpp_components_register_nodes(spawnturtles "composition::spawnturtles")
set(node_plugins "${node_plugins}composition::spawnturtles;$<TARGET_FILE:spawnturtles\n>")

add_library(turtledistance SHARED src/turtledistance.cpp)
target_compile_definitions(turtledistance PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(turtledistance 
  "rclcpp"
  "rclcpp_components"
  "turtlesim"
)
rosidl_target_interfaces(turtledistance ${PROJECT_NAME} "rosidl_typesupport_cpp")
rclcpp_components_register_nodes(turtledistance "composition::turtledistance")
set(node_plugins "${node_plugins}composition::turtledistance;$<TARGET_FILE:turtledistance\n>")


add_library(waypoint SHARED src/waypoint.cpp)
target_compile_definitions(waypoint PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(waypoint 
  "rclcpp"
  "rclcpp_components"
  "turtlesim"
  "rclcpp_action"
  "geometry_msgs"
)
rosidl_target_interfaces(waypoint ${PROJECT_NAME} "rosidl_typesupport_cpp")
rclcpp_components_register_nodes(waypoint "composition::waypoint")
set(node_plugins "${node_plugins}composition::waypoint;$<TARGET_FILE:waypoint\n>")



if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS 
  clearturtles
  drawCircle
  resetturtle 
  spawnturtles
  turtledistance
  waypoint
  ARCHIVE DESTINATION lib 
  LIBRARY DESTINATION lib 
  RUNTIME DESTINATION bin)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME})

ament_package()
