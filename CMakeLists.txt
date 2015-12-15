cmake_minimum_required(VERSION 3.3)
project(DataStructures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BTNode.h BSTree.h Link.h LinkedList.h ArrayPrentPointerTree.h LinkedMap.h)
add_executable(DataStructures ${SOURCE_FILES})