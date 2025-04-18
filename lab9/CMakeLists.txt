cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME PongGame)
project("${PROJECT_NAME}")

# Настройки стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Для SFML 3.0 (динамическая линковка)
add_definitions(-DSFML_DYNAMIC)

# Пути к заголовочным файлам
include_directories("inc/")
include_directories("ext/SFML/include/")

# Пути к библиотекам
link_directories("ext/SFML/lib/")

# Список исходных файлов
set(SOURCES
    "src/main.cpp"
    "src/PongGame.cpp"
)

# Список заголовочных файлов
set(HEADERS
    "inc/PongGame.h"
)

# Создание исполняемого файла
add_executable("${PROJECT_NAME}" 
    ${SOURCES}
    ${HEADERS}
)

# Линковка для SFML 3.0
target_link_libraries("${PROJECT_NAME}"
    sfml-graphics
    sfml-window
    sfml-system
)

# Дополнительные библиотеки для Windows
if(WIN32)
    target_link_libraries("${PROJECT_NAME}"
        opengl32
        freetype
        winmm
        gdi32
    )
    
    # Копирование DLL файлов (для динамической линковки)
    if(NOT SFML_STATIC)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${CMAKE_SOURCE_DIR}/ext/SFML/bin/sfml-graphics-2.dll"
                $<TARGET_FILE_DIR:${PROJECT_NAME}>
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${CMAKE_SOURCE_DIR}/ext/SFML/bin/sfml-window-2.dll"
                $<TARGET_FILE_DIR:${PROJECT_NAME}>
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${CMAKE_SOURCE_DIR}/ext/SFML/bin/sfml-system-2.dll"
                $<TARGET_FILE_DIR:${PROJECT_NAME}>
        )
    endif()
endif()