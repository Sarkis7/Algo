cmake_minimum_required(VERSION 3.9)
project(Algorithm)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(Algorithm main.cpp find_max_subarray.h)