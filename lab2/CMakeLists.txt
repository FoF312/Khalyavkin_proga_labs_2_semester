cmake_minimum_required(VERSION 3.10)
project(lab2)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем папку с заголовочными файлами
include_directories(${CMAKE_SOURCE_DIR}/inc)

# Добавляем исходные файлы
set(SOURCES
    src/main.cpp
    src/scripts/StringLength.cpp
    src/scripts/QuickSort.cpp
    src/scripts/PathFinder.cpp
    src/scripts/Utils.cpp
    src/tests/TestRunner.cpp
)

# Создаем исполняемый файл
add_executable(lab2 ${SOURCES})