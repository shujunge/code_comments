project(multiloc)

add_subdirectory(./googletest)
set(LIBRARIES test pthread)

set(SOURCE_FILES main_test.cpp)
add_executable(multiloc_tests ${SOURCE_FILES})


