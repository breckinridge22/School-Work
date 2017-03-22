cmake_minimum_required(VERSION 3.6)
project(Date)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        date-test.cpp
        Date.cpp
        Date.h)

add_executable(Date ${SOURCE_FILES})