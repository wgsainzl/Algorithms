cmake_minimum_required(VERSION 3.29)
project(Hashing)

set(CMAKE_CXX_STANDARD 20)

add_executable(Hashing main.cpp
        Hashtable.h
        Hashtable.cpp)
