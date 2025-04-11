cmake_minimum_required(VERSION 3.10)

project(lab5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab5
    src/main.cpp
    src/MyVector/MyVector.cpp
    src/tests/TestRunner.cpp
    src/tests/Functional/MyVectorFunctionalTests.cpp
    src/tests/Logical/MyVectorLogicalTests.cpp
)

target_include_directories(lab5 PUBLIC
    ${CMAKE_SOURCE_DIR}/inc
    ${CMAKE_SOURCE_DIR}/inc/scripts
    ${CMAKE_SOURCE_DIR}/inc/tests
    ${CMAKE_SOURCE_DIR}/inc/tests/Functional
    ${CMAKE_SOURCE_DIR}/inc/tests/Logical
)