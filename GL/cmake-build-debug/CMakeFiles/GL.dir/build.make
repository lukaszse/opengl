# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\02_PROGRAMOWANIE\cpp\GL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\02_PROGRAMOWANIE\cpp\GL\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GL.dir/flags.make

CMakeFiles/GL.dir/main.cpp.obj: CMakeFiles/GL.dir/flags.make
CMakeFiles/GL.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\02_PROGRAMOWANIE\cpp\GL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GL.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\GL.dir\main.cpp.obj -c D:\02_PROGRAMOWANIE\cpp\GL\main.cpp

CMakeFiles/GL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GL.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\02_PROGRAMOWANIE\cpp\GL\main.cpp > CMakeFiles\GL.dir\main.cpp.i

CMakeFiles/GL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GL.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\02_PROGRAMOWANIE\cpp\GL\main.cpp -o CMakeFiles\GL.dir\main.cpp.s

# Object files for target GL
GL_OBJECTS = \
"CMakeFiles/GL.dir/main.cpp.obj"

# External object files for target GL
GL_EXTERNAL_OBJECTS =

GL.exe: CMakeFiles/GL.dir/main.cpp.obj
GL.exe: CMakeFiles/GL.dir/build.make
GL.exe: CMakeFiles/GL.dir/linklibs.rsp
GL.exe: CMakeFiles/GL.dir/objects1.rsp
GL.exe: CMakeFiles/GL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\02_PROGRAMOWANIE\cpp\GL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GL.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GL.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GL.dir/build: GL.exe

.PHONY : CMakeFiles/GL.dir/build

CMakeFiles/GL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GL.dir\cmake_clean.cmake
.PHONY : CMakeFiles/GL.dir/clean

CMakeFiles/GL.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\02_PROGRAMOWANIE\cpp\GL D:\02_PROGRAMOWANIE\cpp\GL D:\02_PROGRAMOWANIE\cpp\GL\cmake-build-debug D:\02_PROGRAMOWANIE\cpp\GL\cmake-build-debug D:\02_PROGRAMOWANIE\cpp\GL\cmake-build-debug\CMakeFiles\GL.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GL.dir/depend

