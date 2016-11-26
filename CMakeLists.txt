cmake_minimum_required(VERSION 3.5)
project(gomoku)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

set(SOURCE_FILES main.c)
add_executable(gomoku ${SOURCE_FILES})

project(openings)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES openings.cpp)
add_executable(openings ${SOURCE_FILES})