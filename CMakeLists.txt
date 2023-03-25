cmake_minimum_required(VERSION 3.16)

project(matching)

#set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(./modules/dijkstra)

set(matching_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/graph.cpp")
add_library(matching ${matching_SOURCES})
target_include_directories(matching PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(matching PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/modules/dijkstra/include)
target_link_libraries(matching heap)

set(minPerfMatchWeight_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/minPerfMatching.cpp")
add_executable(minPerfMatchWeight ${minPerfMatchWeight_SOURCES})
set_property(TARGET minPerfMatchWeight PROPERTY CXX_STANDARD 20)
target_include_directories(minPerfMatchWeight PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(minPerfMatchWeight matching)

set(maxMatchWeight_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/maxMatching.cpp")
add_executable(maxMatchWeight ${maxMatchWeight_SOURCES})
set_property(TARGET maxMatchWeight PROPERTY CXX_STANDARD 20)
target_include_directories(maxMatchWeight PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(maxMatchWeight matching)
