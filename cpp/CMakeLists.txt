cmake_minimum_required(VERSION 3.5.1)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(graphs)
include_directories("sorting and basics")
include_directories(tests)

add_executable(cpp
        graphs/graph.cpp
        graphs/graph.h
        graphs/graph_algorithms.cpp
        graphs/graph_algorithms.h
        "sorting and basics/sorting.cpp"
        "sorting and basics/sorting.h"
        misc/shuffle.h
        tests/graph_algorithms_test.h
        tests/graph_test.h
        tests/sorting_test.h
        tests/misc_test.h
        main.cpp)
