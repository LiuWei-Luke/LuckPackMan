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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/romens/Documents/graphic/LuckPackMan

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/romens/Documents/graphic/LuckPackMan/build

# Include any dependencies generated for this target.
include CMakeFiles/packman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/packman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/packman.dir/flags.make

CMakeFiles/packman.dir/ScatterStrategy.cpp.o: CMakeFiles/packman.dir/flags.make
CMakeFiles/packman.dir/ScatterStrategy.cpp.o: ../ScatterStrategy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romens/Documents/graphic/LuckPackMan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/packman.dir/ScatterStrategy.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/packman.dir/ScatterStrategy.cpp.o -c /Users/romens/Documents/graphic/LuckPackMan/ScatterStrategy.cpp

CMakeFiles/packman.dir/ScatterStrategy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/packman.dir/ScatterStrategy.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romens/Documents/graphic/LuckPackMan/ScatterStrategy.cpp > CMakeFiles/packman.dir/ScatterStrategy.cpp.i

CMakeFiles/packman.dir/ScatterStrategy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/packman.dir/ScatterStrategy.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romens/Documents/graphic/LuckPackMan/ScatterStrategy.cpp -o CMakeFiles/packman.dir/ScatterStrategy.cpp.s

CMakeFiles/packman.dir/ScatterTopRight.cpp.o: CMakeFiles/packman.dir/flags.make
CMakeFiles/packman.dir/ScatterTopRight.cpp.o: ../ScatterTopRight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romens/Documents/graphic/LuckPackMan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/packman.dir/ScatterTopRight.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/packman.dir/ScatterTopRight.cpp.o -c /Users/romens/Documents/graphic/LuckPackMan/ScatterTopRight.cpp

CMakeFiles/packman.dir/ScatterTopRight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/packman.dir/ScatterTopRight.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romens/Documents/graphic/LuckPackMan/ScatterTopRight.cpp > CMakeFiles/packman.dir/ScatterTopRight.cpp.i

CMakeFiles/packman.dir/ScatterTopRight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/packman.dir/ScatterTopRight.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romens/Documents/graphic/LuckPackMan/ScatterTopRight.cpp -o CMakeFiles/packman.dir/ScatterTopRight.cpp.s

CMakeFiles/packman.dir/game.cpp.o: CMakeFiles/packman.dir/flags.make
CMakeFiles/packman.dir/game.cpp.o: ../game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romens/Documents/graphic/LuckPackMan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/packman.dir/game.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/packman.dir/game.cpp.o -c /Users/romens/Documents/graphic/LuckPackMan/game.cpp

CMakeFiles/packman.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/packman.dir/game.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romens/Documents/graphic/LuckPackMan/game.cpp > CMakeFiles/packman.dir/game.cpp.i

CMakeFiles/packman.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/packman.dir/game.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romens/Documents/graphic/LuckPackMan/game.cpp -o CMakeFiles/packman.dir/game.cpp.s

CMakeFiles/packman.dir/ghost.cpp.o: CMakeFiles/packman.dir/flags.make
CMakeFiles/packman.dir/ghost.cpp.o: ../ghost.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romens/Documents/graphic/LuckPackMan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/packman.dir/ghost.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/packman.dir/ghost.cpp.o -c /Users/romens/Documents/graphic/LuckPackMan/ghost.cpp

CMakeFiles/packman.dir/ghost.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/packman.dir/ghost.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romens/Documents/graphic/LuckPackMan/ghost.cpp > CMakeFiles/packman.dir/ghost.cpp.i

CMakeFiles/packman.dir/ghost.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/packman.dir/ghost.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romens/Documents/graphic/LuckPackMan/ghost.cpp -o CMakeFiles/packman.dir/ghost.cpp.s

CMakeFiles/packman.dir/ghost_object.cpp.o: CMakeFiles/packman.dir/flags.make
CMakeFiles/packman.dir/ghost_object.cpp.o: ../ghost_object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romens/Documents/graphic/LuckPackMan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/packman.dir/ghost_object.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/packman.dir/ghost_object.cpp.o -c /Users/romens/Documents/graphic/LuckPackMan/ghost_object.cpp

CMakeFiles/packman.dir/ghost_object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/packman.dir/ghost_object.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romens/Documents/graphic/LuckPackMan/ghost_object.cpp > CMakeFiles/packman.dir/ghost_object.cpp.i

CMakeFiles/packman.dir/ghost_object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/packman.dir/ghost_object.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romens/Documents/graphic/LuckPackMan/ghost_object.cpp -o CMakeFiles/packman.dir/ghost_object.cpp.s

CMakeFiles/packman.dir/glad.c.o: CMakeFiles/packman.dir/flags.make
CMakeFiles/packman.dir/glad.c.o: ../glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romens/Documents/graphic/LuckPackMan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/packman.dir/glad.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/packman.dir/glad.c.o   -c /Users/romens/Documents/graphic/LuckPackMan/glad.c

CMakeFiles/packman.dir/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/packman.dir/glad.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/romens/Documents/graphic/LuckPackMan/glad.c > CMakeFiles/packman.dir/glad.c.i

CMakeFiles/packman.dir/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/packman.dir/glad.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/romens/Documents/graphic/LuckPackMan/glad.c -o CMakeFiles/packman.dir/glad.c.s

CMakeFiles/packman.dir/main.cpp.o: CMakeFiles/packman.dir/flags.make
CMakeFiles/packman.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romens/Documents/graphic/LuckPackMan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/packman.dir/main.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/packman.dir/main.cpp.o -c /Users/romens/Documents/graphic/LuckPackMan/main.cpp

CMakeFiles/packman.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/packman.dir/main.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romens/Documents/graphic/LuckPackMan/main.cpp > CMakeFiles/packman.dir/main.cpp.i

CMakeFiles/packman.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/packman.dir/main.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romens/Documents/graphic/LuckPackMan/main.cpp -o CMakeFiles/packman.dir/main.cpp.s

CMakeFiles/packman.dir/maze.cpp.o: CMakeFiles/packman.dir/flags.make
CMakeFiles/packman.dir/maze.cpp.o: ../maze.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romens/Documents/graphic/LuckPackMan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/packman.dir/maze.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/packman.dir/maze.cpp.o -c /Users/romens/Documents/graphic/LuckPackMan/maze.cpp

CMakeFiles/packman.dir/maze.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/packman.dir/maze.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romens/Documents/graphic/LuckPackMan/maze.cpp > CMakeFiles/packman.dir/maze.cpp.i

CMakeFiles/packman.dir/maze.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/packman.dir/maze.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romens/Documents/graphic/LuckPackMan/maze.cpp -o CMakeFiles/packman.dir/maze.cpp.s

CMakeFiles/packman.dir/maze_object.cpp.o: CMakeFiles/packman.dir/flags.make
CMakeFiles/packman.dir/maze_object.cpp.o: ../maze_object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romens/Documents/graphic/LuckPackMan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/packman.dir/maze_object.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/packman.dir/maze_object.cpp.o -c /Users/romens/Documents/graphic/LuckPackMan/maze_object.cpp

CMakeFiles/packman.dir/maze_object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/packman.dir/maze_object.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romens/Documents/graphic/LuckPackMan/maze_object.cpp > CMakeFiles/packman.dir/maze_object.cpp.i

CMakeFiles/packman.dir/maze_object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/packman.dir/maze_object.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romens/Documents/graphic/LuckPackMan/maze_object.cpp -o CMakeFiles/packman.dir/maze_object.cpp.s

CMakeFiles/packman.dir/min_heap.cpp.o: CMakeFiles/packman.dir/flags.make
CMakeFiles/packman.dir/min_heap.cpp.o: ../min_heap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romens/Documents/graphic/LuckPackMan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/packman.dir/min_heap.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/packman.dir/min_heap.cpp.o -c /Users/romens/Documents/graphic/LuckPackMan/min_heap.cpp

CMakeFiles/packman.dir/min_heap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/packman.dir/min_heap.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romens/Documents/graphic/LuckPackMan/min_heap.cpp > CMakeFiles/packman.dir/min_heap.cpp.i

CMakeFiles/packman.dir/min_heap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/packman.dir/min_heap.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romens/Documents/graphic/LuckPackMan/min_heap.cpp -o CMakeFiles/packman.dir/min_heap.cpp.s

CMakeFiles/packman.dir/resource_manager.cc.o: CMakeFiles/packman.dir/flags.make
CMakeFiles/packman.dir/resource_manager.cc.o: ../resource_manager.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romens/Documents/graphic/LuckPackMan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/packman.dir/resource_manager.cc.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/packman.dir/resource_manager.cc.o -c /Users/romens/Documents/graphic/LuckPackMan/resource_manager.cc

CMakeFiles/packman.dir/resource_manager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/packman.dir/resource_manager.cc.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romens/Documents/graphic/LuckPackMan/resource_manager.cc > CMakeFiles/packman.dir/resource_manager.cc.i

CMakeFiles/packman.dir/resource_manager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/packman.dir/resource_manager.cc.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romens/Documents/graphic/LuckPackMan/resource_manager.cc -o CMakeFiles/packman.dir/resource_manager.cc.s

CMakeFiles/packman.dir/shader.cpp.o: CMakeFiles/packman.dir/flags.make
CMakeFiles/packman.dir/shader.cpp.o: ../shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romens/Documents/graphic/LuckPackMan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/packman.dir/shader.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/packman.dir/shader.cpp.o -c /Users/romens/Documents/graphic/LuckPackMan/shader.cpp

CMakeFiles/packman.dir/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/packman.dir/shader.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romens/Documents/graphic/LuckPackMan/shader.cpp > CMakeFiles/packman.dir/shader.cpp.i

CMakeFiles/packman.dir/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/packman.dir/shader.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romens/Documents/graphic/LuckPackMan/shader.cpp -o CMakeFiles/packman.dir/shader.cpp.s

CMakeFiles/packman.dir/sprite_renderer.cc.o: CMakeFiles/packman.dir/flags.make
CMakeFiles/packman.dir/sprite_renderer.cc.o: ../sprite_renderer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romens/Documents/graphic/LuckPackMan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/packman.dir/sprite_renderer.cc.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/packman.dir/sprite_renderer.cc.o -c /Users/romens/Documents/graphic/LuckPackMan/sprite_renderer.cc

CMakeFiles/packman.dir/sprite_renderer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/packman.dir/sprite_renderer.cc.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romens/Documents/graphic/LuckPackMan/sprite_renderer.cc > CMakeFiles/packman.dir/sprite_renderer.cc.i

CMakeFiles/packman.dir/sprite_renderer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/packman.dir/sprite_renderer.cc.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romens/Documents/graphic/LuckPackMan/sprite_renderer.cc -o CMakeFiles/packman.dir/sprite_renderer.cc.s

CMakeFiles/packman.dir/texture.cpp.o: CMakeFiles/packman.dir/flags.make
CMakeFiles/packman.dir/texture.cpp.o: ../texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/romens/Documents/graphic/LuckPackMan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/packman.dir/texture.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/packman.dir/texture.cpp.o -c /Users/romens/Documents/graphic/LuckPackMan/texture.cpp

CMakeFiles/packman.dir/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/packman.dir/texture.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romens/Documents/graphic/LuckPackMan/texture.cpp > CMakeFiles/packman.dir/texture.cpp.i

CMakeFiles/packman.dir/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/packman.dir/texture.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romens/Documents/graphic/LuckPackMan/texture.cpp -o CMakeFiles/packman.dir/texture.cpp.s

# Object files for target packman
packman_OBJECTS = \
"CMakeFiles/packman.dir/ScatterStrategy.cpp.o" \
"CMakeFiles/packman.dir/ScatterTopRight.cpp.o" \
"CMakeFiles/packman.dir/game.cpp.o" \
"CMakeFiles/packman.dir/ghost.cpp.o" \
"CMakeFiles/packman.dir/ghost_object.cpp.o" \
"CMakeFiles/packman.dir/glad.c.o" \
"CMakeFiles/packman.dir/main.cpp.o" \
"CMakeFiles/packman.dir/maze.cpp.o" \
"CMakeFiles/packman.dir/maze_object.cpp.o" \
"CMakeFiles/packman.dir/min_heap.cpp.o" \
"CMakeFiles/packman.dir/resource_manager.cc.o" \
"CMakeFiles/packman.dir/shader.cpp.o" \
"CMakeFiles/packman.dir/sprite_renderer.cc.o" \
"CMakeFiles/packman.dir/texture.cpp.o"

# External object files for target packman
packman_EXTERNAL_OBJECTS =

packman: CMakeFiles/packman.dir/ScatterStrategy.cpp.o
packman: CMakeFiles/packman.dir/ScatterTopRight.cpp.o
packman: CMakeFiles/packman.dir/game.cpp.o
packman: CMakeFiles/packman.dir/ghost.cpp.o
packman: CMakeFiles/packman.dir/ghost_object.cpp.o
packman: CMakeFiles/packman.dir/glad.c.o
packman: CMakeFiles/packman.dir/main.cpp.o
packman: CMakeFiles/packman.dir/maze.cpp.o
packman: CMakeFiles/packman.dir/maze_object.cpp.o
packman: CMakeFiles/packman.dir/min_heap.cpp.o
packman: CMakeFiles/packman.dir/resource_manager.cc.o
packman: CMakeFiles/packman.dir/shader.cpp.o
packman: CMakeFiles/packman.dir/sprite_renderer.cc.o
packman: CMakeFiles/packman.dir/texture.cpp.o
packman: CMakeFiles/packman.dir/build.make
packman: CMakeFiles/packman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/romens/Documents/graphic/LuckPackMan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable packman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/packman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/packman.dir/build: packman

.PHONY : CMakeFiles/packman.dir/build

CMakeFiles/packman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/packman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/packman.dir/clean

CMakeFiles/packman.dir/depend:
	cd /Users/romens/Documents/graphic/LuckPackMan/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/romens/Documents/graphic/LuckPackMan /Users/romens/Documents/graphic/LuckPackMan /Users/romens/Documents/graphic/LuckPackMan/build /Users/romens/Documents/graphic/LuckPackMan/build /Users/romens/Documents/graphic/LuckPackMan/build/CMakeFiles/packman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/packman.dir/depend

