cmake_minimum_required(VERSION 3.26)
project(MathProg)

set(CMAKE_CXX_STANDARD 17)

add_executable(MathProg main.cpp
        Monominal.cpp
        Function.cpp)
