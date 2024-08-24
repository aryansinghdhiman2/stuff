cmake_minimum_required(VERSION 3.13)

project(testproj)
add_executable(test semicircleinsquare.cpp) 
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(glui CONFIG REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_compile_options(test PUBLIC)
# target_link_options(test PUBLIC -lglut32)
target_link_libraries(test ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} -lfreeglut glui::glui)
