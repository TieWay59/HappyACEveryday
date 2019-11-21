# My issues when using CLion 



## Clone and initiate this project

<img src="cloneproject.png" alt="pic1" style="zoom:80%;" />



<img src="initproject.png" alt="pic2" style="zoom:80%;" />



## Enable C++11 feature

Add the code below into `CMakeLists.txt`

```cmake
SET(CMAKE_CXX_FLAGS "-std=c++11 ") 
#https://blog.csdn.net/qq_42189368/article/details/87252919
```

Additionally, my full `CMakeLists.txt` config is like below:

```cmake
cmake_minimum_required(VERSION 3.14)
project(Hace)

set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_CXX_FLAGS "-std=c++11 ")
#https://blog.csdn.net/qq_42189368/article/details/87252919

add_executable(Hace main.cpp)

```



