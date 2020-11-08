cmake_minimum_required(VERSION 3.17)
project(Exercise6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Exercise6
        Real.cpp
        Real.h main.cpp)
