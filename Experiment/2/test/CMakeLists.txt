cmake_minimum_required(VERSION 3.27)

project(DATA_STRUCTURE C CXX)
set(CMAKE_CXX_STANDARD 26)

add_executable(EXPERIMENT_2
        test.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../Node.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../BinaryTree.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../BinaryTreeTools.cpp
)