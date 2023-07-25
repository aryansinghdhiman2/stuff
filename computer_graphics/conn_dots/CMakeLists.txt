cmake_minimum_required(VERSION 3.13)

project(conndotsproj)
add_executable(conn_dots ConnectDots.c)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS})

target_compile_options(conn_dots PUBLIC)
target_link_libraries(conn_dots ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} -lfreeglut)
