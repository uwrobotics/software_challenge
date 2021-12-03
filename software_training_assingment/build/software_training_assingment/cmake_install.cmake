# Install script for directory: /home/alikasim/dev_ws/src/software_training_assingment

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/alikasim/dev_ws/src/software_training_assingment/install/software_training_assingment")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/rosidl_interfaces" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_index/share/ament_index/resource_index/rosidl_interfaces/software_training_assingment")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/software_training_assingment" TYPE DIRECTORY FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_generator_c/software_training_assingment/" REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/environment" TYPE FILE FILES "/home/alikasim/ros2_foxy/install/ament_package/lib/python3.8/site-packages/ament_package/template/environment_hook/library_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/environment" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_environment_hooks/library_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_generator_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_generator_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_generator_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/libsoftware_training_assingment__rosidl_generator_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_generator_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_generator_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_generator_c.so"
         OLD_RPATH "/home/alikasim/ros2_foxy/install/rosidl_runtime_c/lib:/home/alikasim/ros2_foxy/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_generator_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/software_training_assingment" TYPE DIRECTORY FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_typesupport_introspection_c/software_training_assingment/" REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_introspection_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_introspection_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_introspection_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/libsoftware_training_assingment__rosidl_typesupport_introspection_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_introspection_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_introspection_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_introspection_c.so"
         OLD_RPATH "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment:/home/alikasim/ros2_foxy/install/rosidl_typesupport_introspection_c/lib:/home/alikasim/ros2_foxy/install/rosidl_runtime_c/lib:/home/alikasim/ros2_foxy/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_introspection_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/software_training_assingment" TYPE DIRECTORY FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_typesupport_fastrtps_c/software_training_assingment/" REGEX "/[^/]*\\.cpp$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_fastrtps_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_fastrtps_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_fastrtps_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/libsoftware_training_assingment__rosidl_typesupport_fastrtps_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_fastrtps_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_fastrtps_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_fastrtps_c.so"
         OLD_RPATH "/home/alikasim/ros2_foxy/install/rosidl_typesupport_fastrtps_c/lib:/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment:/home/alikasim/ros2_foxy/install/rmw/lib:/home/alikasim/ros2_foxy/install/rosidl_runtime_c/lib:/home/alikasim/ros2_foxy/install/rcutils/lib:/home/alikasim/ros2_foxy/install/rosidl_typesupport_fastrtps_cpp/lib:/home/alikasim/ros2_foxy/install/fastrtps/lib:/home/alikasim/ros2_foxy/install/fastcdr/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_fastrtps_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/software_training_assingment" TYPE DIRECTORY FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_typesupport_fastrtps_cpp/software_training_assingment/" REGEX "/[^/]*\\.cpp$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_fastrtps_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_fastrtps_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_fastrtps_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/libsoftware_training_assingment__rosidl_typesupport_fastrtps_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_fastrtps_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_fastrtps_cpp.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_fastrtps_cpp.so"
         OLD_RPATH "/home/alikasim/ros2_foxy/install/rmw/lib:/home/alikasim/ros2_foxy/install/rosidl_runtime_c/lib:/home/alikasim/ros2_foxy/install/rosidl_typesupport_fastrtps_cpp/lib:/home/alikasim/ros2_foxy/install/fastrtps/lib:/home/alikasim/ros2_foxy/install/fastcdr/lib:/home/alikasim/ros2_foxy/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_fastrtps_cpp.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/libsoftware_training_assingment__rosidl_typesupport_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_c.so"
         OLD_RPATH "/home/alikasim/ros2_foxy/install/rosidl_typesupport_c/lib:/home/alikasim/ros2_foxy/install/rosidl_runtime_c/lib:/home/alikasim/ros2_foxy/install/rcpputils/lib:/home/alikasim/ros2_foxy/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/software_training_assingment" TYPE DIRECTORY FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_generator_cpp/software_training_assingment/" REGEX "/[^/]*\\.hpp$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/software_training_assingment" TYPE DIRECTORY FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_typesupport_introspection_cpp/software_training_assingment/" REGEX "/[^/]*\\.hpp$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_introspection_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_introspection_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_introspection_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/libsoftware_training_assingment__rosidl_typesupport_introspection_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_introspection_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_introspection_cpp.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_introspection_cpp.so"
         OLD_RPATH "/home/alikasim/ros2_foxy/install/rosidl_runtime_c/lib:/home/alikasim/ros2_foxy/install/rosidl_typesupport_introspection_cpp/lib:/home/alikasim/ros2_foxy/install/rcutils/lib:/home/alikasim/ros2_foxy/install/rosidl_typesupport_introspection_c/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_introspection_cpp.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/libsoftware_training_assingment__rosidl_typesupport_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_cpp.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_cpp.so"
         OLD_RPATH "/home/alikasim/ros2_foxy/install/rosidl_typesupport_cpp/lib:/home/alikasim/ros2_foxy/install/rosidl_typesupport_c/lib:/home/alikasim/ros2_foxy/install/rosidl_runtime_c/lib:/home/alikasim/ros2_foxy/install/rcpputils/lib:/home/alikasim/ros2_foxy/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__rosidl_typesupport_cpp.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/environment" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_environment_hooks/pythonpath.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/environment" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_environment_hooks/pythonpath.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_generator_py/software_training_assingment/__init__.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(
        COMMAND
        "/usr/bin/python3" "-m" "compileall"
        "/home/alikasim/dev_ws/src/software_training_assingment/install/software_training_assingment/lib/python3.8/site-packages/software_training_assingment/__init__.py"
      )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/srv" TYPE DIRECTORY FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_generator_py/software_training_assingment/srv/" REGEX "/[^/]*\\.py$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment" TYPE SHARED_LIBRARY FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_generator_py/software_training_assingment/software_training_assingment_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so"
         OLD_RPATH "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_generator_py/software_training_assingment:/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment:/home/alikasim/ros2_foxy/install/rosidl_typesupport_c/lib:/home/alikasim/ros2_foxy/install/rmw/lib:/home/alikasim/ros2_foxy/install/rosidl_runtime_c/lib:/home/alikasim/ros2_foxy/install/rcpputils/lib:/home/alikasim/ros2_foxy/install/rcutils/lib:/home/alikasim/ros2_foxy/install/rosidl_typesupport_introspection_c/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment" TYPE SHARED_LIBRARY FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_generator_py/software_training_assingment/software_training_assingment_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so"
         OLD_RPATH "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_generator_py/software_training_assingment:/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment:/home/alikasim/ros2_foxy/install/rosidl_typesupport_c/lib:/home/alikasim/ros2_foxy/install/rmw/lib:/home/alikasim/ros2_foxy/install/rosidl_runtime_c/lib:/home/alikasim/ros2_foxy/install/rcpputils/lib:/home/alikasim/ros2_foxy/install/rosidl_typesupport_fastrtps_c/lib:/home/alikasim/ros2_foxy/install/rcutils/lib:/home/alikasim/ros2_foxy/install/rosidl_typesupport_fastrtps_cpp/lib:/home/alikasim/ros2_foxy/install/fastrtps/lib:/home/alikasim/ros2_foxy/install/fastcdr/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment" TYPE SHARED_LIBRARY FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_generator_py/software_training_assingment/software_training_assingment_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so"
         OLD_RPATH "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_generator_py/software_training_assingment:/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment:/home/alikasim/ros2_foxy/install/rosidl_typesupport_c/lib:/home/alikasim/ros2_foxy/install/rmw/lib:/home/alikasim/ros2_foxy/install/rosidl_runtime_c/lib:/home/alikasim/ros2_foxy/install/rcpputils/lib:/home/alikasim/ros2_foxy/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/software_training_assingment/software_training_assingment_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__python.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__python.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__python.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_generator_py/software_training_assingment/libsoftware_training_assingment__python.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__python.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__python.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__python.so"
         OLD_RPATH "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment:/home/alikasim/ros2_foxy/install/rosidl_typesupport_c/lib:/home/alikasim/ros2_foxy/install/rosidl_runtime_c/lib:/home/alikasim/ros2_foxy/install/rcpputils/lib:/home/alikasim/ros2_foxy/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoftware_training_assingment__python.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/srv" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_adapter/software_training_assingment/srv/ResetTurtle.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/srv" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/srv/ResetTurtle.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/srv" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_cmake/srv/ResetTurtle_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/srv" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_cmake/srv/ResetTurtle_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/software_training_assingment/client" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/software_training_assingment/client")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/software_training_assingment/client"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/software_training_assingment" TYPE EXECUTABLE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/client")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/software_training_assingment/client" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/software_training_assingment/client")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/software_training_assingment/client"
         OLD_RPATH "/home/alikasim/ros2_foxy/install/rclcpp/lib:/home/alikasim/ros2_foxy/install/turtlesim/lib:/home/alikasim/ros2_foxy/install/libstatistics_collector/lib:/home/alikasim/ros2_foxy/install/std_msgs/lib:/home/alikasim/ros2_foxy/install/rcl/lib:/home/alikasim/ros2_foxy/install/rcl_interfaces/lib:/home/alikasim/ros2_foxy/install/rmw_implementation/lib:/home/alikasim/ros2_foxy/install/rmw/lib:/home/alikasim/ros2_foxy/install/rcl_logging_spdlog/lib:/home/alikasim/ros2_foxy/install/rcl_yaml_param_parser/lib:/home/alikasim/ros2_foxy/install/libyaml_vendor/lib:/home/alikasim/ros2_foxy/install/rosgraph_msgs/lib:/home/alikasim/ros2_foxy/install/statistics_msgs/lib:/home/alikasim/ros2_foxy/install/tracetools/lib:/home/alikasim/ros2_foxy/install/action_msgs/lib:/home/alikasim/ros2_foxy/install/builtin_interfaces/lib:/home/alikasim/ros2_foxy/install/unique_identifier_msgs/lib:/home/alikasim/ros2_foxy/install/rosidl_typesupport_introspection_cpp/lib:/home/alikasim/ros2_foxy/install/rosidl_typesupport_introspection_c/lib:/home/alikasim/ros2_foxy/install/rosidl_typesupport_cpp/lib:/home/alikasim/ros2_foxy/install/rosidl_typesupport_c/lib:/home/alikasim/ros2_foxy/install/rcpputils/lib:/home/alikasim/ros2_foxy/install/rosidl_runtime_c/lib:/home/alikasim/ros2_foxy/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/software_training_assingment/client")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/software_training_assingment/create_turtles" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/software_training_assingment/create_turtles")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/software_training_assingment/create_turtles"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/software_training_assingment" TYPE EXECUTABLE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/create_turtles")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/software_training_assingment/create_turtles" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/software_training_assingment/create_turtles")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/software_training_assingment/create_turtles"
         OLD_RPATH "/home/alikasim/ros2_foxy/install/rclcpp/lib:/home/alikasim/ros2_foxy/install/turtlesim/lib:/home/alikasim/ros2_foxy/install/libstatistics_collector/lib:/home/alikasim/ros2_foxy/install/std_msgs/lib:/home/alikasim/ros2_foxy/install/rcl/lib:/home/alikasim/ros2_foxy/install/rcl_interfaces/lib:/home/alikasim/ros2_foxy/install/rmw_implementation/lib:/home/alikasim/ros2_foxy/install/rmw/lib:/home/alikasim/ros2_foxy/install/rcl_logging_spdlog/lib:/home/alikasim/ros2_foxy/install/rcl_yaml_param_parser/lib:/home/alikasim/ros2_foxy/install/libyaml_vendor/lib:/home/alikasim/ros2_foxy/install/rosgraph_msgs/lib:/home/alikasim/ros2_foxy/install/statistics_msgs/lib:/home/alikasim/ros2_foxy/install/tracetools/lib:/home/alikasim/ros2_foxy/install/action_msgs/lib:/home/alikasim/ros2_foxy/install/builtin_interfaces/lib:/home/alikasim/ros2_foxy/install/unique_identifier_msgs/lib:/home/alikasim/ros2_foxy/install/rosidl_typesupport_introspection_cpp/lib:/home/alikasim/ros2_foxy/install/rosidl_typesupport_introspection_c/lib:/home/alikasim/ros2_foxy/install/rosidl_typesupport_cpp/lib:/home/alikasim/ros2_foxy/install/rosidl_typesupport_c/lib:/home/alikasim/ros2_foxy/install/rcpputils/lib:/home/alikasim/ros2_foxy/install/rosidl_runtime_c/lib:/home/alikasim/ros2_foxy/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/software_training_assingment/create_turtles")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/software_training_assingment")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/software_training_assingment")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/environment" TYPE FILE FILES "/home/alikasim/ros2_foxy/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/environment" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/environment" TYPE FILE FILES "/home/alikasim/ros2_foxy/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/environment" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_environment_hooks/path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_environment_hooks/local_setup.bash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_environment_hooks/local_setup.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_environment_hooks/package.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_index/share/ament_index/resource_index/packages/software_training_assingment")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_generator_cExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_generator_cExport.cmake"
         "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/CMakeFiles/Export/share/software_training_assingment/cmake/software_training_assingment__rosidl_generator_cExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_generator_cExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_generator_cExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/CMakeFiles/Export/share/software_training_assingment/cmake/software_training_assingment__rosidl_generator_cExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/CMakeFiles/Export/share/software_training_assingment/cmake/software_training_assingment__rosidl_generator_cExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_introspection_cExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_introspection_cExport.cmake"
         "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/CMakeFiles/Export/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_introspection_cExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_introspection_cExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_introspection_cExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/CMakeFiles/Export/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_introspection_cExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/CMakeFiles/Export/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_introspection_cExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_cExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_cExport.cmake"
         "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/CMakeFiles/Export/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_cExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_cExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_cExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/CMakeFiles/Export/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_cExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/CMakeFiles/Export/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_cExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_generator_cppExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_generator_cppExport.cmake"
         "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/CMakeFiles/Export/share/software_training_assingment/cmake/software_training_assingment__rosidl_generator_cppExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_generator_cppExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_generator_cppExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/CMakeFiles/Export/share/software_training_assingment/cmake/software_training_assingment__rosidl_generator_cppExport.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_introspection_cppExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_introspection_cppExport.cmake"
         "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/CMakeFiles/Export/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_introspection_cppExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_introspection_cppExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_introspection_cppExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/CMakeFiles/Export/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_introspection_cppExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/CMakeFiles/Export/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_introspection_cppExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_cppExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_cppExport.cmake"
         "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/CMakeFiles/Export/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_cppExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_cppExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_cppExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/CMakeFiles/Export/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_cppExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/CMakeFiles/Export/share/software_training_assingment/cmake/software_training_assingment__rosidl_typesupport_cppExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_cmake/rosidl_cmake-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_export_dependencies/ament_cmake_export_dependencies-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_export_libraries/ament_cmake_export_libraries-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_export_targets/ament_cmake_export_targets-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_export_include_directories/ament_cmake_export_include_directories-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_cmake/rosidl_cmake_export_typesupport_targets-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/rosidl_cmake/rosidl_cmake_export_typesupport_libraries-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment/cmake" TYPE FILE FILES
    "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_core/software_training_assingmentConfig.cmake"
    "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/ament_cmake_core/software_training_assingmentConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assingment" TYPE FILE FILES "/home/alikasim/dev_ws/src/software_training_assingment/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/software_training_assingment__py/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/alikasim/dev_ws/src/software_training_assingment/build/software_training_assingment/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
