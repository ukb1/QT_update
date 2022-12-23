cmake_minimum_required(VERSION 3.5)

project(Qt_13_ros_pub_sub LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(ament_cmake REQUIRED)

if(ANDROID)
  add_library(Qt_13_ros_pub_sub SHARED
    main.cpp
    window.cpp
    window.h
    window.ui
  )
else()
  add_executable(Qt_13_ros_pub_sub
    main.cpp
    window.cpp
    rosnode.cpp
    rosnode.h
    window.h
    window.ui
  )
endif()

target_link_libraries(Qt_13_ros_pub_sub  Qt5::Widgets)
ament_target_dependencies(Qt_13_ros_pub_sub rclcpp example_interfaces)
