#ifndef BOARD_H
#define BOARD_H

#include <bits/stdc++.h>
#include "GRID.hpp"

class BOARD
{
public:
    BOARD();

    void Game(int);// 0:PVP 1:PVE 2:EVP 3:EVE

    void PrintBoard();

private:
    std::vector<std::vector<GRID>> grid;
    std::vector<std::pair<int, int>> can_black_v, can_white_v;

    int black, white, can_black, can_white;
    int turn;

    int di[8] = {1, 1, 1, 0, -1, -1, -1, 0};
    int dj[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    void Init();
    void ChangeTurn();

    std::pair<int, int> InputPos();

    void PutDiskPlayer();
    void PutDisk(std::pair<int, int>);
    void PutDiskAI();

    std::pair<int, int> AI();

    void UpdateCan();
};

#endif