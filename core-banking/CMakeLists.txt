cmake_minimum_required(VERSION 3.17)
project(core_banking)

set(CMAKE_CXX_STANDARD 14)

add_executable(core_banking main.cpp account.cpp account.h)