# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.12.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.12.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build"

# Include any dependencies generated for this target.
include src/CMakeFiles/meshedit.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/meshedit.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/meshedit.dir/flags.make

src/CMakeFiles/meshedit.dir/bezierPatch.cpp.o: src/CMakeFiles/meshedit.dir/flags.make
src/CMakeFiles/meshedit.dir/bezierPatch.cpp.o: ../src/bezierPatch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/meshedit.dir/bezierPatch.cpp.o"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meshedit.dir/bezierPatch.cpp.o -c "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/bezierPatch.cpp"

src/CMakeFiles/meshedit.dir/bezierPatch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshedit.dir/bezierPatch.cpp.i"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/bezierPatch.cpp" > CMakeFiles/meshedit.dir/bezierPatch.cpp.i

src/CMakeFiles/meshedit.dir/bezierPatch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshedit.dir/bezierPatch.cpp.s"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/bezierPatch.cpp" -o CMakeFiles/meshedit.dir/bezierPatch.cpp.s

src/CMakeFiles/meshedit.dir/bezierCurve.cpp.o: src/CMakeFiles/meshedit.dir/flags.make
src/CMakeFiles/meshedit.dir/bezierCurve.cpp.o: ../src/bezierCurve.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/meshedit.dir/bezierCurve.cpp.o"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meshedit.dir/bezierCurve.cpp.o -c "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/bezierCurve.cpp"

src/CMakeFiles/meshedit.dir/bezierCurve.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshedit.dir/bezierCurve.cpp.i"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/bezierCurve.cpp" > CMakeFiles/meshedit.dir/bezierCurve.cpp.i

src/CMakeFiles/meshedit.dir/bezierCurve.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshedit.dir/bezierCurve.cpp.s"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/bezierCurve.cpp" -o CMakeFiles/meshedit.dir/bezierCurve.cpp.s

src/CMakeFiles/meshedit.dir/scene.cpp.o: src/CMakeFiles/meshedit.dir/flags.make
src/CMakeFiles/meshedit.dir/scene.cpp.o: ../src/scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/meshedit.dir/scene.cpp.o"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meshedit.dir/scene.cpp.o -c "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/scene.cpp"

src/CMakeFiles/meshedit.dir/scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshedit.dir/scene.cpp.i"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/scene.cpp" > CMakeFiles/meshedit.dir/scene.cpp.i

src/CMakeFiles/meshedit.dir/scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshedit.dir/scene.cpp.s"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/scene.cpp" -o CMakeFiles/meshedit.dir/scene.cpp.s

src/CMakeFiles/meshedit.dir/camera.cpp.o: src/CMakeFiles/meshedit.dir/flags.make
src/CMakeFiles/meshedit.dir/camera.cpp.o: ../src/camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/meshedit.dir/camera.cpp.o"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meshedit.dir/camera.cpp.o -c "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/camera.cpp"

src/CMakeFiles/meshedit.dir/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshedit.dir/camera.cpp.i"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/camera.cpp" > CMakeFiles/meshedit.dir/camera.cpp.i

src/CMakeFiles/meshedit.dir/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshedit.dir/camera.cpp.s"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/camera.cpp" -o CMakeFiles/meshedit.dir/camera.cpp.s

src/CMakeFiles/meshedit.dir/light.cpp.o: src/CMakeFiles/meshedit.dir/flags.make
src/CMakeFiles/meshedit.dir/light.cpp.o: ../src/light.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/meshedit.dir/light.cpp.o"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meshedit.dir/light.cpp.o -c "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/light.cpp"

src/CMakeFiles/meshedit.dir/light.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshedit.dir/light.cpp.i"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/light.cpp" > CMakeFiles/meshedit.dir/light.cpp.i

src/CMakeFiles/meshedit.dir/light.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshedit.dir/light.cpp.s"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/light.cpp" -o CMakeFiles/meshedit.dir/light.cpp.s

src/CMakeFiles/meshedit.dir/mesh.cpp.o: src/CMakeFiles/meshedit.dir/flags.make
src/CMakeFiles/meshedit.dir/mesh.cpp.o: ../src/mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/meshedit.dir/mesh.cpp.o"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meshedit.dir/mesh.cpp.o -c "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/mesh.cpp"

src/CMakeFiles/meshedit.dir/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshedit.dir/mesh.cpp.i"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/mesh.cpp" > CMakeFiles/meshedit.dir/mesh.cpp.i

src/CMakeFiles/meshedit.dir/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshedit.dir/mesh.cpp.s"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/mesh.cpp" -o CMakeFiles/meshedit.dir/mesh.cpp.s

src/CMakeFiles/meshedit.dir/material.cpp.o: src/CMakeFiles/meshedit.dir/flags.make
src/CMakeFiles/meshedit.dir/material.cpp.o: ../src/material.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/meshedit.dir/material.cpp.o"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meshedit.dir/material.cpp.o -c "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/material.cpp"

src/CMakeFiles/meshedit.dir/material.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshedit.dir/material.cpp.i"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/material.cpp" > CMakeFiles/meshedit.dir/material.cpp.i

src/CMakeFiles/meshedit.dir/material.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshedit.dir/material.cpp.s"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/material.cpp" -o CMakeFiles/meshedit.dir/material.cpp.s

src/CMakeFiles/meshedit.dir/texture.cpp.o: src/CMakeFiles/meshedit.dir/flags.make
src/CMakeFiles/meshedit.dir/texture.cpp.o: ../src/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/meshedit.dir/texture.cpp.o"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meshedit.dir/texture.cpp.o -c "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/texture.cpp"

src/CMakeFiles/meshedit.dir/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshedit.dir/texture.cpp.i"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/texture.cpp" > CMakeFiles/meshedit.dir/texture.cpp.i

src/CMakeFiles/meshedit.dir/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshedit.dir/texture.cpp.s"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/texture.cpp" -o CMakeFiles/meshedit.dir/texture.cpp.s

src/CMakeFiles/meshedit.dir/collada.cpp.o: src/CMakeFiles/meshedit.dir/flags.make
src/CMakeFiles/meshedit.dir/collada.cpp.o: ../src/collada.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/meshedit.dir/collada.cpp.o"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meshedit.dir/collada.cpp.o -c "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/collada.cpp"

src/CMakeFiles/meshedit.dir/collada.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshedit.dir/collada.cpp.i"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/collada.cpp" > CMakeFiles/meshedit.dir/collada.cpp.i

src/CMakeFiles/meshedit.dir/collada.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshedit.dir/collada.cpp.s"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/collada.cpp" -o CMakeFiles/meshedit.dir/collada.cpp.s

src/CMakeFiles/meshedit.dir/halfEdgeMesh.cpp.o: src/CMakeFiles/meshedit.dir/flags.make
src/CMakeFiles/meshedit.dir/halfEdgeMesh.cpp.o: ../src/halfEdgeMesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/meshedit.dir/halfEdgeMesh.cpp.o"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meshedit.dir/halfEdgeMesh.cpp.o -c "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/halfEdgeMesh.cpp"

src/CMakeFiles/meshedit.dir/halfEdgeMesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshedit.dir/halfEdgeMesh.cpp.i"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/halfEdgeMesh.cpp" > CMakeFiles/meshedit.dir/halfEdgeMesh.cpp.i

src/CMakeFiles/meshedit.dir/halfEdgeMesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshedit.dir/halfEdgeMesh.cpp.s"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/halfEdgeMesh.cpp" -o CMakeFiles/meshedit.dir/halfEdgeMesh.cpp.s

src/CMakeFiles/meshedit.dir/student_code.cpp.o: src/CMakeFiles/meshedit.dir/flags.make
src/CMakeFiles/meshedit.dir/student_code.cpp.o: ../src/student_code.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/CMakeFiles/meshedit.dir/student_code.cpp.o"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meshedit.dir/student_code.cpp.o -c "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/student_code.cpp"

src/CMakeFiles/meshedit.dir/student_code.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshedit.dir/student_code.cpp.i"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/student_code.cpp" > CMakeFiles/meshedit.dir/student_code.cpp.i

src/CMakeFiles/meshedit.dir/student_code.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshedit.dir/student_code.cpp.s"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/student_code.cpp" -o CMakeFiles/meshedit.dir/student_code.cpp.s

src/CMakeFiles/meshedit.dir/meshEdit.cpp.o: src/CMakeFiles/meshedit.dir/flags.make
src/CMakeFiles/meshedit.dir/meshEdit.cpp.o: ../src/meshEdit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/CMakeFiles/meshedit.dir/meshEdit.cpp.o"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meshedit.dir/meshEdit.cpp.o -c "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/meshEdit.cpp"

src/CMakeFiles/meshedit.dir/meshEdit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshedit.dir/meshEdit.cpp.i"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/meshEdit.cpp" > CMakeFiles/meshedit.dir/meshEdit.cpp.i

src/CMakeFiles/meshedit.dir/meshEdit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshedit.dir/meshEdit.cpp.s"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/meshEdit.cpp" -o CMakeFiles/meshedit.dir/meshEdit.cpp.s

src/CMakeFiles/meshedit.dir/main.cpp.o: src/CMakeFiles/meshedit.dir/flags.make
src/CMakeFiles/meshedit.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object src/CMakeFiles/meshedit.dir/main.cpp.o"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meshedit.dir/main.cpp.o -c "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/main.cpp"

src/CMakeFiles/meshedit.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshedit.dir/main.cpp.i"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/main.cpp" > CMakeFiles/meshedit.dir/main.cpp.i

src/CMakeFiles/meshedit.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshedit.dir/main.cpp.s"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/main.cpp" -o CMakeFiles/meshedit.dir/main.cpp.s

src/CMakeFiles/meshedit.dir/png.cpp.o: src/CMakeFiles/meshedit.dir/flags.make
src/CMakeFiles/meshedit.dir/png.cpp.o: ../src/png.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object src/CMakeFiles/meshedit.dir/png.cpp.o"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meshedit.dir/png.cpp.o -c "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/png.cpp"

src/CMakeFiles/meshedit.dir/png.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshedit.dir/png.cpp.i"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/png.cpp" > CMakeFiles/meshedit.dir/png.cpp.i

src/CMakeFiles/meshedit.dir/png.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshedit.dir/png.cpp.s"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src/png.cpp" -o CMakeFiles/meshedit.dir/png.cpp.s

# Object files for target meshedit
meshedit_OBJECTS = \
"CMakeFiles/meshedit.dir/bezierPatch.cpp.o" \
"CMakeFiles/meshedit.dir/bezierCurve.cpp.o" \
"CMakeFiles/meshedit.dir/scene.cpp.o" \
"CMakeFiles/meshedit.dir/camera.cpp.o" \
"CMakeFiles/meshedit.dir/light.cpp.o" \
"CMakeFiles/meshedit.dir/mesh.cpp.o" \
"CMakeFiles/meshedit.dir/material.cpp.o" \
"CMakeFiles/meshedit.dir/texture.cpp.o" \
"CMakeFiles/meshedit.dir/collada.cpp.o" \
"CMakeFiles/meshedit.dir/halfEdgeMesh.cpp.o" \
"CMakeFiles/meshedit.dir/student_code.cpp.o" \
"CMakeFiles/meshedit.dir/meshEdit.cpp.o" \
"CMakeFiles/meshedit.dir/main.cpp.o" \
"CMakeFiles/meshedit.dir/png.cpp.o"

# External object files for target meshedit
meshedit_EXTERNAL_OBJECTS =

meshedit: src/CMakeFiles/meshedit.dir/bezierPatch.cpp.o
meshedit: src/CMakeFiles/meshedit.dir/bezierCurve.cpp.o
meshedit: src/CMakeFiles/meshedit.dir/scene.cpp.o
meshedit: src/CMakeFiles/meshedit.dir/camera.cpp.o
meshedit: src/CMakeFiles/meshedit.dir/light.cpp.o
meshedit: src/CMakeFiles/meshedit.dir/mesh.cpp.o
meshedit: src/CMakeFiles/meshedit.dir/material.cpp.o
meshedit: src/CMakeFiles/meshedit.dir/texture.cpp.o
meshedit: src/CMakeFiles/meshedit.dir/collada.cpp.o
meshedit: src/CMakeFiles/meshedit.dir/halfEdgeMesh.cpp.o
meshedit: src/CMakeFiles/meshedit.dir/student_code.cpp.o
meshedit: src/CMakeFiles/meshedit.dir/meshEdit.cpp.o
meshedit: src/CMakeFiles/meshedit.dir/main.cpp.o
meshedit: src/CMakeFiles/meshedit.dir/png.cpp.o
meshedit: src/CMakeFiles/meshedit.dir/build.make
meshedit: CGL/src/libCGL.a
meshedit: CGL/deps/glew/libglew.a
meshedit: CGL/deps/glfw/src/libglfw3.a
meshedit: /usr/local/lib/libfreetype.dylib
meshedit: /usr/local/lib/libfreetype.dylib
meshedit: src/CMakeFiles/meshedit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable ../meshedit"
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/meshedit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/meshedit.dir/build: meshedit

.PHONY : src/CMakeFiles/meshedit.dir/build

src/CMakeFiles/meshedit.dir/clean:
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" && $(CMAKE_COMMAND) -P CMakeFiles/meshedit.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/meshedit.dir/clean

src/CMakeFiles/meshedit.dir/depend:
	cd "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master" "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/src" "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build" "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src" "/Users/FeryalShoaib/Documents/LUMS/LUMS_F'18/Graphics/PA4-MeshEdit-master/build/src/CMakeFiles/meshedit.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/meshedit.dir/depend

