
# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly

# This line must be the first line in the CMakeLists.txt file.
# ESP-IDF is designed to work with CMake 3.5 or newer.
cmake_minimum_required(VERSION 3.10)

# Use -std=c++14
set(CMAKE_CXX_STANDARD 14)

# For std::to_string (until using xtensa-gcc 8)
add_definitions(-D_GLIBCXX_USE_C99)

# Pulls in the rest of the CMake functionality to configure
# the project, discover all the components, etc.
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# The project name is used for the final binary output files
# of the app - ie myProject.elf, myProject.bin
project(esp32-mruby-test)
