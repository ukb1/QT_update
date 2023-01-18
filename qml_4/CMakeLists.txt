cmake_minimum_required(VERSION 3.10)

project(joy_ros)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_DIR}/inc)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)


set(EXE_FILE
    main.cpp
    qml.qrc
)

add_subdirectory(inc)
add_subdirectory(src)
add_subdirectory(ros)


add_executable(${PROJECT_NAME}  ${EXE_FILE})
target_link_libraries(${PROJECT_NAME}     
            Qt${QT_VERSION_MAJOR}::Core 
            Qt${QT_VERSION_MAJOR}::Quick 
            source mylibs ros_node
            )



