cmake_minimum_required(VERSION 3.20)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

set (CMAKE_EXPORT_COMPILE_COMMANDS 1)

set (CMAKE_CXX_STANDARD 17)

# Project Name
project(LogiWheelEventHandler)
# Add executable
add_executable(demo demo.cpp)
# Include directories
target_include_directories(demo PRIVATE .)
