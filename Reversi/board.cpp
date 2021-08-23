#include "board.hpp"

BOARD::BOARD()
{
    grid.resize(8, std::vector<GRID>(8));
    init();
}

void BOARD::init()
{
    for (int i = 0; i < 8; i++)for (int j = 0; j < 8; j++)grid[i][j].Stat2Empty();

    grid[3][3].Stat2Black();
    grid[4][4].Stat2Black();
    grid[3][4].Stat2White();
    grid[4][3].Stat2White();

    white = 2;
    black = 2;
    turn = 1;
}

void BOARD::PrintBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%c", grid[i][j].stat == 1 ? 'B' : grid[i][j].stat == -1 ? 'W' : '.');
        }
        printf("\n");
    }
    
}

void BOARD::game(int mode)
{
    return;
}