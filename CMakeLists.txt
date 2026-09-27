cmake_minimum_required(VERSION 3.14)
project(MatrixLib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(matrix_app
    src/Matrix.cpp
    src/main.cpp
)