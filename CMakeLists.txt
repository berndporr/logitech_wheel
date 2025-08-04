cmake_minimum_required(VERSION 3.10)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()



# Project Name
project(LogiWheelEventHandler)
# Add executable
add_executable(demo example.cpp)
# Include directories
target_include_directories(demo PRIVATE .)
