cmake_minimum_required(VERSION 3.13)

project(ddaproj)

add_library(csvlib "../csvHandler.cpp" "../csvHandler.hpp")
add_library(ellipsehelperlib "ellipse_helper.cpp" "ellipse_helper.hpp")

add_executable(ellipse_file ellipse.cpp)
add_executable(ellipse_double_buffer ellipse_backup.cpp)

find_package(OpenGL REQUIRED)
find_package(glui CONFIG REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS})

# message(OPENGL_LIBRARIES="${OPENGL_LIBRARIES}")

target_link_libraries(ellipse_file ${OPENGL_LIBRARIES} -lfreeglut glui::glui ellipsehelperlib csvlib)
target_link_libraries(ellipse_double_buffer ${OPENGL_LIBRARIES} -lfreeglut glui::glui)