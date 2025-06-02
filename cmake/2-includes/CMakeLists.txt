cmake_minimum_required(VERSION 3.10)
project(2_includes)

#target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC &{CMAKE_CURRENT_SOURCE_DIR}/testinclude)
add_executable(${CMAKE_PROJECT_NAME} main.cpp test1.hpp test2.hpp test3.hpp)
