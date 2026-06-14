cmake_minimum_required(VERSION 4.1)
project(BopCoreLib)

set(CMAKE_CXX_STANDARD 20)

add_library(BopCoreLib STATIC
        maths/Vector2.cpp
        )
