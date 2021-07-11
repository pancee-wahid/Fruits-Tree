cmake_minimum_required(VERSION 3.19)
project(Fruit)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Fruit
        Fruit.cpp
        Fruit.h)
