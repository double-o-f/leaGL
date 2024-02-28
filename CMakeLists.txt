cmake_minimum_required(VERSION 3.28.3)

project(gawDL)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(gawDL src/main.c src/shadercomp.c src/glad.c src/windowinit.c src/tri.c)

target_include_directories(gawDL PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include /usr/include)

target_link_libraries(gawDL libglfw.so)
