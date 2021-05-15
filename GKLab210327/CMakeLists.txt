cmake_minimum_required(VERSION 3.17)
project(GKLab210327 C)

set(CMAKE_C_STANDARD 99)

add_executable(GKLab210327 main.c)
target_link_libraries(GKLab210327 libglu32.a libfreeglut.a libopengl32.a libglut32.a libglaux.a)