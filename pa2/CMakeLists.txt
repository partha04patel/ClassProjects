cmake_minimum_required(VERSION 3.8)
project(pa2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp main.h)
add_executable(main.cpp ${SOURCE_FILES} main.h)