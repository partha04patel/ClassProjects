cmake_minimum_required(VERSION 3.8)
project(pa3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp pa3.cpp pa3.h)
add_executable(pa3 ${SOURCE_FILES} pa3.cpp pa3.h)