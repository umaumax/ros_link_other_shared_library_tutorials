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
target_link_libraries(${PROJECT_NAME}_node
# ${ros_shared_library_tutorials_LIBRARIES}
  ${catkin_LIBRARIES}
)


include_directories(
# include
# ${ros_shared_library_tutorials_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
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
