cmake_minimum_required(VERSION 3.27)

project(WEEK11 C CXX)
set(CMAKE_CXX_STANDARD 26)
add_executable(WEEK11
        test.cpp
        work.cpp
)

target_include_directories(WEEK11
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../MyContainer/Tree/BasicBinaryTree
)
