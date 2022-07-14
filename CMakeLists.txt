cmake_minimum_required(VERSION 3.21)
project(checkers)

set(CMAKE_CXX_STANDARD 14)

add_executable(checkers main.cpp Field.cpp Field.h Figure.h Vector2D.cpp Vector2D.h GameLoop.cpp GameLoop.h King.cpp King.h Pawn.cpp Pawn.h Knight.cpp Knight.h Rook.cpp Rook.h Bishop.cpp Bishop.h Queen.cpp Queen.h FiguresFactory.h FiguresFactory.cpp)
