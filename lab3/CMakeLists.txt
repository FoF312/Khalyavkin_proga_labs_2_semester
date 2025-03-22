cmake_minimum_required(VERSION 3.10)

project(lab3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab3
    src/main.cpp
    src/TaskExecutor.cpp
    src/scripts/Cube.cpp
    src/tests/TestRunner.cpp
    src/tests/Functional/CubeFunctionalTests.cpp
    src/tests/Logical/CubeLogicalTests.cpp
)

target_include_directories(lab3 PUBLIC
    ${CMAKE_SOURCE_DIR}/inc
    ${CMAKE_SOURCE_DIR}/inc/scripts
    ${CMAKE_SOURCE_DIR}/inc/tests
    ${CMAKE_SOURCE_DIR}/inc/tests/Functional
    ${CMAKE_SOURCE_DIR}/inc/tests/Logical
)