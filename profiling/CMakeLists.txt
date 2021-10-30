set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(profiling Profiling.cpp)
target_link_libraries(profiling PUBLIC linkedlist)
