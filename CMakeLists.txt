cmake_minimum_required(VERSION 3.10)
project(sis-app)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBPQXX REQUIRED libpqxx)

include_directories(${LIBPQXX_INCLUDE_DIRS})
link_directories(${LIBPQXX_LIBRARY_DIRS})

add_executable(sis-app src/main.cpp)
target_link_libraries(sis-app ${LIBPQXX_LIBRARIES})

