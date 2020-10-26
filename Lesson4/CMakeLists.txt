cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 17)

project(vector_sum)

add_executable(vectorSum src/main.cpp src/increment_and_sum.cpp src/vect_add_one.cpp)
