find_package(rclcpp REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(example_interfaces REQUIRED)



file(GLOB_RECURSE ROS_SRC  ./*.cpp )
file(GLOB_RECURSE ROS_LIBS ./*.h)

add_executable(ros_pac ${ROS_SRC}  ${ROS_LIBS})

target_include_directories(ros_pac PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
ament_target_dependencies(ros_pac rclcpp std_msgs example_interfaces)
