cmake_minimum_required(VERSION 3.20)
project(Laba5bVectors C)

set(CMAKE_C_STANDARD 11)

add_executable(Laba5bVectors main.c)

add_subdirectory(libs)

target_link_libraries(Laba5bVectors libs)
