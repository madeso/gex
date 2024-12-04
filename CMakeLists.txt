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

add_subdirectory(external)

set(em_src
    src/gex/chip8.cc
    src/gex/chip8.hh
)
set(test_src
    src/gex/chip8.test.cc
)
set(main_src
    src/gex/main.cc
)
source_group("" FILES ${em_src} ${main_src} ${test_src})

add_library(emulators STATIC ${em_src})
add_library(g::emulators ALIAS emulators)
add_executable(gex ${main_src})
add_executable(test ${test_src})

target_include_directories(emulators PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(gex PRIVATE
    g::emulators
)
target_link_libraries(test PRIVATE
    g::emulators
    external::catch
)


set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)