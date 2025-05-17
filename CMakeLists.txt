cmake_minimum_required(VERSION 3.10)
project(HTTPServer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include header files
include_directories(include)

# Source files (automatically collect all .cpp files in src/)
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create the executable
add_executable(server ${SOURCES})
