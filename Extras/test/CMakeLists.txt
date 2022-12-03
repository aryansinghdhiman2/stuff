cmake_minimum_required(VERSION 3.0.0)
project(time_now VERSION 0.1.0)
project(file)

include(CTest)
enable_testing()

add_library(hello example.cpp)
add_executable(time_now time.cpp)
add_executable(file file.cpp)

target_link_libraries(time_now hello)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
