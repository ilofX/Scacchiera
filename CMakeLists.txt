cmake_minimum_required(VERSION 3.16)
project(Scacchiera)

set(CMAKE_CXX_STANDARD 14)

include_directories(lib)
include_directories(replay/lib)

add_library(tabellone lib/board.h src/board.cpp src/checkHelpers.cpp)
add_library(pieces lib/piece.h src/piece.cpp lib/pawn.h src/pawn.cpp lib/rook.h src/rook.cpp lib/knight.h src/knight.cpp lib/bishop.h src/bishop.cpp lib/queen.h src/queen.cpp lib/king.h src/king.cpp)
add_library(giocatori lib/player.h src/player.cpp lib/human.h src/human.cpp lib/computer.h src/computer.cpp)
add_library(chess_IO lib/writer.h src/writer.cpp)
add_library(replay_IO replay/lib/log_reader.h replay/src/log_reader.cpp replay/lib/log_writer.h replay/src/log_writer.cpp)

add_executable(Scacchiera src/main.cpp)
add_executable(Replay replay/src/main.cpp)

target_link_libraries(Scacchiera tabellone pieces giocatori)
target_link_libraries(Replay tabellone pieces replay_IO)
