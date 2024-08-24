cmake_minimum_required(VERSION 3.0.0)
project(time VERSION 0.1.0)

include(CTest)
enable_testing()

add_compile_options(-Wall)

add_executable(time 16_time.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
