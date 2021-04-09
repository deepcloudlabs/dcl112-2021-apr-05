cmake_minimum_required(VERSION 3.17)
project(module14_multithreading)
project(study-parallel-programming)

set(CMAKE_CXX_STANDARD 17)

add_executable(module14_multithreading main.cpp study-parallel-programming.cpp)
add_executable(study-parallel-programming study-parallel-programming.cpp)