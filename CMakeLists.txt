# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(land VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories (for header files)
include_directories(include)

# Find all .cpp files in the src directory and include the main.cpp
file(GLOB_RECURSE SOURCES
    main.cpp
    src/*.cpp
)

# Check if sources are found
if (NOT SOURCES)
    message(FATAL_ERROR "No source files found.")
endif()

# Create an executable named 'land'
add_executable(land ${SOURCES})

# Optionally link libraries if needed
# target_link_libraries(land mysqlcppconn)
