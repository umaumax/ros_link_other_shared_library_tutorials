# ros_link_other_shared_library_tutorials

```
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  ros_shared_library_tutorials
)
```

`find_package`でパッケージを指定することで，そのパッケージで適切に，`LIBRARIES`と`INCLUDE_DIRS`が指定されてれば，下記のように明示的に指定する必要性はない

```
include_directories(
# include
# ${ros_shared_library_tutorials_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(${PROJECT_NAME}_node
# ${ros_shared_library_tutorials_LIBRARIES}
  ${catkin_LIBRARIES}
)
```

`package.xml`
```
  <build_depend>ros_shared_library_turorials</build_depend>
  <exec_depend>ros_shared_library_turorials</exec_depend>
```

----

## FYI
init gen command
```
catkin_create_pkg ros_link_other_shared_library_tutorials std_msgs roscpp
```

----

```
catkin_make install
```
を行い`rm -rf build devel`のみを行った場合に
`catkin_make`や`catkin_make clean`
を行うとエラーとなるので，`rm -rf build devel install`とすれば直る

```
-- ==> add_subdirectory(ros_link_other_shared_library_tutorials)
CMake Warning at /opt/ros/kinetic/share/catkin/cmake/catkinConfig.cmake:76 (find_package):
  Could not find a package configuration file provided by
  "ros_shared_library_tutorials" with any of the following names:

    ros_shared_library_tutorialsConfig.cmake
    ros_shared_library_tutorials-config.cmake

  Add the installation prefix of "ros_shared_library_tutorials" to
  CMAKE_PREFIX_PATH or set "ros_shared_library_tutorials_DIR" to a directory
  containing one of the above files.  If "ros_shared_library_tutorials"
  provides a separate development package or SDK, be sure it has been
  installed.
Call Stack (most recent call first):
  ros_link_other_shared_library_tutorials/CMakeLists.txt:10 (find_package)


-- Could not find the required component 'ros_shared_library_tutorials'. The following CMake error indicates that you either need to install the package with the same name or change your environment so that it can be found.
CMake Error at /opt/ros/kinetic/share/catkin/cmake/catkinConfig.cmake:83 (find_package):
  Could not find a package configuration file provided by
  "ros_shared_library_tutorials" with any of the following names:

    ros_shared_library_tutorialsConfig.cmake
    ros_shared_library_tutorials-config.cmake

  Add the installation prefix of "ros_shared_library_tutorials" to
  CMAKE_PREFIX_PATH or set "ros_shared_library_tutorials_DIR" to a directory
  containing one of the above files.  If "ros_shared_library_tutorials"
  provides a separate development package or SDK, be sure it has been
  installed.
Call Stack (most recent call first):
  ros_link_other_shared_library_tutorials/CMakeLists.txt:10 (find_package)


-- Configuring incomplete, errors occurred!
See also "~/catkin_ws/build/CMakeFiles/CMakeOutput.log".
See also "~/catkin_ws/build/CMakeFiles/CMakeError.log".
Invoking "cmake" failed
```
