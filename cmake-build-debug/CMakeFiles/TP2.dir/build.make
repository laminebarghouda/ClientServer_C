# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\lamin\CLionProjects\TP2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lamin\CLionProjects\TP2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TP2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TP2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TP2.dir/flags.make

CMakeFiles/TP2.dir/Serveur.c.obj: CMakeFiles/TP2.dir/flags.make
CMakeFiles/TP2.dir/Serveur.c.obj: CMakeFiles/TP2.dir/includes_C.rsp
CMakeFiles/TP2.dir/Serveur.c.obj: ../Serveur.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lamin\CLionProjects\TP2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TP2.dir/Serveur.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\TP2.dir\Serveur.c.obj   -c C:\Users\lamin\CLionProjects\TP2\Serveur.c

CMakeFiles/TP2.dir/Serveur.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TP2.dir/Serveur.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\lamin\CLionProjects\TP2\Serveur.c > CMakeFiles\TP2.dir\Serveur.c.i

CMakeFiles/TP2.dir/Serveur.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TP2.dir/Serveur.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\lamin\CLionProjects\TP2\Serveur.c -o CMakeFiles\TP2.dir\Serveur.c.s

CMakeFiles/TP2.dir/Client.c.obj: CMakeFiles/TP2.dir/flags.make
CMakeFiles/TP2.dir/Client.c.obj: CMakeFiles/TP2.dir/includes_C.rsp
CMakeFiles/TP2.dir/Client.c.obj: ../Client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lamin\CLionProjects\TP2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/TP2.dir/Client.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\TP2.dir\Client.c.obj   -c C:\Users\lamin\CLionProjects\TP2\Client.c

CMakeFiles/TP2.dir/Client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TP2.dir/Client.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\lamin\CLionProjects\TP2\Client.c > CMakeFiles\TP2.dir\Client.c.i

CMakeFiles/TP2.dir/Client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TP2.dir/Client.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\lamin\CLionProjects\TP2\Client.c -o CMakeFiles\TP2.dir\Client.c.s

# Object files for target TP2
TP2_OBJECTS = \
"CMakeFiles/TP2.dir/Serveur.c.obj" \
"CMakeFiles/TP2.dir/Client.c.obj"

# External object files for target TP2
TP2_EXTERNAL_OBJECTS =

TP2.exe: CMakeFiles/TP2.dir/Serveur.c.obj
TP2.exe: CMakeFiles/TP2.dir/Client.c.obj
TP2.exe: CMakeFiles/TP2.dir/build.make
TP2.exe: CMakeFiles/TP2.dir/linklibs.rsp
TP2.exe: CMakeFiles/TP2.dir/objects1.rsp
TP2.exe: CMakeFiles/TP2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\lamin\CLionProjects\TP2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable TP2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TP2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TP2.dir/build: TP2.exe

.PHONY : CMakeFiles/TP2.dir/build

CMakeFiles/TP2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TP2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TP2.dir/clean

CMakeFiles/TP2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lamin\CLionProjects\TP2 C:\Users\lamin\CLionProjects\TP2 C:\Users\lamin\CLionProjects\TP2\cmake-build-debug C:\Users\lamin\CLionProjects\TP2\cmake-build-debug C:\Users\lamin\CLionProjects\TP2\cmake-build-debug\CMakeFiles\TP2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TP2.dir/depend

