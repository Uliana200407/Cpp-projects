cmake_minimum_required(VERSION 3.19)
project(test_cpp3)

set(CMAKE_CXX_STANDARD 14)

add_executable(test_cpp3 main.cpp LinkedList.h LinkedList.tpp Functions.cpp Functions.h)