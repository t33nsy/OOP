# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\CMake\cmake-3.29.1-windows-x86_64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CMake\cmake-3.29.1-windows-x86_64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\projects\training\OOP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\projects\training\OOP\build

# Include any dependencies generated for this target.
include CMakeFiles/Sea_battle.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Sea_battle.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Sea_battle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sea_battle.dir/flags.make

CMakeFiles/Sea_battle.dir/main.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/main.cc.obj: E:/projects/training/OOP/main.cc
CMakeFiles/Sea_battle.dir/main.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Sea_battle.dir/main.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/main.cc.obj -MF CMakeFiles\Sea_battle.dir\main.cc.obj.d -o CMakeFiles\Sea_battle.dir\main.cc.obj -c E:\projects\training\OOP\main.cc

CMakeFiles/Sea_battle.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/main.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\main.cc > CMakeFiles\Sea_battle.dir\main.cc.i

CMakeFiles/Sea_battle.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/main.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\main.cc -o CMakeFiles\Sea_battle.dir\main.cc.s

CMakeFiles/Sea_battle.dir/sources/CollisionException.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/CollisionException.cc.obj: E:/projects/training/OOP/sources/CollisionException.cc
CMakeFiles/Sea_battle.dir/sources/CollisionException.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Sea_battle.dir/sources/CollisionException.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/CollisionException.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\CollisionException.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\CollisionException.cc.obj -c E:\projects\training\OOP\sources\CollisionException.cc

CMakeFiles/Sea_battle.dir/sources/CollisionException.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/CollisionException.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\CollisionException.cc > CMakeFiles\Sea_battle.dir\sources\CollisionException.cc.i

CMakeFiles/Sea_battle.dir/sources/CollisionException.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/CollisionException.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\CollisionException.cc -o CMakeFiles\Sea_battle.dir\sources\CollisionException.cc.s

CMakeFiles/Sea_battle.dir/sources/DoubleDamage.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/DoubleDamage.cc.obj: E:/projects/training/OOP/sources/DoubleDamage.cc
CMakeFiles/Sea_battle.dir/sources/DoubleDamage.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Sea_battle.dir/sources/DoubleDamage.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/DoubleDamage.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\DoubleDamage.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\DoubleDamage.cc.obj -c E:\projects\training\OOP\sources\DoubleDamage.cc

CMakeFiles/Sea_battle.dir/sources/DoubleDamage.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/DoubleDamage.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\DoubleDamage.cc > CMakeFiles\Sea_battle.dir\sources\DoubleDamage.cc.i

CMakeFiles/Sea_battle.dir/sources/DoubleDamage.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/DoubleDamage.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\DoubleDamage.cc -o CMakeFiles\Sea_battle.dir\sources\DoubleDamage.cc.s

CMakeFiles/Sea_battle.dir/sources/GameField.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/GameField.cc.obj: E:/projects/training/OOP/sources/GameField.cc
CMakeFiles/Sea_battle.dir/sources/GameField.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Sea_battle.dir/sources/GameField.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/GameField.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\GameField.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\GameField.cc.obj -c E:\projects\training\OOP\sources\GameField.cc

CMakeFiles/Sea_battle.dir/sources/GameField.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/GameField.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\GameField.cc > CMakeFiles\Sea_battle.dir\sources\GameField.cc.i

CMakeFiles/Sea_battle.dir/sources/GameField.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/GameField.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\GameField.cc -o CMakeFiles\Sea_battle.dir\sources\GameField.cc.s

CMakeFiles/Sea_battle.dir/sources/NoSkillsException.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/NoSkillsException.cc.obj: E:/projects/training/OOP/sources/NoSkillsException.cc
CMakeFiles/Sea_battle.dir/sources/NoSkillsException.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Sea_battle.dir/sources/NoSkillsException.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/NoSkillsException.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\NoSkillsException.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\NoSkillsException.cc.obj -c E:\projects\training\OOP\sources\NoSkillsException.cc

CMakeFiles/Sea_battle.dir/sources/NoSkillsException.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/NoSkillsException.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\NoSkillsException.cc > CMakeFiles\Sea_battle.dir\sources\NoSkillsException.cc.i

CMakeFiles/Sea_battle.dir/sources/NoSkillsException.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/NoSkillsException.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\NoSkillsException.cc -o CMakeFiles\Sea_battle.dir\sources\NoSkillsException.cc.s

CMakeFiles/Sea_battle.dir/sources/OutOfFieldException.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/OutOfFieldException.cc.obj: E:/projects/training/OOP/sources/OutOfFieldException.cc
CMakeFiles/Sea_battle.dir/sources/OutOfFieldException.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Sea_battle.dir/sources/OutOfFieldException.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/OutOfFieldException.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\OutOfFieldException.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\OutOfFieldException.cc.obj -c E:\projects\training\OOP\sources\OutOfFieldException.cc

CMakeFiles/Sea_battle.dir/sources/OutOfFieldException.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/OutOfFieldException.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\OutOfFieldException.cc > CMakeFiles\Sea_battle.dir\sources\OutOfFieldException.cc.i

CMakeFiles/Sea_battle.dir/sources/OutOfFieldException.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/OutOfFieldException.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\OutOfFieldException.cc -o CMakeFiles\Sea_battle.dir\sources\OutOfFieldException.cc.s

CMakeFiles/Sea_battle.dir/sources/RandomShot.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/RandomShot.cc.obj: E:/projects/training/OOP/sources/RandomShot.cc
CMakeFiles/Sea_battle.dir/sources/RandomShot.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Sea_battle.dir/sources/RandomShot.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/RandomShot.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\RandomShot.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\RandomShot.cc.obj -c E:\projects\training\OOP\sources\RandomShot.cc

CMakeFiles/Sea_battle.dir/sources/RandomShot.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/RandomShot.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\RandomShot.cc > CMakeFiles\Sea_battle.dir\sources\RandomShot.cc.i

CMakeFiles/Sea_battle.dir/sources/RandomShot.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/RandomShot.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\RandomShot.cc -o CMakeFiles\Sea_battle.dir\sources\RandomShot.cc.s

CMakeFiles/Sea_battle.dir/sources/Scanner.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/Scanner.cc.obj: E:/projects/training/OOP/sources/Scanner.cc
CMakeFiles/Sea_battle.dir/sources/Scanner.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Sea_battle.dir/sources/Scanner.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/Scanner.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\Scanner.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\Scanner.cc.obj -c E:\projects\training\OOP\sources\Scanner.cc

CMakeFiles/Sea_battle.dir/sources/Scanner.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/Scanner.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\Scanner.cc > CMakeFiles\Sea_battle.dir\sources\Scanner.cc.i

CMakeFiles/Sea_battle.dir/sources/Scanner.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/Scanner.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\Scanner.cc -o CMakeFiles\Sea_battle.dir\sources\Scanner.cc.s

CMakeFiles/Sea_battle.dir/sources/Ship.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/Ship.cc.obj: E:/projects/training/OOP/sources/Ship.cc
CMakeFiles/Sea_battle.dir/sources/Ship.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Sea_battle.dir/sources/Ship.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/Ship.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\Ship.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\Ship.cc.obj -c E:\projects\training\OOP\sources\Ship.cc

CMakeFiles/Sea_battle.dir/sources/Ship.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/Ship.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\Ship.cc > CMakeFiles\Sea_battle.dir\sources\Ship.cc.i

CMakeFiles/Sea_battle.dir/sources/Ship.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/Ship.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\Ship.cc -o CMakeFiles\Sea_battle.dir\sources\Ship.cc.s

CMakeFiles/Sea_battle.dir/sources/ShipKilled.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/ShipKilled.cc.obj: E:/projects/training/OOP/sources/ShipKilled.cc
CMakeFiles/Sea_battle.dir/sources/ShipKilled.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Sea_battle.dir/sources/ShipKilled.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/ShipKilled.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\ShipKilled.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\ShipKilled.cc.obj -c E:\projects\training\OOP\sources\ShipKilled.cc

CMakeFiles/Sea_battle.dir/sources/ShipKilled.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/ShipKilled.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\ShipKilled.cc > CMakeFiles\Sea_battle.dir\sources\ShipKilled.cc.i

CMakeFiles/Sea_battle.dir/sources/ShipKilled.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/ShipKilled.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\ShipKilled.cc -o CMakeFiles\Sea_battle.dir\sources\ShipKilled.cc.s

CMakeFiles/Sea_battle.dir/sources/ShipManager.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/ShipManager.cc.obj: E:/projects/training/OOP/sources/ShipManager.cc
CMakeFiles/Sea_battle.dir/sources/ShipManager.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Sea_battle.dir/sources/ShipManager.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/ShipManager.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\ShipManager.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\ShipManager.cc.obj -c E:\projects\training\OOP\sources\ShipManager.cc

CMakeFiles/Sea_battle.dir/sources/ShipManager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/ShipManager.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\ShipManager.cc > CMakeFiles\Sea_battle.dir\sources\ShipManager.cc.i

CMakeFiles/Sea_battle.dir/sources/ShipManager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/ShipManager.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\ShipManager.cc -o CMakeFiles\Sea_battle.dir\sources\ShipManager.cc.s

CMakeFiles/Sea_battle.dir/sources/Skill.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/Skill.cc.obj: E:/projects/training/OOP/sources/Skill.cc
CMakeFiles/Sea_battle.dir/sources/Skill.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Sea_battle.dir/sources/Skill.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/Skill.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\Skill.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\Skill.cc.obj -c E:\projects\training\OOP\sources\Skill.cc

CMakeFiles/Sea_battle.dir/sources/Skill.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/Skill.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\Skill.cc > CMakeFiles\Sea_battle.dir\sources\Skill.cc.i

CMakeFiles/Sea_battle.dir/sources/Skill.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/Skill.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\Skill.cc -o CMakeFiles\Sea_battle.dir\sources\Skill.cc.s

CMakeFiles/Sea_battle.dir/sources/SkillManager.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/SkillManager.cc.obj: E:/projects/training/OOP/sources/SkillManager.cc
CMakeFiles/Sea_battle.dir/sources/SkillManager.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Sea_battle.dir/sources/SkillManager.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/SkillManager.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\SkillManager.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\SkillManager.cc.obj -c E:\projects\training\OOP\sources\SkillManager.cc

CMakeFiles/Sea_battle.dir/sources/SkillManager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/SkillManager.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\SkillManager.cc > CMakeFiles\Sea_battle.dir\sources\SkillManager.cc.i

CMakeFiles/Sea_battle.dir/sources/SkillManager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/SkillManager.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\SkillManager.cc -o CMakeFiles\Sea_battle.dir\sources\SkillManager.cc.s

CMakeFiles/Sea_battle.dir/sources/Game.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/Game.cc.obj: E:/projects/training/OOP/sources/Game.cc
CMakeFiles/Sea_battle.dir/sources/Game.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Sea_battle.dir/sources/Game.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/Game.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\Game.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\Game.cc.obj -c E:\projects\training\OOP\sources\Game.cc

CMakeFiles/Sea_battle.dir/sources/Game.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/Game.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\Game.cc > CMakeFiles\Sea_battle.dir\sources\Game.cc.i

CMakeFiles/Sea_battle.dir/sources/Game.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/Game.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\Game.cc -o CMakeFiles\Sea_battle.dir\sources\Game.cc.s

CMakeFiles/Sea_battle.dir/sources/GameState.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/GameState.cc.obj: E:/projects/training/OOP/sources/GameState.cc
CMakeFiles/Sea_battle.dir/sources/GameState.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Sea_battle.dir/sources/GameState.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/GameState.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\GameState.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\GameState.cc.obj -c E:\projects\training\OOP\sources\GameState.cc

CMakeFiles/Sea_battle.dir/sources/GameState.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/GameState.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\GameState.cc > CMakeFiles\Sea_battle.dir\sources\GameState.cc.i

CMakeFiles/Sea_battle.dir/sources/GameState.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/GameState.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\GameState.cc -o CMakeFiles\Sea_battle.dir\sources\GameState.cc.s

CMakeFiles/Sea_battle.dir/sources/ComputerEnemy.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/ComputerEnemy.cc.obj: E:/projects/training/OOP/sources/ComputerEnemy.cc
CMakeFiles/Sea_battle.dir/sources/ComputerEnemy.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/Sea_battle.dir/sources/ComputerEnemy.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/ComputerEnemy.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\ComputerEnemy.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\ComputerEnemy.cc.obj -c E:\projects\training\OOP\sources\ComputerEnemy.cc

CMakeFiles/Sea_battle.dir/sources/ComputerEnemy.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/ComputerEnemy.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\ComputerEnemy.cc > CMakeFiles\Sea_battle.dir\sources\ComputerEnemy.cc.i

CMakeFiles/Sea_battle.dir/sources/ComputerEnemy.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/ComputerEnemy.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\ComputerEnemy.cc -o CMakeFiles\Sea_battle.dir\sources\ComputerEnemy.cc.s

CMakeFiles/Sea_battle.dir/sources/TerminalInputHandler.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/TerminalInputHandler.cc.obj: E:/projects/training/OOP/sources/TerminalInputHandler.cc
CMakeFiles/Sea_battle.dir/sources/TerminalInputHandler.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/Sea_battle.dir/sources/TerminalInputHandler.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/TerminalInputHandler.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\TerminalInputHandler.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\TerminalInputHandler.cc.obj -c E:\projects\training\OOP\sources\TerminalInputHandler.cc

CMakeFiles/Sea_battle.dir/sources/TerminalInputHandler.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/TerminalInputHandler.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\TerminalInputHandler.cc > CMakeFiles\Sea_battle.dir\sources\TerminalInputHandler.cc.i

CMakeFiles/Sea_battle.dir/sources/TerminalInputHandler.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/TerminalInputHandler.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\TerminalInputHandler.cc -o CMakeFiles\Sea_battle.dir\sources\TerminalInputHandler.cc.s

CMakeFiles/Sea_battle.dir/sources/Tracker.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/Tracker.cc.obj: E:/projects/training/OOP/sources/Tracker.cc
CMakeFiles/Sea_battle.dir/sources/Tracker.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/Sea_battle.dir/sources/Tracker.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/Tracker.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\Tracker.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\Tracker.cc.obj -c E:\projects\training\OOP\sources\Tracker.cc

CMakeFiles/Sea_battle.dir/sources/Tracker.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/Tracker.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\Tracker.cc > CMakeFiles\Sea_battle.dir\sources\Tracker.cc.i

CMakeFiles/Sea_battle.dir/sources/Tracker.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/Tracker.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\Tracker.cc -o CMakeFiles\Sea_battle.dir\sources\Tracker.cc.s

CMakeFiles/Sea_battle.dir/sources/TerminalField.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/TerminalField.cc.obj: E:/projects/training/OOP/sources/TerminalField.cc
CMakeFiles/Sea_battle.dir/sources/TerminalField.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/Sea_battle.dir/sources/TerminalField.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/TerminalField.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\TerminalField.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\TerminalField.cc.obj -c E:\projects\training\OOP\sources\TerminalField.cc

CMakeFiles/Sea_battle.dir/sources/TerminalField.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/TerminalField.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\TerminalField.cc > CMakeFiles\Sea_battle.dir\sources\TerminalField.cc.i

CMakeFiles/Sea_battle.dir/sources/TerminalField.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/TerminalField.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\TerminalField.cc -o CMakeFiles\Sea_battle.dir\sources\TerminalField.cc.s

CMakeFiles/Sea_battle.dir/sources/FileHandler.cc.obj: CMakeFiles/Sea_battle.dir/flags.make
CMakeFiles/Sea_battle.dir/sources/FileHandler.cc.obj: E:/projects/training/OOP/sources/FileHandler.cc
CMakeFiles/Sea_battle.dir/sources/FileHandler.cc.obj: CMakeFiles/Sea_battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/Sea_battle.dir/sources/FileHandler.cc.obj"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sea_battle.dir/sources/FileHandler.cc.obj -MF CMakeFiles\Sea_battle.dir\sources\FileHandler.cc.obj.d -o CMakeFiles\Sea_battle.dir\sources\FileHandler.cc.obj -c E:\projects\training\OOP\sources\FileHandler.cc

CMakeFiles/Sea_battle.dir/sources/FileHandler.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sea_battle.dir/sources/FileHandler.cc.i"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\training\OOP\sources\FileHandler.cc > CMakeFiles\Sea_battle.dir\sources\FileHandler.cc.i

CMakeFiles/Sea_battle.dir/sources/FileHandler.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sea_battle.dir/sources/FileHandler.cc.s"
	E:\msys2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\projects\training\OOP\sources\FileHandler.cc -o CMakeFiles\Sea_battle.dir\sources\FileHandler.cc.s

# Object files for target Sea_battle
Sea_battle_OBJECTS = \
"CMakeFiles/Sea_battle.dir/main.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/CollisionException.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/DoubleDamage.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/GameField.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/NoSkillsException.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/OutOfFieldException.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/RandomShot.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/Scanner.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/Ship.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/ShipKilled.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/ShipManager.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/Skill.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/SkillManager.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/Game.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/GameState.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/ComputerEnemy.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/TerminalInputHandler.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/Tracker.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/TerminalField.cc.obj" \
"CMakeFiles/Sea_battle.dir/sources/FileHandler.cc.obj"

# External object files for target Sea_battle
Sea_battle_EXTERNAL_OBJECTS =

Sea_battle.exe: CMakeFiles/Sea_battle.dir/main.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/CollisionException.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/DoubleDamage.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/GameField.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/NoSkillsException.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/OutOfFieldException.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/RandomShot.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/Scanner.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/Ship.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/ShipKilled.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/ShipManager.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/Skill.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/SkillManager.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/Game.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/GameState.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/ComputerEnemy.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/TerminalInputHandler.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/Tracker.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/TerminalField.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/sources/FileHandler.cc.obj
Sea_battle.exe: CMakeFiles/Sea_battle.dir/build.make
Sea_battle.exe: CMakeFiles/Sea_battle.dir/linkLibs.rsp
Sea_battle.exe: CMakeFiles/Sea_battle.dir/objects1.rsp
Sea_battle.exe: CMakeFiles/Sea_battle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\projects\training\OOP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Linking CXX executable Sea_battle.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Sea_battle.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sea_battle.dir/build: Sea_battle.exe
.PHONY : CMakeFiles/Sea_battle.dir/build

CMakeFiles/Sea_battle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Sea_battle.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Sea_battle.dir/clean

CMakeFiles/Sea_battle.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\projects\training\OOP E:\projects\training\OOP E:\projects\training\OOP\build E:\projects\training\OOP\build E:\projects\training\OOP\build\CMakeFiles\Sea_battle.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Sea_battle.dir/depend

