cmake_minimum_required(VERSION 3.13)

project(ddaproj)
add_executable(transform transformations.cpp)

find_package(OpenGL REQUIRED)
find_package(glui CONFIG REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS})

message(OPENGL_LIBRARIES="${OPENGL_LIBRARIES}")
target_link_libraries(transform ${OPENGL_LIBRARIES} -lfreeglut glui::glui)


