cmake_minimum_required(VERSION 3.28.3)

project(leaGL)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(leaGL src/main.c src/shadercomp.c src/glad.c src/windowinit.c src/tri.c)

target_include_directories(leaGL PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include /usr/include)

target_link_libraries(leaGL libglfw.so)
