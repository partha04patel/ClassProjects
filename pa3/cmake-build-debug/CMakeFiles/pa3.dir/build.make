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
CMAKE_COMMAND = /cygdrive/c/Users/Parth/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Parth/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Parth/CLionProjects/pa3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Parth/CLionProjects/pa3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pa3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pa3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pa3.dir/flags.make

CMakeFiles/pa3.dir/main.cpp.o: CMakeFiles/pa3.dir/flags.make
CMakeFiles/pa3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Parth/CLionProjects/pa3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pa3.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa3.dir/main.cpp.o -c /cygdrive/c/Users/Parth/CLionProjects/pa3/main.cpp

CMakeFiles/pa3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa3.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Parth/CLionProjects/pa3/main.cpp > CMakeFiles/pa3.dir/main.cpp.i

CMakeFiles/pa3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa3.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Parth/CLionProjects/pa3/main.cpp -o CMakeFiles/pa3.dir/main.cpp.s

CMakeFiles/pa3.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/pa3.dir/main.cpp.o.requires

CMakeFiles/pa3.dir/main.cpp.o.provides: CMakeFiles/pa3.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/pa3.dir/build.make CMakeFiles/pa3.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/pa3.dir/main.cpp.o.provides

CMakeFiles/pa3.dir/main.cpp.o.provides.build: CMakeFiles/pa3.dir/main.cpp.o


CMakeFiles/pa3.dir/pa3.cpp.o: CMakeFiles/pa3.dir/flags.make
CMakeFiles/pa3.dir/pa3.cpp.o: ../pa3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Parth/CLionProjects/pa3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pa3.dir/pa3.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa3.dir/pa3.cpp.o -c /cygdrive/c/Users/Parth/CLionProjects/pa3/pa3.cpp

CMakeFiles/pa3.dir/pa3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa3.dir/pa3.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Parth/CLionProjects/pa3/pa3.cpp > CMakeFiles/pa3.dir/pa3.cpp.i

CMakeFiles/pa3.dir/pa3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa3.dir/pa3.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Parth/CLionProjects/pa3/pa3.cpp -o CMakeFiles/pa3.dir/pa3.cpp.s

CMakeFiles/pa3.dir/pa3.cpp.o.requires:

.PHONY : CMakeFiles/pa3.dir/pa3.cpp.o.requires

CMakeFiles/pa3.dir/pa3.cpp.o.provides: CMakeFiles/pa3.dir/pa3.cpp.o.requires
	$(MAKE) -f CMakeFiles/pa3.dir/build.make CMakeFiles/pa3.dir/pa3.cpp.o.provides.build
.PHONY : CMakeFiles/pa3.dir/pa3.cpp.o.provides

CMakeFiles/pa3.dir/pa3.cpp.o.provides.build: CMakeFiles/pa3.dir/pa3.cpp.o


# Object files for target pa3
pa3_OBJECTS = \
"CMakeFiles/pa3.dir/main.cpp.o" \
"CMakeFiles/pa3.dir/pa3.cpp.o"

# External object files for target pa3
pa3_EXTERNAL_OBJECTS =

pa3.exe: CMakeFiles/pa3.dir/main.cpp.o
pa3.exe: CMakeFiles/pa3.dir/pa3.cpp.o
pa3.exe: CMakeFiles/pa3.dir/build.make
pa3.exe: CMakeFiles/pa3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Parth/CLionProjects/pa3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable pa3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pa3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pa3.dir/build: pa3.exe

.PHONY : CMakeFiles/pa3.dir/build

CMakeFiles/pa3.dir/requires: CMakeFiles/pa3.dir/main.cpp.o.requires
CMakeFiles/pa3.dir/requires: CMakeFiles/pa3.dir/pa3.cpp.o.requires

.PHONY : CMakeFiles/pa3.dir/requires

CMakeFiles/pa3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pa3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pa3.dir/clean

CMakeFiles/pa3.dir/depend:
	cd /cygdrive/c/Users/Parth/CLionProjects/pa3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Parth/CLionProjects/pa3 /cygdrive/c/Users/Parth/CLionProjects/pa3 /cygdrive/c/Users/Parth/CLionProjects/pa3/cmake-build-debug /cygdrive/c/Users/Parth/CLionProjects/pa3/cmake-build-debug /cygdrive/c/Users/Parth/CLionProjects/pa3/cmake-build-debug/CMakeFiles/pa3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pa3.dir/depend

