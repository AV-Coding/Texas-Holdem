# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/arielvillasenor/CLionProjects/CardTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/arielvillasenor/CLionProjects/CardTest/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CardTest.cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CardTest.cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CardTest.cpp.dir/flags.make

CMakeFiles/CardTest.cpp.dir/Card.cpp.o: CMakeFiles/CardTest.cpp.dir/flags.make
CMakeFiles/CardTest.cpp.dir/Card.cpp.o: ../Card.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arielvillasenor/CLionProjects/CardTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CardTest.cpp.dir/Card.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CardTest.cpp.dir/Card.cpp.o -c /Users/arielvillasenor/CLionProjects/CardTest/Card.cpp

CMakeFiles/CardTest.cpp.dir/Card.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CardTest.cpp.dir/Card.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/arielvillasenor/CLionProjects/CardTest/Card.cpp > CMakeFiles/CardTest.cpp.dir/Card.cpp.i

CMakeFiles/CardTest.cpp.dir/Card.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CardTest.cpp.dir/Card.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/arielvillasenor/CLionProjects/CardTest/Card.cpp -o CMakeFiles/CardTest.cpp.dir/Card.cpp.s

# Object files for target CardTest.cpp
CardTest_cpp_OBJECTS = \
"CMakeFiles/CardTest.cpp.dir/Card.cpp.o"

# External object files for target CardTest.cpp
CardTest_cpp_EXTERNAL_OBJECTS =

CardTest.cpp: CMakeFiles/CardTest.cpp.dir/Card.cpp.o
CardTest.cpp: CMakeFiles/CardTest.cpp.dir/build.make
CardTest.cpp: CMakeFiles/CardTest.cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/arielvillasenor/CLionProjects/CardTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CardTest.cpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CardTest.cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CardTest.cpp.dir/build: CardTest.cpp

.PHONY : CMakeFiles/CardTest.cpp.dir/build

CMakeFiles/CardTest.cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CardTest.cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CardTest.cpp.dir/clean

CMakeFiles/CardTest.cpp.dir/depend:
	cd /Users/arielvillasenor/CLionProjects/CardTest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/arielvillasenor/CLionProjects/CardTest /Users/arielvillasenor/CLionProjects/CardTest /Users/arielvillasenor/CLionProjects/CardTest/cmake-build-debug /Users/arielvillasenor/CLionProjects/CardTest/cmake-build-debug /Users/arielvillasenor/CLionProjects/CardTest/cmake-build-debug/CMakeFiles/CardTest.cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CardTest.cpp.dir/depend
