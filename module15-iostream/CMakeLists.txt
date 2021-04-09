cmake_minimum_required(VERSION 3.17)
project(module15_iostream)
project(read-circle)

set(CMAKE_CXX_STANDARD 14)

add_executable(module15_iostream main.cpp circle.cpp circle.h)
add_executable(read-circle.cpp read-circle.cpp circle.cpp circle.h)