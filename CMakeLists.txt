cmake_minimum_required(VERSION 3.28)
project(littlecli)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/console.cpp
        src/inputhandler.cpp
        src/command.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE includes)