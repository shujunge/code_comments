cmake_minimum_required(VERSION 3.8)
project(zf)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(./googletest)

set(LIBRARIES test pthread)
set(SOURCE_FILES main_test.cpp)
add_executable(test_out ${SOURCE_FILES})
target_link_libraries(test_out gtest gtest_main)

set(SOURCE_FILES main.cpp)
add_executable(out ${SOURCE_FILES})

