# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fiatia1/Cmake/Tema

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fiatia1/Cmake/Tema/build

# Include any dependencies generated for this target.
include src/CMakeFiles/myproject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/myproject.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/myproject.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/myproject.dir/flags.make

src/CMakeFiles/myproject.dir/main.cpp.o: src/CMakeFiles/myproject.dir/flags.make
src/CMakeFiles/myproject.dir/main.cpp.o: ../src/main.cpp
src/CMakeFiles/myproject.dir/main.cpp.o: src/CMakeFiles/myproject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fiatia1/Cmake/Tema/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/myproject.dir/main.cpp.o"
	cd /home/fiatia1/Cmake/Tema/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/myproject.dir/main.cpp.o -MF CMakeFiles/myproject.dir/main.cpp.o.d -o CMakeFiles/myproject.dir/main.cpp.o -c /home/fiatia1/Cmake/Tema/src/main.cpp

src/CMakeFiles/myproject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myproject.dir/main.cpp.i"
	cd /home/fiatia1/Cmake/Tema/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fiatia1/Cmake/Tema/src/main.cpp > CMakeFiles/myproject.dir/main.cpp.i

src/CMakeFiles/myproject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myproject.dir/main.cpp.s"
	cd /home/fiatia1/Cmake/Tema/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fiatia1/Cmake/Tema/src/main.cpp -o CMakeFiles/myproject.dir/main.cpp.s

# Object files for target myproject
myproject_OBJECTS = \
"CMakeFiles/myproject.dir/main.cpp.o"

# External object files for target myproject
myproject_EXTERNAL_OBJECTS =

src/myproject: src/CMakeFiles/myproject.dir/main.cpp.o
src/myproject: src/CMakeFiles/myproject.dir/build.make
src/myproject: src/libmyproject_library.a
src/myproject: src/CMakeFiles/myproject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fiatia1/Cmake/Tema/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable myproject"
	cd /home/fiatia1/Cmake/Tema/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myproject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/myproject.dir/build: src/myproject
.PHONY : src/CMakeFiles/myproject.dir/build

src/CMakeFiles/myproject.dir/clean:
	cd /home/fiatia1/Cmake/Tema/build/src && $(CMAKE_COMMAND) -P CMakeFiles/myproject.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/myproject.dir/clean

src/CMakeFiles/myproject.dir/depend:
	cd /home/fiatia1/Cmake/Tema/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fiatia1/Cmake/Tema /home/fiatia1/Cmake/Tema/src /home/fiatia1/Cmake/Tema/build /home/fiatia1/Cmake/Tema/build/src /home/fiatia1/Cmake/Tema/build/src/CMakeFiles/myproject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/myproject.dir/depend

