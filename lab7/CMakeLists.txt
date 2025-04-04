cmake_minimum_required(VERSION 3.10)
project(VectorBoolLab)

set(CMAKE_CXX_STANDARD 17)

# Основной исполняемый файл
add_executable(VectorBoolLab
    src/main.cpp
    src/VectorBool/VectorBool.cpp
    src/Tests/TestRunner.cpp
    src/Tests/Functional/VectorBoolFunctionalTests.cpp
    src/Tests/Logical/VectorBoolLogicalTests.cpp
)

target_include_directories(VectorBoolLab PRIVATE inc)