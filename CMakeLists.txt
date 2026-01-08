cmake_minimum_required(VERSION 3.10)
<<<<<<< HEAD
project(sis-app)
=======

project(system_programming_project)
>>>>>>> 5db1a381303d63373ea905a63ffa909bc922f1db

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
<<<<<<< HEAD
pkg_check_modules(LIBPQXX REQUIRED libpqxx)

include_directories(${LIBPQXX_INCLUDE_DIRS})
link_directories(${LIBPQXX_LIBRARY_DIRS})

add_executable(sis-app src/main.cpp)
target_link_libraries(sis-app ${LIBPQXX_LIBRARIES})

=======
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
#updated on week 2
>>>>>>> 5db1a381303d63373ea905a63ffa909bc922f1db
