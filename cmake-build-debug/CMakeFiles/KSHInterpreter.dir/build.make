# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/brunon/桌面/CLion/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/brunon/桌面/CLion/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/brunon/CLionProjects/KSHInterpreter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/brunon/CLionProjects/KSHInterpreter/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/KSHInterpreter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/KSHInterpreter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/KSHInterpreter.dir/flags.make

CMakeFiles/KSHInterpreter.dir/main.c.o: CMakeFiles/KSHInterpreter.dir/flags.make
CMakeFiles/KSHInterpreter.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/brunon/CLionProjects/KSHInterpreter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/KSHInterpreter.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/KSHInterpreter.dir/main.c.o   -c /home/brunon/CLionProjects/KSHInterpreter/main.c

CMakeFiles/KSHInterpreter.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/KSHInterpreter.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/brunon/CLionProjects/KSHInterpreter/main.c > CMakeFiles/KSHInterpreter.dir/main.c.i

CMakeFiles/KSHInterpreter.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/KSHInterpreter.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/brunon/CLionProjects/KSHInterpreter/main.c -o CMakeFiles/KSHInterpreter.dir/main.c.s

CMakeFiles/KSHInterpreter.dir/main.c.o.requires:

.PHONY : CMakeFiles/KSHInterpreter.dir/main.c.o.requires

CMakeFiles/KSHInterpreter.dir/main.c.o.provides: CMakeFiles/KSHInterpreter.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/KSHInterpreter.dir/build.make CMakeFiles/KSHInterpreter.dir/main.c.o.provides.build
.PHONY : CMakeFiles/KSHInterpreter.dir/main.c.o.provides

CMakeFiles/KSHInterpreter.dir/main.c.o.provides.build: CMakeFiles/KSHInterpreter.dir/main.c.o


# Object files for target KSHInterpreter
KSHInterpreter_OBJECTS = \
"CMakeFiles/KSHInterpreter.dir/main.c.o"

# External object files for target KSHInterpreter
KSHInterpreter_EXTERNAL_OBJECTS =

KSHInterpreter: CMakeFiles/KSHInterpreter.dir/main.c.o
KSHInterpreter: CMakeFiles/KSHInterpreter.dir/build.make
KSHInterpreter: CMakeFiles/KSHInterpreter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/brunon/CLionProjects/KSHInterpreter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable KSHInterpreter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/KSHInterpreter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/KSHInterpreter.dir/build: KSHInterpreter

.PHONY : CMakeFiles/KSHInterpreter.dir/build

CMakeFiles/KSHInterpreter.dir/requires: CMakeFiles/KSHInterpreter.dir/main.c.o.requires

.PHONY : CMakeFiles/KSHInterpreter.dir/requires

CMakeFiles/KSHInterpreter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/KSHInterpreter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/KSHInterpreter.dir/clean

CMakeFiles/KSHInterpreter.dir/depend:
	cd /home/brunon/CLionProjects/KSHInterpreter/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/brunon/CLionProjects/KSHInterpreter /home/brunon/CLionProjects/KSHInterpreter /home/brunon/CLionProjects/KSHInterpreter/cmake-build-debug /home/brunon/CLionProjects/KSHInterpreter/cmake-build-debug /home/brunon/CLionProjects/KSHInterpreter/cmake-build-debug/CMakeFiles/KSHInterpreter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/KSHInterpreter.dir/depend

