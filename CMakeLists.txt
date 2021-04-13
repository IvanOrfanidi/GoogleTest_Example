# Version CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(main)

# Directory googletest
if(TEST)
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/googletest")
endif()

# Options
set(CMAKE_CXX_STANDARD 11)

# Source files
set(SOURCES
    source/main.cpp
    source/equal.cpp
    source/sum.cpp
    include/min.h
    include/less_than_zero.h
)

# Source tests files
set(TEST_SOURCES
    test/source/test_equal.cpp
    test/source/test_sum.cpp
    test/source/test_min.cpp
    test/source/test_less_than_zero.cpp
    source/equal.cpp
    source/sum.cpp
    include/min.h
    include/less_than_zero.h
)

# Include directories
if(TEST)
    include_directories("${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include")
endif()
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

# Set build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# Compiling target
add_executable(${PROJECT_NAME} ${SOURCES})

if(TEST)
    # Compiling target for tests
    add_executable(${PROJECT_NAME}_tests ${TEST_SOURCES})

    # Link target with gtest
    target_link_libraries(${PROJECT_NAME}_tests
        gtest
        gtest_main
    )
endif()