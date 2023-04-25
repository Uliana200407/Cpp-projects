cmake_minimum_required(VERSION 3.24)
project(test_cpp2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(test_cpp2
        main.cpp
        TSystem2LinearEquation.cpp
        TSystem2LinearEquation.h
        TSystemL3inearEquation.cpp
        TSystemL3inearEquation.h
        TSystemLinearEquation.cpp
        TSystemLinearEquation.h)
