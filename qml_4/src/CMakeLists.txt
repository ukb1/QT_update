file(GLOB_RECURSE SRC ./*.cpp)

add_library( source STATIC
    ${SRC}
)

target_link_libraries(source   ${PROJECT_NAME} mylibs)
target_include_directories(source PUBLIC ${PROJECT_SOURCE_DIR}/inc)
