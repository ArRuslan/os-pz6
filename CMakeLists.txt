cmake_minimum_required(VERSION 3.28)
project(os_pz6)

set(CMAKE_CXX_STANDARD 17)

add_library(lib_sta STATIC lib.cpp)
add_library(lib_dyn MODULE lib.cpp)

#target_include_directories(lib_dyn PUBLIC ./)
#target_include_directories(lib_sta PUBLIC ./)

add_executable(test_static test_static.cpp test_all.cpp)
add_executable(test_dyn test_dynamic.cpp test_all.cpp)

target_link_libraries(test_static lib_sta)
add_dependencies(test_dyn lib_dyn)