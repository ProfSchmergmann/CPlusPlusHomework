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
CMAKE_SOURCE_DIR = /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x01/uebungen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x01/uebungen/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/blue_canyon.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/blue_canyon.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/blue_canyon.dir/flags.make

CMakeFiles/blue_canyon.dir/blue_canyon.cpp.o: CMakeFiles/blue_canyon.dir/flags.make
CMakeFiles/blue_canyon.dir/blue_canyon.cpp.o: ../blue_canyon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x01/uebungen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/blue_canyon.dir/blue_canyon.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/blue_canyon.dir/blue_canyon.cpp.o -c /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x01/uebungen/blue_canyon.cpp

CMakeFiles/blue_canyon.dir/blue_canyon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blue_canyon.dir/blue_canyon.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x01/uebungen/blue_canyon.cpp > CMakeFiles/blue_canyon.dir/blue_canyon.cpp.i

CMakeFiles/blue_canyon.dir/blue_canyon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blue_canyon.dir/blue_canyon.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x01/uebungen/blue_canyon.cpp -o CMakeFiles/blue_canyon.dir/blue_canyon.cpp.s

# Object files for target blue_canyon
blue_canyon_OBJECTS = \
"CMakeFiles/blue_canyon.dir/blue_canyon.cpp.o"

# External object files for target blue_canyon
blue_canyon_EXTERNAL_OBJECTS =

blue_canyon.exe: CMakeFiles/blue_canyon.dir/blue_canyon.cpp.o
blue_canyon.exe: CMakeFiles/blue_canyon.dir/build.make
blue_canyon.exe: CMakeFiles/blue_canyon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x01/uebungen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable blue_canyon.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/blue_canyon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/blue_canyon.dir/build: blue_canyon.exe

.PHONY : CMakeFiles/blue_canyon.dir/build

CMakeFiles/blue_canyon.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/blue_canyon.dir/cmake_clean.cmake
.PHONY : CMakeFiles/blue_canyon.dir/clean

CMakeFiles/blue_canyon.dir/depend:
	cd /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x01/uebungen/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x01/uebungen /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x01/uebungen /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x01/uebungen/cmake-build-debug /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x01/uebungen/cmake-build-debug /cygdrive/c/Users/sberg/Documents/Uni/C++/cpp_test/0x01/uebungen/cmake-build-debug/CMakeFiles/blue_canyon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/blue_canyon.dir/depend

