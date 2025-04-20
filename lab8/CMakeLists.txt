cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME sfml_sample)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Включаем FetchContent
include(FetchContent)

# Настраиваем SFML через FetchContent
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/_deps/sfml-src"
    BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/_deps/sfml-build"
)

# Настройки для статической сборки SFML
set(SFML_BUILD_AUDIO TRUE)
set(SFML_BUILD_GRAPHICS TRUE)
set(SFML_BUILD_WINDOW TRUE)
set(SFML_BUILD_SYSTEM TRUE)
set(SFML_BUILD_DOCS FALSE)
set(SFML_BUILD_EXAMPLES FALSE)
set(SFML_BUILD_TESTS FALSE)
set(SFML_BUILD_SHARED_LIBS FALSE)

# Загружаем SFML
FetchContent_MakeAvailable(SFML)

add_executable("${PROJECT_NAME}" main.cpp)

# Линкуем с SFML
target_link_libraries("${PROJECT_NAME}" PRIVATE 
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)

# Копируем DLL файлы в директорию с исполняемым файлом
add_custom_command(TARGET "${PROJECT_NAME}" POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "$<TARGET_FILE:sfml-graphics>"
    "$<TARGET_FILE:sfml-window>"
    "$<TARGET_FILE:sfml-system>"
    "$<TARGET_FILE:sfml-audio>"
    $<TARGET_FILE_DIR:${PROJECT_NAME}>
)