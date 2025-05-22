# Минимальная версия CMake, которую мы используем
cmake_minimum_required(VERSION 3.10.0)

# Название проекта и язык (C и C++)
project(splay_tree VERSION 0.1.0 LANGUAGES CXX)

# Указываем стандарт C++ (например, C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем исполняемый файл, собираем из указанных .cpp файлов
add_executable(splay_tree src/main.cpp src/splay_tree.cpp)

# Подключаем заголовочные файлы из папки include
include_directories(include)

# Включаем тестирование (если будешь его использовать)
enable_testing()

# Настройка CPack — генерация установочных пакетов
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)