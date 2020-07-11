cmake_minimum_required(VERSION 3.14)
project(Hace)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG")
SET(CMAKE_CXX_FLAGS "-std=c++14 ")
# https://blog.csdn.net/qq_42189368/article/details/87252919

set(CMAKE_BUILD_TYPE Debug)
# https://blog.csdn.net/qq_32376851/article/details/78709407

add_executable(Hace main.cpp)
