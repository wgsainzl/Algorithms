cmake_minimum_required(VERSION 3.29)
project(NewQueue)

set(CMAKE_CXX_STANDARD 20)

add_executable(NewQueue main.cpp
        Queue.cpp
        Queuedemo.cpp
        Queuedemo.h)
