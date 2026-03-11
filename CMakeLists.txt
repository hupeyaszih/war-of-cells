cmake_minimum_required(VERSION 3.16)

project(war-of-cells LANGUAGES C)

set(CMAKE_C\_STANDARD 11)
set(CMAKE_C\_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED)

add_executable(war-of-cells
    src/main.c
    src/renderer.c
)

target_link_libraries(war-of-cells PRIVATE SDL2::SDL2)

target_include_directories(war-of-cells
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
