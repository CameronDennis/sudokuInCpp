cmake_minimum_required(VERSION 3.15)
project(sudokuv2)

set(CMAKE_CXX_STANDARD 14)

add_executable(sudokuv2 main.cpp sudokuBoard.cpp)
add_executable(testing testing.cpp)