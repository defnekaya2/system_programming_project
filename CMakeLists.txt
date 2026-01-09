cmake_minimum_required(VERSION 3.10)
project(sis_app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

include_directories(include ${PQXX_INCLUDE_DIRS})

add_executable(sis_app
    src/main.cpp
    src/services/student_service.cpp
)

target_link_libraries(sis_app ${PQXX_LIBRARIES})

