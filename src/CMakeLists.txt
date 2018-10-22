cmake_minimum_required(VERSION 2.8.11)
project(MyString)

set(MODULE_NAME MyString)

set(CMAKE_CXX_STANDARD 14)

#include_directories(../include)


set(SOURCE_FILES MyString/MyString.cpp)


add_library(${MODULE_NAME} STATIC ${SOURCE_FILES})
#add_executable(MyString ${SOURCE_FILES})
