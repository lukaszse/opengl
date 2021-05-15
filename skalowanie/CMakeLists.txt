cmake_minimum_required(VERSION 3.17)
project(skalowanie)

set(CMAKE_CXX_STANDARD 14)


add_executable(skalowanie main.c)
target_link_libraries(skalowanie libglu32.a libfreeglut.a libopengl32.a libglut32.a libglaux.a)