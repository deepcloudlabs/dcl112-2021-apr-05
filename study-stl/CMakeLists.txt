cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

project(study-vector)
project(study_map)

add_executable(study-vector study-vector.cpp)
add_executable(study_map study-map.cpp)

target_link_libraries(study-vector pthread)