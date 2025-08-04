cmake_minimum_required(VERSION 3.10)
# Project Name
project(LogiWheelEventHandler)
# Add executable
add_executable(demo example.cpp)
# Include directories
target_include_directories(demo PRIVATE .)
