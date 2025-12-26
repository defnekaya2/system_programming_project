cmake_minimum_required(VERSION 3.10)

project(system_programming_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(sis_app
    src/main.cpp
)

target_include_directories(sis_app PRIVATE include)
