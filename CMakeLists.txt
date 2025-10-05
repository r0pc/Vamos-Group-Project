cmake_minimum_required(VERSION 3.10)
project(MyCProject C)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Collect all .c source files
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.c)

# Create executable
add_executable(${PROJECT_NAME} ${SRC_FILES})