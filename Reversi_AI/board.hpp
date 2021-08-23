
#ifndef Board_H
#define Board_H

#include <bits/stdc++.h>
#include "grid.hpp"

class BOARD
{
public:
    std::vector<std::vector<GRID>> grid;

    int black, white, turn, can_num;
    int di[8] = {1, 1, 1, 0, -1, -1, -1, 0};
    int dj[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    BOARD();
    void init();
    
    void PrintBoard();
    void game(int);//0:PVP 1:PVE 2:EVP 3:EVE

    void CheckCanPlace();
    std::pair<int, int> InputDisk();
    bool PutDisk();
    bool PutDisk(int,int);
    bool PutDisk(std::pair<int, int>);

    void ChangeTurn();

    void PlayerMove();
    void AIMove();
};

#endif