cmake_minimum_required(VERSION 3.10)
project(MatrixProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/inc)
include_directories(${CMAKE_SOURCE_DIR}/src)

set(SOURCES
    src/main.cpp
    src/Matrix/Matrix.cpp
    src/Tests/Functional/MatrixFunctionalTests.cpp
    src/Tests/Logical/MatrixLogicalTests.cpp
)

add_executable(matrix_app ${SOURCES})

