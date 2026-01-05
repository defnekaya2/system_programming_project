cmake_minimum_required(VERSION 3.10)

project(system_programming_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

add_executable(sis_app
    src/main.cpp
    src/database.cpp
    src/config.cpp
)

target_include_directories(sis_app PRIVATE
    include
    ${PQXX_INCLUDE_DIRS}
)

target_link_libraries(sis_app
    pqxx
    ${PQXX_LIBRARIES}
)
