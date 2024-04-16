cmake_minimum_required(VERSION 3.27)

project(DATA_STRUCTURE C CXX)
set(CMAKE_CXX_STANDARD 26)

add_executable(EXPERIMENT_1
        test.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../Polynomial_Array.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../Polynomial_Node.cpp
        testArray.cpp
        testNode.cpp
)

target_include_directories(EXPERIMENT_1
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../MyContainer/BasicContainer/BasicList
)
