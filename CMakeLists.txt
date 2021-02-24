cmake_minimum_required(VERSION 3.12)

project(String)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories(
    ./include
    ./tests/catch
)

set(SOURCE_FILES
   ./src/string.cpp
   ./tests/tests.cpp
   ./tests/catch/catch.cpp
)

add_executable(Tests ${SOURCE_FILES})
