cmake_minimum_required(VERSION 3.1)
project(malloc)

set(CMAKE_CXX_STANDARD 14)

add_executable(malloc_vs_new cxx/malloc_vs_new.cpp)
