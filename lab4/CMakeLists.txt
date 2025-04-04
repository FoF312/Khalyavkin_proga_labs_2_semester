cmake_minimum_required(VERSION 3.10)

# Название проекта
project(lab4)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление исполняемого файла
add_executable(lab4
    src/main.cpp
    src/scripts/BigInt.cpp
    src/tests/TestRunner.cpp
    src/tests/Functional/BigIntFunctionalTests.cpp
    src/tests/Logical/BigIntLogicalTests.cpp
)

target_include_directories(lab4 PUBLIC
    ${CMAKE_SOURCE_DIR}/inc
    ${CMAKE_SOURCE_DIR}/inc/scripts
    ${CMAKE_SOURCE_DIR}/inc/tests
    ${CMAKE_SOURCE_DIR}/inc/tests/Functional
    ${CMAKE_SOURCE_DIR}/inc/tests/Logical
)