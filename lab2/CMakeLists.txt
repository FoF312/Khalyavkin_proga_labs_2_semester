# Минимальная требуемая версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(BFU_Labs)

# Установка стандарта C++ (C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление исполняемого файла
add_executable(lab2
    src/main.cpp
    src/TaskExecutor.cpp
    src/Tests/TestRunner.cpp
    src/scripts/StringLength.cpp
    src/scripts/QuickSort.cpp
    src/scripts/PathFinder.cpp
    src/scripts/Utils.cpp
    src/tests/Functional/StringLengthFunctionalTests.cpp
    src/tests/Functional/QuickSortFunctionalTests.cpp
    src/tests/Functional/PathFinderFunctionalTests.cpp
    src/tests/Logical/StringLengthLogicalTests.cpp
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