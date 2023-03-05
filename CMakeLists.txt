cmake_minimum_required(VERSION 3.16)

project(matching)

#set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(./modules/dijkstra)

set(${PROJECT_NAME}_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
        )

add_executable(match ${${PROJECT_NAME}_SOURCES})

set_property(TARGET match PROPERTY CXX_STANDARD 11)

target_include_directories(match PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
