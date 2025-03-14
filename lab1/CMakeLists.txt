cmake_minimum_required(VERSION 3.10)

# Название проекта
project(lab1)

# Установка стандарта C++ (C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление исполняемого файла
add_executable(lab1
    src/main.cpp
    src/scripts/DoublyLinkedList.cpp
    src/tests/TestRunner.cpp
    src/tests/Functional/DoublyLinkedListFunctionalTests.cpp
    src/tests/Logical/DoublyLinkedListLogicalTests.cpp
)

# Подключение заголовочных файлов
target_include_directories(lab1 PUBLIC
    ${CMAKE_SOURCE_DIR}/inc
    ${CMAKE_SOURCE_DIR}/inc/scripts
    ${CMAKE_SOURCE_DIR}/inc/tests
    ${CMAKE_SOURCE_DIR}/inc/tests/Functional
    ${CMAKE_SOURCE_DIR}/inc/tests/Logical
)