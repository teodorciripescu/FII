# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = /Users/teodorciripescu/CLionProjects/chatClient

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/teodorciripescu/CLionProjects/chatClient/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/chatClient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chatClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chatClient.dir/flags.make

CMakeFiles/chatClient.dir/main.cpp.o: CMakeFiles/chatClient.dir/flags.make
CMakeFiles/chatClient.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/teodorciripescu/CLionProjects/chatClient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chatClient.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chatClient.dir/main.cpp.o -c /Users/teodorciripescu/CLionProjects/chatClient/main.cpp

CMakeFiles/chatClient.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chatClient.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/teodorciripescu/CLionProjects/chatClient/main.cpp > CMakeFiles/chatClient.dir/main.cpp.i

CMakeFiles/chatClient.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chatClient.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/teodorciripescu/CLionProjects/chatClient/main.cpp -o CMakeFiles/chatClient.dir/main.cpp.s

# Object files for target chatClient
chatClient_OBJECTS = \
"CMakeFiles/chatClient.dir/main.cpp.o"

# External object files for target chatClient
chatClient_EXTERNAL_OBJECTS =

chatClient: CMakeFiles/chatClient.dir/main.cpp.o
chatClient: CMakeFiles/chatClient.dir/build.make
chatClient: CMakeFiles/chatClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/teodorciripescu/CLionProjects/chatClient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable chatClient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chatClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chatClient.dir/build: chatClient

.PHONY : CMakeFiles/chatClient.dir/build

CMakeFiles/chatClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chatClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chatClient.dir/clean

CMakeFiles/chatClient.dir/depend:
	cd /Users/teodorciripescu/CLionProjects/chatClient/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/teodorciripescu/CLionProjects/chatClient /Users/teodorciripescu/CLionProjects/chatClient /Users/teodorciripescu/CLionProjects/chatClient/cmake-build-debug /Users/teodorciripescu/CLionProjects/chatClient/cmake-build-debug /Users/teodorciripescu/CLionProjects/chatClient/cmake-build-debug/CMakeFiles/chatClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chatClient.dir/depend

