cmake_minimum_required(VERSION 3.17)
project(OpenGL_glut C)

set(CMAKE_C_STANDARD 99)

add_executable(OpenGL_glut main.c)
target_link_libraries(OpenGL_glut libglu32.a libfreeglut.a libopengl32.a libglut32.a libglaux.a)