cmake_minimum_required(VERSION 3.29)
project(LoadBalancer)

set(CMAKE_CXX_STANDARD 20)

add_executable(LoadBalancer main.cpp
        LoadBalancer.h
        LoadBalancer.cpp)
