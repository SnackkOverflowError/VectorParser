# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/adi/apps/clion-2019.1.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/adi/apps/clion-2019.1.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adi/development/cs/clion-projects/VectorParser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adi/development/cs/clion-projects/VectorParser/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TestParser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestParser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestParser.dir/flags.make

CMakeFiles/TestParser.dir/test.cpp.o: CMakeFiles/TestParser.dir/flags.make
CMakeFiles/TestParser.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adi/development/cs/clion-projects/VectorParser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestParser.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestParser.dir/test.cpp.o -c /home/adi/development/cs/clion-projects/VectorParser/test.cpp

CMakeFiles/TestParser.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestParser.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adi/development/cs/clion-projects/VectorParser/test.cpp > CMakeFiles/TestParser.dir/test.cpp.i

CMakeFiles/TestParser.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestParser.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adi/development/cs/clion-projects/VectorParser/test.cpp -o CMakeFiles/TestParser.dir/test.cpp.s

CMakeFiles/TestParser.dir/parser.cpp.o: CMakeFiles/TestParser.dir/flags.make
CMakeFiles/TestParser.dir/parser.cpp.o: ../parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adi/development/cs/clion-projects/VectorParser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TestParser.dir/parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestParser.dir/parser.cpp.o -c /home/adi/development/cs/clion-projects/VectorParser/parser.cpp

CMakeFiles/TestParser.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestParser.dir/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adi/development/cs/clion-projects/VectorParser/parser.cpp > CMakeFiles/TestParser.dir/parser.cpp.i

CMakeFiles/TestParser.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestParser.dir/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adi/development/cs/clion-projects/VectorParser/parser.cpp -o CMakeFiles/TestParser.dir/parser.cpp.s

# Object files for target TestParser
TestParser_OBJECTS = \
"CMakeFiles/TestParser.dir/test.cpp.o" \
"CMakeFiles/TestParser.dir/parser.cpp.o"

# External object files for target TestParser
TestParser_EXTERNAL_OBJECTS =

TestParser: CMakeFiles/TestParser.dir/test.cpp.o
TestParser: CMakeFiles/TestParser.dir/parser.cpp.o
TestParser: CMakeFiles/TestParser.dir/build.make
TestParser: CMakeFiles/TestParser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adi/development/cs/clion-projects/VectorParser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TestParser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestParser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestParser.dir/build: TestParser

.PHONY : CMakeFiles/TestParser.dir/build

CMakeFiles/TestParser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestParser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestParser.dir/clean

CMakeFiles/TestParser.dir/depend:
	cd /home/adi/development/cs/clion-projects/VectorParser/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adi/development/cs/clion-projects/VectorParser /home/adi/development/cs/clion-projects/VectorParser /home/adi/development/cs/clion-projects/VectorParser/cmake-build-debug /home/adi/development/cs/clion-projects/VectorParser/cmake-build-debug /home/adi/development/cs/clion-projects/VectorParser/cmake-build-debug/CMakeFiles/TestParser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestParser.dir/depend

