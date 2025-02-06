cmake_minimum_required(VERSION 3.10)
project(lab1)

set(SOURCES
    src/main.cpp
    src/Containers/CircularDoublyLinkedList.cpp
)

set(HEADERS
    inc/Containers/CircularDoublyLinkedList.h
)

add_executable(lab1_executable ${SOURCES} ${HEADERS})

target_include_directories(lab1_executable PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/inc")


