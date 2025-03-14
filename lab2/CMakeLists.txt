cmake_minimum_required(VERSION 3.10)

project(lab2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab2
    src/main.cpp
    src/TaskExecutor.cpp
    src/scripts/ReverseNumber.cpp
    src/scripts/QuickSort.cpp
    src/scripts/PathFinder.cpp
    src/tests/TestRunner.cpp
    src/tests/Functional/ReverseNumberFunctionalTests.cpp
    src/tests/Functional/QuickSortFunctionalTests.cpp
    src/tests/Functional/PathFinderFunctionalTests.cpp
    src/tests/Logical/ReverseNumberLogicalTests.cpp
    src/tests/Logical/QuickSortLogicalTests.cpp
    src/tests/Logical/PathFinderLogicalTests.cpp
)

target_include_directories(lab2 PUBLIC
    ${CMAKE_SOURCE_DIR}/inc
    ${CMAKE_SOURCE_DIR}/inc/scripts
    ${CMAKE_SOURCE_DIR}/inc/tests
    ${CMAKE_SOURCE_DIR}/inc/tests/Functional
    ${CMAKE_SOURCE_DIR}/inc/tests/Logical
)