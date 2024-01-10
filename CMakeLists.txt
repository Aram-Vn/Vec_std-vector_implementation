# CMakeLists.txt

cmake_minimum_required(VERSION 3.12)
project(Vector)

#add compile_commands.json for vscode
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

# Add the source files
set(SOURCES
    src/Vec_declaration.h
    src/Vec.hpp
    src/main.cpp
)

# Create an executable
add_executable(VectorTest ${SOURCES})