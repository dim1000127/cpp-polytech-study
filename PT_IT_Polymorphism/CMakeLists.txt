cmake_minimum_required(VERSION 3.26)
project(PT_IT_Polymorphism)

set(CMAKE_CXX_STANDARD 17)

add_executable(PT_IT_Polymorphism main.cpp
        point.h
        shape.h
        rectangle.cpp
        rectangle.h
        circle.cpp
        circle.h)
