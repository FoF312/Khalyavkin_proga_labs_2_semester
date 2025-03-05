cmake_minimum_required(VERSION 3.10)
project(lab1)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем папку с заголовочными файлами
include_directories(${CMAKE_SOURCE_DIR}/inc)

# Добавляем исходные файлы
set(SOURCES
    src/main.cpp
    src/TestRunner.cpp
    src/Containers/CircularDoublyLinkedList.cpp
    src/Tests/Functional/AppendTest.cpp
    src/Tests/Functional/RemovePrimesTest.cpp
    src/Tests/Functional/SortTest.cpp
    src/Tests/Functional/CountEndingWith2Or4Test.cpp
    src/Tests/Logical/LogicAppendTest.cpp
    src/Tests/Logical/LogicRemovePrimesTest.cpp
    src/Tests/Logical/LogicSortingTest.cpp
)

# Создаем исполняемый файл
add_executable(lab1 ${SOURCES})