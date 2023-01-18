cmake_minimum_required(VERSION 3.14)

project(setJoyName LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

find_library(rclcpp REQUIRED)
find_library(ament_cmake REQUIRED)
find_package(exemaple_interfaces REQUIRED)


add_executable(setJoyName
  main.cpp
)
target_link_libraries(setJoyName Qt${QT_VERSION_MAJOR}::Core)
ament_target_dependenceis(setJoyName rclcpp example_interfaces)
