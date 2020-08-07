cmake_minimum_required(VERSION 3.16)
project(TP2 C)

set(CMAKE_C_STANDARD 99)

add_executable(TP2 Serveur.c Client.c)
target_link_libraries(TP2 ws2_32)