# 1. Minimalna wymagana wersja programu CMake
cmake_minimum_required(VERSION 3.10)

# 2. Nazwa Twojego projektu i używany język (CXX oznacza C++)
project(GO-game CXX)

# 3. Wybór standardu języka C++ (dobrą praktyką jest używanie minimum C++17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 4. Lista plików źródłowych (.cpp)
set(SOURCES
    src/main.cpp
)

# 5. Stworzenie pliku wykonywalnego (programu) z plików źródłowych
add_executable(${PROJECT_NAME} ${SOURCES})

# 6. Poinformowanie kompilatora, gdzie ma szukać plików nagłówkowych (.hpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)