# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\src"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\bin"

# Include any dependencies generated for this target.
include CMakeFiles/GameOfLife.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GameOfLife.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GameOfLife.dir/flags.make

CMakeFiles/GameOfLife.dir/gameoflife.c.obj: CMakeFiles/GameOfLife.dir/flags.make
CMakeFiles/GameOfLife.dir/gameoflife.c.obj: CMakeFiles/GameOfLife.dir/includes_C.rsp
CMakeFiles/GameOfLife.dir/gameoflife.c.obj: C:/Users/Ben/Documents/programming/Git\ Repositories/Systems\ Programming/Prog/src/gameoflife.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\bin\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/GameOfLife.dir/gameoflife.c.obj"
	C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\GameOfLife.dir\gameoflife.c.obj   -c "C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\src\gameoflife.c"

CMakeFiles/GameOfLife.dir/gameoflife.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GameOfLife.dir/gameoflife.c.i"
	C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\src\gameoflife.c" > CMakeFiles\GameOfLife.dir\gameoflife.c.i

CMakeFiles/GameOfLife.dir/gameoflife.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GameOfLife.dir/gameoflife.c.s"
	C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\src\gameoflife.c" -o CMakeFiles\GameOfLife.dir\gameoflife.c.s

# Object files for target GameOfLife
GameOfLife_OBJECTS = \
"CMakeFiles/GameOfLife.dir/gameoflife.c.obj"

# External object files for target GameOfLife
GameOfLife_EXTERNAL_OBJECTS =

GameOfLife.exe: CMakeFiles/GameOfLife.dir/gameoflife.c.obj
GameOfLife.exe: CMakeFiles/GameOfLife.dir/build.make
GameOfLife.exe: libgol/libgol.dll.a
GameOfLife.exe: CMakeFiles/GameOfLife.dir/linklibs.rsp
GameOfLife.exe: CMakeFiles/GameOfLife.dir/objects1.rsp
GameOfLife.exe: CMakeFiles/GameOfLife.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\bin\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable GameOfLife.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GameOfLife.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GameOfLife.dir/build: GameOfLife.exe

.PHONY : CMakeFiles/GameOfLife.dir/build

CMakeFiles/GameOfLife.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GameOfLife.dir\cmake_clean.cmake
.PHONY : CMakeFiles/GameOfLife.dir/clean

CMakeFiles/GameOfLife.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\src" "C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\src" "C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\bin" "C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\bin" "C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\bin\CMakeFiles\GameOfLife.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/GameOfLife.dir/depend

