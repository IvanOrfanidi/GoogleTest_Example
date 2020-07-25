# Version CMake
cmake_minimum_required(VERSION 3.3)

# Project name
project(tests)

# Directory googletest
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/googletest")

# Option
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

# Compiler-specific options
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    add_compile_options(
        -Werror
        -Wall
        -Wextra
        -Wpedantic
        -Wcast-align
        -Wcast-qual
        -Wenum-compare
        -Wfloat-equal
        -Wnon-virtual-dtor
        -Woverloaded-virtual
        -Wredundant-decls
        -Wsign-promo
        -Wno-deprecated-declarations
    )
endif()

# Source files
set(TEST_SOURCES
    test/test_equal.cpp
    test/test_sum.cpp
    test/test_min.cpp
    test/test_counting_zeros.cpp
    src/equal.cpp
    inc/equal.h
    src/sum.cpp
    inc/sum.h
    inc/min.h
    inc/counting_zeros.h
)

# Include directories
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

# Compiling target
add_executable(${PROJECT_NAME} ${TEST_SOURCES})

# Link target
target_link_libraries(
    ${PROJECT_NAME}
    gtest
    gtest_main
)
