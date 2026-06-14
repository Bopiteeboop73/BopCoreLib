cmake_minimum_required(VERSION 3.20)

project(BopCoreLib LANGUAGES CXX)

add_library(BopCoreLib STATIC
        src/Vector2.cpp
        src/Vector3.cpp
)

target_compile_features(BopCoreLib PUBLIC cxx_std_20)

target_include_directories(BopCoreLib
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)