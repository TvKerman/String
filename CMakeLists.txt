cmake_minimum_required(VERSION 3.20)
project(String C)

set(CMAKE_C_STANDARD 11)

add_executable(String main.c)

add_library(str string/string_.h string/string_.c

        )