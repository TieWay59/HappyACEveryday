cmake_minimum_required(VERSION 3.14)
project(Hace)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG")
set(CMAKE_CXX_FLAGS "-std=c++17")
# https://blog.csdn.net/qq_42189368/article/details/87252919

#set(CMAKE_EXE_LINKER_FLAGS "-lstdc++fs")
add_executable(Hace main.cpp)

# (latest MinGW) https://nuwen.net/mingw.html#install