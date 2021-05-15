cmake_minimum_required(VERSION 3.17)
project(openglTest)

set(CMAKE_CXX_STANDARD 14)


add_executable(openglTest main.c)
target_link_libraries(openglTest libglu32.a libfreeglut.a libopengl32.a libglut32.a libglaux.a)