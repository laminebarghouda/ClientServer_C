cmake_minimum_required(VERSION 3.16)
project(TP2 C)

set(CMAKE_C_STANDARD 11)

add_executable(TP2 Serveur.c Client.c)
target_link_libraries(TP2 ws2_32)

add_library(thread_library SHARED IMPORTED)
set_target_properties(thread_library PROPERTIES IMPORTED_LOCATION "./Thread API/lib")
target_link_libraries(TP2 ./Thread API/dll/pthreadVC2)

include_directories("./Thread API/include")

