cmake_minimum_required(VERSION 3.17)
project(OpenGL_rotacja3D C)

set(CMAKE_C_STANDARD 99)

add_executable(OpenGL_rotacja3D main.c)
target_link_libraries(OpenGL_rotacja3D libglu32.a libfreeglut.a libopengl32.a libglut32.a libglaux.a)