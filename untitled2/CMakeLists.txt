cmake_minimum_required(VERSION 3.10)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)

set(SOURCES
        event.cpp
        functions.cpp
        GameFunction.cpp
        )
add_executable(untitled2 ${SOURCES} main.cpp)