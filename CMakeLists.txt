cmake_minimum_required(VERSION 3.20)
project(MyGauss C)

set(CMAKE_C_STANDARD 99)

add_executable(MyGauss main.c matrix.h cholesky.h gaussGJ.h singleLoop.h)
