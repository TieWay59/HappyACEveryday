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

## 过多的indexing

你可以右键一些文件夹mark为excluded，会有一定改进。

## gitignore没有生效

本地仓库会有很多已缓存的操作，所以后来的规则会不生效。
所以按照下面的方式清楚一下缓存就好了。

``` bash
git rm -r --cached .
git add .
git commit -m 'update .gitignore'
```

