cmake_minimum_required(VERSION 3.15)
project(AgriTopia VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output binary to build/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/plant.cpp
    src/game.cpp
)

add_executable(AgriTopia ${SOURCES})

# Compiler warnings
if (MSVC)
    target_compile_options(AgriTopia PRIVATE /W4)
else()
    target_compile_options(AgriTopia PRIVATE -Wall -Wextra -Wpedantic)
endif()
