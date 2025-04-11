cmake_minimum_required(VERSION 3.10)

project(lab2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab2
    src/main.cpp
    src/TaskExecutor.cpp
    src/All_CPP/ReverseNumber.cpp
    src/All_CPP/QuickSort.cpp
    src/All_CPP/PathFinder.cpp
    src/Tests/TestRunner.cpp
    src/Tests/Functional/ReverseNumberFunctionalTests.cpp
    src/Tests/Functional/QuickSortFunctionalTests.cpp
    src/Tests/Functional/PathFinderFunctionalTests.cpp
    src/Tests/Logical/ReverseNumberLogicalTests.cpp
    src/Tests/Logical/QuickSortLogicalTests.cpp
    src/Tests/Logical/PathFinderLogicalTests.cpp
)

target_include_directories(lab2 PUBLIC
    ${CMAKE_SOURCE_DIR}/inc
    ${CMAKE_SOURCE_DIR}/inc/All_CPP
    ${CMAKE_SOURCE_DIR}/inc/Tests
    ${CMAKE_SOURCE_DIR}/inc/Tests/Functional
    ${CMAKE_SOURCE_DIR}/inc/Tests/Logical
)