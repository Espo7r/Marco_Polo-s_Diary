cmake_minimum_required(VERSION 4.3)

project(Marco_Polo_s_Diary C)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

add_executable(Marco_Polo_s_Diary main.c)

target_include_directories(Marco_Polo_s_Diary PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_directories(Marco_Polo_s_Diary PRIVATE ${GTK4_LIBRARY_DIRS})
target_link_libraries(Marco_Polo_s_Diary PRIVATE ${GTK4_LIBRARIES})
target_compile_options(Marco_Polo_s_Diary PRIVATE ${GTK4_CFLAGS_OTHER})