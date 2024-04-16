cmake_minimum_required(VERSION 3.27)

project(BASIC_LIST_TEST C CXX)
set(CMAKE_CXX_STANDARD 26)

add_executable(BASIC_LIST_TEST
        test_BasicArrayList.cpp
)

target_include_directories(BASIC_LIST_TEST
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..
)