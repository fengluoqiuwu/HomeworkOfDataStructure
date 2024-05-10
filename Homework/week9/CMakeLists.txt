cmake_minimum_required(VERSION 3.27)

project(WEEK9 C CXX)
set(CMAKE_CXX_STANDARD 26)
add_executable(WEEK9
        test.cpp
        work.cpp
)

target_include_directories(WEEK9
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../MyContainer/Tree/BasicBinaryTree
)
