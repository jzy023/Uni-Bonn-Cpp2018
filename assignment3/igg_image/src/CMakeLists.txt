add_subdirectory(igg_image)

add_executable(main main.cpp)

## strategies
target_link_libraries(main image)
