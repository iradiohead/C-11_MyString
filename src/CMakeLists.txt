cmake_minimum_required(VERSION 3.2.2)
project(MyString)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES MyString/MyString.cpp)
add_library(MyString STATIC ${SOURCE_FILES})
#add_executable(MyString ${SOURCE_FILES})

