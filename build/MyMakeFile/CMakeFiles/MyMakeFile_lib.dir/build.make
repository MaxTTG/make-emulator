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
CMAKE_SOURCE_DIR = /root/make-emulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/make-emulator/build

# Include any dependencies generated for this target.
include MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/progress.make

# Include the compile flags for this target's objects.
include MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/flags.make

MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/makefile.cpp.o: MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/flags.make
MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/makefile.cpp.o: ../MyMakeFile/makefile.cpp
MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/makefile.cpp.o: MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/make-emulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/makefile.cpp.o"
	cd /root/make-emulator/build/MyMakeFile && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/makefile.cpp.o -MF CMakeFiles/MyMakeFile_lib.dir/makefile.cpp.o.d -o CMakeFiles/MyMakeFile_lib.dir/makefile.cpp.o -c /root/make-emulator/MyMakeFile/makefile.cpp

MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/makefile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMakeFile_lib.dir/makefile.cpp.i"
	cd /root/make-emulator/build/MyMakeFile && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/make-emulator/MyMakeFile/makefile.cpp > CMakeFiles/MyMakeFile_lib.dir/makefile.cpp.i

MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/makefile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMakeFile_lib.dir/makefile.cpp.s"
	cd /root/make-emulator/build/MyMakeFile && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/make-emulator/MyMakeFile/makefile.cpp -o CMakeFiles/MyMakeFile_lib.dir/makefile.cpp.s

# Object files for target MyMakeFile_lib
MyMakeFile_lib_OBJECTS = \
"CMakeFiles/MyMakeFile_lib.dir/makefile.cpp.o"

# External object files for target MyMakeFile_lib
MyMakeFile_lib_EXTERNAL_OBJECTS =

MyMakeFile/libMyMakeFile_lib.a: MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/makefile.cpp.o
MyMakeFile/libMyMakeFile_lib.a: MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/build.make
MyMakeFile/libMyMakeFile_lib.a: MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/make-emulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libMyMakeFile_lib.a"
	cd /root/make-emulator/build/MyMakeFile && $(CMAKE_COMMAND) -P CMakeFiles/MyMakeFile_lib.dir/cmake_clean_target.cmake
	cd /root/make-emulator/build/MyMakeFile && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyMakeFile_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/build: MyMakeFile/libMyMakeFile_lib.a
.PHONY : MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/build

MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/clean:
	cd /root/make-emulator/build/MyMakeFile && $(CMAKE_COMMAND) -P CMakeFiles/MyMakeFile_lib.dir/cmake_clean.cmake
.PHONY : MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/clean

MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/depend:
	cd /root/make-emulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/make-emulator /root/make-emulator/MyMakeFile /root/make-emulator/build /root/make-emulator/build/MyMakeFile /root/make-emulator/build/MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : MyMakeFile/CMakeFiles/MyMakeFile_lib.dir/depend

