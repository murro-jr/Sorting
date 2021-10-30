cmake_minimum_required (VERSION 2.8.11)
project (Sorting)

add_subdirectory (linkedlist)
add_subdirectory (profiling)

add_executable (sorting main.cpp)
target_link_libraries (sorting PUBLIC linkedlist profiling)
