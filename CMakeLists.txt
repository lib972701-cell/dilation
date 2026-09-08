cmake_minimum_required(VERSION 3.11)     
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(dilation)							
include_directories(includes)			

add_executable(dilation src/dilation.cpp src/main.cpp)	