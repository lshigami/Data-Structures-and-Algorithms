cmake_minimum_required(VERSION 3.26)
project(untitled8)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled8 main.cpp
        Stack.h
        Stack.cpp
        Queue.h
        Queue.cpp
        PriorityQueue.h
        PriorityQueue.cpp)
