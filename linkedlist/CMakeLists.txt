set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_library(linkedlist LinkedList.cpp)
target_include_directories(linkedlist PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
