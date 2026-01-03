cmake_minimum_required(VERSION 3.10)
project(sis_app)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

add_executable(sis_app
    src/main.cpp
    src/config.cpp
    src/database/database.cpp
    src/services/student_service.cpp
)

target_include_directories(sis_app PRIVATE
    include
    ${PQXX_INCLUDE_DIRS}
)

target_link_libraries(sis_app PRIVATE
    ${PQXX_LIBRARIES}
)

