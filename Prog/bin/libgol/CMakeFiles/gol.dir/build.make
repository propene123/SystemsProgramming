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
include libgol/CMakeFiles/gol.dir/depend.make

# Include the progress variables for this target.
include libgol/CMakeFiles/gol.dir/progress.make

# Include the compile flags for this target's objects.
include libgol/CMakeFiles/gol.dir/flags.make

libgol/CMakeFiles/gol.dir/gol.c.obj: libgol/CMakeFiles/gol.dir/flags.make
libgol/CMakeFiles/gol.dir/gol.c.obj: C:/Users/Ben/Documents/programming/Git\ Repositories/Systems\ Programming/Prog/src/libgol/gol.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\bin\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object libgol/CMakeFiles/gol.dir/gol.c.obj"
	cd /d "C:\Users\Ben\DOCUME~1\programming\Git Repositories\Systems Programming\Prog\bin\libgol" && C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\gol.dir\gol.c.obj   -c "C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\src\libgol\gol.c"

libgol/CMakeFiles/gol.dir/gol.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gol.dir/gol.c.i"
	cd /d "C:\Users\Ben\DOCUME~1\programming\Git Repositories\Systems Programming\Prog\bin\libgol" && C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\src\libgol\gol.c" > CMakeFiles\gol.dir\gol.c.i

libgol/CMakeFiles/gol.dir/gol.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gol.dir/gol.c.s"
	cd /d "C:\Users\Ben\DOCUME~1\programming\Git Repositories\Systems Programming\Prog\bin\libgol" && C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\src\libgol\gol.c" -o CMakeFiles\gol.dir\gol.c.s

# Object files for target gol
gol_OBJECTS = \
"CMakeFiles/gol.dir/gol.c.obj"

# External object files for target gol
gol_EXTERNAL_OBJECTS =

libgol/libgol.dll: libgol/CMakeFiles/gol.dir/gol.c.obj
libgol/libgol.dll: libgol/CMakeFiles/gol.dir/build.make
libgol/libgol.dll: libgol/CMakeFiles/gol.dir/linklibs.rsp
libgol/libgol.dll: libgol/CMakeFiles/gol.dir/objects1.rsp
libgol/libgol.dll: libgol/CMakeFiles/gol.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\bin\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libgol.dll"
	cd /d "C:\Users\Ben\DOCUME~1\programming\Git Repositories\Systems Programming\Prog\bin\libgol" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gol.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libgol/CMakeFiles/gol.dir/build: libgol/libgol.dll

.PHONY : libgol/CMakeFiles/gol.dir/build

libgol/CMakeFiles/gol.dir/clean:
	cd /d "C:\Users\Ben\DOCUME~1\programming\Git Repositories\Systems Programming\Prog\bin\libgol" && $(CMAKE_COMMAND) -P CMakeFiles\gol.dir\cmake_clean.cmake
.PHONY : libgol/CMakeFiles/gol.dir/clean

libgol/CMakeFiles/gol.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\src" "C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\src\libgol" "C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\bin" "C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\bin\libgol" "C:\Users\Ben\Documents\programming\Git Repositories\Systems Programming\Prog\bin\libgol\CMakeFiles\gol.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : libgol/CMakeFiles/gol.dir/depend

