cmake_minimum_required(VERSION 3.21)
project(Scacchiera)

set(CMAKE_CXX_STANDARD 14)

include_directories(lib)

add_library(tabellone lib/tabellone.h src/tabellone.cpp)

add_executable(Scacchiera src/main.cpp)

target_link_libraries(Scacchiera tabellone)

