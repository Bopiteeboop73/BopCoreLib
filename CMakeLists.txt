cmake_minimum_required(VERSION 4.1)
project(Bopstructs)

set(CMAKE_CXX_STANDARD 20)

add_library(Bopstructs STATIC
        maths/Vector2.cpp
        )
