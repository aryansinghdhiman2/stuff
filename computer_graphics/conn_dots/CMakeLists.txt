cmake_minimum_required(VERSION 3.13)

project(conndotsproj)
add_executable(conn_dots ConnectDots.c)
find_package(OpenGL REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS})

message(OPENGL_LIBRARIES="${OPENGL_LIBRARIES}")

target_link_libraries(conn_dots ${OPENGL_LIBRARIES} -lfreeglut)
# target_link_libraries(test ${OPENGL_LIBRARIES} -lfreeglut)
