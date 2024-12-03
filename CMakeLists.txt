cmake_minimum_required(VERSION 3.14...3.22)

project(
  gex
  VERSION 1.0
  LANGUAGES CXX
)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

set(src
    src/gex/main.cc
)
source_group("" FILES ${src})

add_executable(gex ${src})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)