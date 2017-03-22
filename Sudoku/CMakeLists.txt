cmake_minimum_required(VERSION 3.6)
project(Sudoku)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Sudoku.h Sudoku.cpp Sudoku-driver.cpp)
add_executable(Sudoku ${SOURCE_FILES})