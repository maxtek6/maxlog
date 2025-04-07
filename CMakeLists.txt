cmake_minimum_required(VERSION 3.15)

# Project name
project(maxlog)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add interface library
add_library(maxlog INTERFACE)
target_include_directories(
    maxlog 
    INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR})

# Add the executable
add_executable(maxlog_sample maxlog_sample.cpp)
target_link_libraries(maxlog_sample maxlog)
target_compile_options(maxlog_sample PRIVATE -Wall -Wextra -pedantic -Werror)