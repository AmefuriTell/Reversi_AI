@echo off

cd %~dp0

g++ Reversi.cpp grid.cpp board.cpp -o Reversi.exe
Reversi.exe

pause