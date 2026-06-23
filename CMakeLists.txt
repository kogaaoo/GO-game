cmake_minimum_required(VERSION 3.10)

project(GoGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include/GO-game)

set(SOURCES
    src/main.cpp
    src/Board.cpp
    src/Player.cpp
    src/GameEngine.cpp
    src/ConsoleView.cpp
)

add_executable(GoGame ${SOURCES})