@echo off

cd %~dp0

g++ Reversi.cpp GRID.cpp BOARD.cpp -o Reversi.exe
Reversi.exe

pause