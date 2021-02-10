cmake_minimum_required(VERSION 3.0.2)
project(software_training_assignment)
find_package(catkin REQUIRED
        roscpp
        std_msgs
        message_generation
        turtlesim
        actionlib_msgs
)
add_message_files(
        FILES
        distance.msg
)
add_action_files(
        DIRECTORY action
        FILES
        move_moving_turtle.action
)
add_service_files(
        FILES
        resetMoving.srv
)
generate_messages(
        DEPENDENCIES
        std_msgs
        actionlib_msgs
)
catkin_package(
        CATKIN_DEPENDS
        roscpp
        std_msgs
        turtlesim
        actionlib_msgs
)
include_directories(
        include
        ${catkin_INCLUDE_DIRS}
        ${software_training_assignment}

)
install(DIRECTORY include/${PROJECT_NAME}/
        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
        FILES_MATCHING PATTERN "*.h"
        PATTERN ".svn" EXCLUDE
)


add_executable(main_node src/main_node.cpp src/spawn_turtle.cpp)
target_link_libraries(main_node ${catkin_LIBRARIES})
add_dependencies(main_node software_training_assignment_generate_messages_cpp)

add_executable(move_turtle_action src/move_turtle_action.cpp)
target_link_libraries(move_turtle_action ${catkin_LIBRARIES})
add_dependencies(move_turtle_action software_training_assignment_generate_messages_cpp)