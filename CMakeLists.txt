cmake_minimum_required(VERSION 3.21)
project(Scacchiera)

set(CMAKE_CXX_STANDARD 14)

include_directories(lib)

add_library(tabellone lib/tabellone.h src/tabellone.cpp)

add_library(pieces lib/piece.h src/piece.cpp lib/pawn.h src/pawn.cpp lib/rook.h src/rook.cpp lib/knight.h src/knight.cpp lib/bishop.h src/bishop.cpp lib/queen.h src/queen.cpp lib/king.h src/king.cpp)

add_executable(Scacchiera src/main.cpp)

target_link_libraries(Scacchiera tabellone pieces)
