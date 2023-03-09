cmake_minimum_required(VERSION 3.24)
project(code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(code
        Functions.cpp
        Functions.h
        Functions2.cpp
        Functions2.h
        main.cpp)
