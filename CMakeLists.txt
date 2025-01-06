cmake_minimum_required(VERSION 3.28)
project(maman22)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(maman22
        complex.c
        complex.h
        mycomp.c
        README.md
        commands.c
        commands.h)
