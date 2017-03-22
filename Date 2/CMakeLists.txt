cmake_minimum_required(VERSION 3.6)
project(Date_solution)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Date.cpp
    Date.h
    P_Reminder.cpp
    P_Reminder.h
    Reminder.cpp
    Reminder.h
    test3.cpp)

add_executable(Date_solution ${SOURCE_FILES})