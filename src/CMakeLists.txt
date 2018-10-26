cmake_minimum_required(VERSION 2.8.11)
project(MyString)

set(MODULE_NAME_LIB MyStringLib)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES MyString/MyString.cpp)

add_library(${MODULE_NAME_LIB} STATIC ${SOURCE_FILES})
add_library(MyString_lib ALIAS ${MODULE_NAME_LIB})
#add_executable(MyString ${SOURCE_FILES})
