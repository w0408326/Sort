cmake_minimum_required(VERSION 3.15)
project(Sort)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sort main.cpp sort.h sort.cpp array_populator.h array_populator.cpp)