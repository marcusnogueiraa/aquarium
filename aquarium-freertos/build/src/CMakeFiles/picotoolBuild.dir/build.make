# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/marcus-leloq/Documentos/aquarium/aquarium-freertos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build

# Utility rule file for picotoolBuild.

# Include any custom commands dependencies for this target.
include src/CMakeFiles/picotoolBuild.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/picotoolBuild.dir/progress.make

src/CMakeFiles/picotoolBuild: src/CMakeFiles/picotoolBuild-complete

src/CMakeFiles/picotoolBuild-complete: src/picotool/src/picotoolBuild-stamp/picotoolBuild-install
src/CMakeFiles/picotoolBuild-complete: src/picotool/src/picotoolBuild-stamp/picotoolBuild-mkdir
src/CMakeFiles/picotoolBuild-complete: src/picotool/src/picotoolBuild-stamp/picotoolBuild-download
src/CMakeFiles/picotoolBuild-complete: src/picotool/src/picotoolBuild-stamp/picotoolBuild-update
src/CMakeFiles/picotoolBuild-complete: src/picotool/src/picotoolBuild-stamp/picotoolBuild-patch
src/CMakeFiles/picotoolBuild-complete: src/picotool/src/picotoolBuild-stamp/picotoolBuild-configure
src/CMakeFiles/picotoolBuild-complete: src/picotool/src/picotoolBuild-stamp/picotoolBuild-build
src/CMakeFiles/picotoolBuild-complete: src/picotool/src/picotoolBuild-stamp/picotoolBuild-install
src/CMakeFiles/picotoolBuild-complete: src/picotool/src/picotoolBuild-stamp/picotoolBuild-test
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'picotoolBuild'"
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src && /usr/bin/cmake -E make_directory /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src/CMakeFiles
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src && /usr/bin/cmake -E touch /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src/CMakeFiles/picotoolBuild-complete
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src && /usr/bin/cmake -E touch /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src/picotool/src/picotoolBuild-stamp/picotoolBuild-done

src/picotool/src/picotoolBuild-stamp/picotoolBuild-install:
.PHONY : src/picotool/src/picotoolBuild-stamp/picotoolBuild-install

src/picotool/src/picotoolBuild-stamp/picotoolBuild-build:
.PHONY : src/picotool/src/picotoolBuild-stamp/picotoolBuild-build

src/picotool/src/picotoolBuild-stamp/picotoolBuild-install:
.PHONY : src/picotool/src/picotoolBuild-stamp/picotoolBuild-install

src/picotool/src/picotoolBuild-stamp/picotoolBuild-build: src/picotool/src/picotoolBuild-stamp/picotoolBuild-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing build step for 'picotoolBuild'"
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/_deps/picotool-build && $(MAKE)

src/picotool/src/picotoolBuild-stamp/picotoolBuild-configure: src/picotool/tmp/picotoolBuild-cfgcmd.txt
src/picotool/src/picotoolBuild-stamp/picotoolBuild-configure: src/picotool/src/picotoolBuild-stamp/picotoolBuild-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Performing configure step for 'picotoolBuild'"
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/_deps/picotool-build && /usr/bin/cmake --no-warn-unused-cli -DCMAKE_MAKE_PROGRAM:FILEPATH=/usr/bin/gmake -DPICO_SDK_PATH:FILEPATH=/home/marcus-leloq/pico-sdk -DPICOTOOL_NO_LIBUSB=1 -DPICOTOOL_FLAT_INSTALL=1 -DCMAKE_INSTALL_PREFIX=/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/_deps -DCMAKE_RULE_MESSAGES=OFF -DCMAKE_INSTALL_MESSAGE=NEVER "-GUnix Makefiles" -S /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/_deps/picotool-src -B /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/_deps/picotool-build
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/_deps/picotool-build && /usr/bin/cmake -E touch /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src/picotool/src/picotoolBuild-stamp/picotoolBuild-configure

src/picotool/src/picotoolBuild-stamp/picotoolBuild-download: src/picotool/src/picotoolBuild-stamp/picotoolBuild-source_dirinfo.txt
src/picotool/src/picotoolBuild-stamp/picotoolBuild-download: src/picotool/src/picotoolBuild-stamp/picotoolBuild-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "No download step for 'picotoolBuild'"
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src && /usr/bin/cmake -E echo_append
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src && /usr/bin/cmake -E touch /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src/picotool/src/picotoolBuild-stamp/picotoolBuild-download

src/picotool/src/picotoolBuild-stamp/picotoolBuild-install: src/picotool/src/picotoolBuild-stamp/picotoolBuild-build
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Performing install step for 'picotoolBuild'"
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/_deps/picotool-build && $(MAKE) install

src/picotool/src/picotoolBuild-stamp/picotoolBuild-build:
.PHONY : src/picotool/src/picotoolBuild-stamp/picotoolBuild-build

src/picotool/src/picotoolBuild-stamp/picotoolBuild-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'picotoolBuild'"
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src && /usr/bin/cmake -Dcfgdir= -P /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src/picotool/tmp/picotoolBuild-mkdirs.cmake
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src && /usr/bin/cmake -E touch /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src/picotool/src/picotoolBuild-stamp/picotoolBuild-mkdir

src/picotool/src/picotoolBuild-stamp/picotoolBuild-patch: src/picotool/src/picotoolBuild-stamp/picotoolBuild-patch-info.txt
src/picotool/src/picotoolBuild-stamp/picotoolBuild-patch: src/picotool/src/picotoolBuild-stamp/picotoolBuild-update
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'picotoolBuild'"
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src && /usr/bin/cmake -E echo_append
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src && /usr/bin/cmake -E touch /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src/picotool/src/picotoolBuild-stamp/picotoolBuild-patch

src/picotool/src/picotoolBuild-stamp/picotoolBuild-test: src/picotool/src/picotoolBuild-stamp/picotoolBuild-install
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Performing test step for 'picotoolBuild'"
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/_deps/picotool-build && /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/_deps/picotool/picotool version 2.1.1
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/_deps/picotool-build && /usr/bin/cmake -E touch /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src/picotool/src/picotoolBuild-stamp/picotoolBuild-test

src/picotool/src/picotoolBuild-stamp/picotoolBuild-install:
.PHONY : src/picotool/src/picotoolBuild-stamp/picotoolBuild-install

src/picotool/src/picotoolBuild-stamp/picotoolBuild-update: src/picotool/src/picotoolBuild-stamp/picotoolBuild-update-info.txt
src/picotool/src/picotoolBuild-stamp/picotoolBuild-update: src/picotool/src/picotoolBuild-stamp/picotoolBuild-download
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "No update step for 'picotoolBuild'"
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src && /usr/bin/cmake -E echo_append
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src && /usr/bin/cmake -E touch /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src/picotool/src/picotoolBuild-stamp/picotoolBuild-update

picotoolBuild: src/CMakeFiles/picotoolBuild
picotoolBuild: src/CMakeFiles/picotoolBuild-complete
picotoolBuild: src/picotool/src/picotoolBuild-stamp/picotoolBuild-build
picotoolBuild: src/picotool/src/picotoolBuild-stamp/picotoolBuild-configure
picotoolBuild: src/picotool/src/picotoolBuild-stamp/picotoolBuild-download
picotoolBuild: src/picotool/src/picotoolBuild-stamp/picotoolBuild-install
picotoolBuild: src/picotool/src/picotoolBuild-stamp/picotoolBuild-mkdir
picotoolBuild: src/picotool/src/picotoolBuild-stamp/picotoolBuild-patch
picotoolBuild: src/picotool/src/picotoolBuild-stamp/picotoolBuild-test
picotoolBuild: src/picotool/src/picotoolBuild-stamp/picotoolBuild-update
picotoolBuild: src/CMakeFiles/picotoolBuild.dir/build.make
.PHONY : picotoolBuild

# Rule to build all files generated by this target.
src/CMakeFiles/picotoolBuild.dir/build: picotoolBuild
.PHONY : src/CMakeFiles/picotoolBuild.dir/build

src/CMakeFiles/picotoolBuild.dir/clean:
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src && $(CMAKE_COMMAND) -P CMakeFiles/picotoolBuild.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/picotoolBuild.dir/clean

src/CMakeFiles/picotoolBuild.dir/depend:
	cd /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marcus-leloq/Documentos/aquarium/aquarium-freertos /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/src /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src /home/marcus-leloq/Documentos/aquarium/aquarium-freertos/build/src/CMakeFiles/picotoolBuild.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/picotoolBuild.dir/depend

