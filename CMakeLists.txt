cmake_minimum_required(VERSION 2.8.11)
project(MyString)
set(MODULE_NAME String)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/.travis/cmake)

include_directories(include)
add_subdirectory(src)

add_executable(${MODULE_NAME}
    ./src/main.cpp
)

target_link_libraries(${MODULE_NAME}
	MyString_lib
)

add_subdirectory(test)
