cmake_minimum_required(VERSION 3.27)
project(svansslukare_final)

set(CMAKE_CXX_STANDARD 17)
include_directories(inc)

add_executable(svansslukare_final src/main.cpp
        src/ship.cpp
        src/GameFunction.cpp
        src/event.cpp
        src/functions.cpp
)
