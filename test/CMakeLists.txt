cmake_minimum_required(VERSION 2.8.11)
project(MyString_test)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

message(STATUS "kjin = " ${PROJECT_SOURCE_DIR})
file(GLOB TEST_FILES ${PROJECT_SOURCE_DIR}/MyString/*.cpp)

add_executable(unittest_string  unit_tests.cpp ${TEST_FILES})
target_link_libraries(unittest_string ${GTEST_LIBRARIES} MyString_lib pthread)

include(CodeCoverage)
setup_target_for_coverage(Sting_coverage unittest_string coverage)


