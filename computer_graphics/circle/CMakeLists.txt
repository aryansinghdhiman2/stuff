cmake_minimum_required(VERSION 3.13)

project(ddaproj)
add_executable(line circle.cpp)
# add_executable(line simple_dda_terminal.cpp)
# add_executable(line simple_dda_mouse.cpp)
# add_executable(line symm_dda_mouse.cpp)

find_package(OpenGL REQUIRED)
find_package(glui CONFIG REQUIRED)


include_directories( ${OPENGL_INCLUDE_DIRS})

message(OPENGL_LIBRARIES="${OPENGL_LIBRARIES}")

target_link_libraries(line ${OPENGL_LIBRARIES} -lfreeglut glui::glui)