cmake_minimum_required(VERSION 3.10.0)
project(lab1.1)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/class_Massive.cpp
)

set(HEADERS
    include/class_Massive.h
)

add_executable(lab1.1 ${SOURCES} ${HEADERS})