
#ifndef A_H_
#define A_H_

#include <bits/stdc++.h>
#include "grid.hpp"

class BOARD
{
public:
    std::vector<std::vector<GRID>> grid;

private:
    int black, white, turn;
    int di[8] = {1, 1, 1, 0, -1, -1, -1, 0};
    int dj[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

public:
    BOARD();
    void init();
    
    void PrintBoard();
    void game(int);//0:PVP 1:PVE 2:EVP 3:EVE

    void ChangeTurn();

private:
    void PlayerMove();
    void AIMove();
};

#endif