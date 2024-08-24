cmake_minimum_required(VERSION 3.13)

project(ddaproj)
add_executable(boundary boundaryFill.cpp)
add_executable(scanline ScanLineFilling.cpp)

find_package(OpenGL REQUIRED)
find_package(glui CONFIG REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS})

message(OPENGL_LIBRARIES="${OPENGL_LIBRARIES}")
target_link_libraries(boundary ${OPENGL_LIBRARIES} -lfreeglut glui::glui)
target_link_libraries(scanline ${OPENGL_LIBRARIES} -lfreeglut glui::glui)
# target_link_libraries(test ${OPENGL_LIBRARIES} -lfreeglut)
