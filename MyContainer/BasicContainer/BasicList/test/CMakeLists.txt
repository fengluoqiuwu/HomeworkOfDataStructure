cmake_minimum_required(VERSION 3.27)

project(BASIC_LIST_TEST C CXX)
set(CMAKE_CXX_STANDARD 26)

add_executable(BASIC_LIST_TEST
        test.cpp
        testBasicArrayList.cpp
#        testLinkedListNode.cpp
#        testBasicLinkedList.cpp
#        ../BasicLinkedList.cpp
)