# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /cygdrive/c/Users/sberg/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/sberg/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x02/uebungen0x02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x02/uebungen0x02/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/elkford.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/elkford.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/elkford.dir/flags.make

CMakeFiles/elkford.dir/elkford.cpp.o: CMakeFiles/elkford.dir/flags.make
CMakeFiles/elkford.dir/elkford.cpp.o: ../elkford.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x02/uebungen0x02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/elkford.dir/elkford.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/elkford.dir/elkford.cpp.o -c /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x02/uebungen0x02/elkford.cpp

CMakeFiles/elkford.dir/elkford.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/elkford.dir/elkford.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x02/uebungen0x02/elkford.cpp > CMakeFiles/elkford.dir/elkford.cpp.i

CMakeFiles/elkford.dir/elkford.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/elkford.dir/elkford.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x02/uebungen0x02/elkford.cpp -o CMakeFiles/elkford.dir/elkford.cpp.s

# Object files for target elkford
elkford_OBJECTS = \
"CMakeFiles/elkford.dir/elkford.cpp.o"

# External object files for target elkford
elkford_EXTERNAL_OBJECTS =

elkford.exe: CMakeFiles/elkford.dir/elkford.cpp.o
elkford.exe: CMakeFiles/elkford.dir/build.make
elkford.exe: CMakeFiles/elkford.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x02/uebungen0x02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable elkford.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/elkford.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/elkford.dir/build: elkford.exe

.PHONY : CMakeFiles/elkford.dir/build

CMakeFiles/elkford.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/elkford.dir/cmake_clean.cmake
.PHONY : CMakeFiles/elkford.dir/clean

CMakeFiles/elkford.dir/depend:
	cd /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x02/uebungen0x02/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x02/uebungen0x02 /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x02/uebungen0x02 /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x02/uebungen0x02/cmake-build-debug /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x02/uebungen0x02/cmake-build-debug /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x02/uebungen0x02/cmake-build-debug/CMakeFiles/elkford.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/elkford.dir/depend

