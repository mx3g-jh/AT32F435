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
CMAKE_SOURCE_DIR = /home/mx3g/Desktop/AT_make/AT32F435/at32f435_at-start-f435

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mx3g/Desktop/AT_make/AT32F435/at32f435_at-start-f435/build

# Utility rule file for jlink_gdb_server.

# Include any custom commands dependencies for this target.
include CMakeFiles/jlink_gdb_server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/jlink_gdb_server.dir/progress.make

CMakeFiles/jlink_gdb_server:
	JLinkGDBServer -device AT32F435CMU7 -if SWD

jlink_gdb_server: CMakeFiles/jlink_gdb_server
jlink_gdb_server: CMakeFiles/jlink_gdb_server.dir/build.make
.PHONY : jlink_gdb_server

# Rule to build all files generated by this target.
CMakeFiles/jlink_gdb_server.dir/build: jlink_gdb_server
.PHONY : CMakeFiles/jlink_gdb_server.dir/build

CMakeFiles/jlink_gdb_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/jlink_gdb_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/jlink_gdb_server.dir/clean

CMakeFiles/jlink_gdb_server.dir/depend:
	cd /home/mx3g/Desktop/AT_make/AT32F435/at32f435_at-start-f435/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mx3g/Desktop/AT_make/AT32F435/at32f435_at-start-f435 /home/mx3g/Desktop/AT_make/AT32F435/at32f435_at-start-f435 /home/mx3g/Desktop/AT_make/AT32F435/at32f435_at-start-f435/build /home/mx3g/Desktop/AT_make/AT32F435/at32f435_at-start-f435/build /home/mx3g/Desktop/AT_make/AT32F435/at32f435_at-start-f435/build/CMakeFiles/jlink_gdb_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/jlink_gdb_server.dir/depend

