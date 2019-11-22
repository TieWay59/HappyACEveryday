cmake_minimum_required(VERSION 3.14)
project(Hace)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS "-std=c++14 ")
# https://blog.csdn.net/qq_42189368/article/details/87252919

add_executable(Hace main.cpp 2019codes/nowcoder/contest2271/A.cpp 2019codes/nowcoder/contest2271/B.cpp)
