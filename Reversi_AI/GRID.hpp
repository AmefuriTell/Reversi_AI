#ifndef GRID_H
#define GRID_H

#include <bits/stdc++.h>

class GRID
{
public:
    int stat;
    bool can_black, can_white;
    std::vector<int> can_for_d_black, can_for_d_white;

    GRID();

    void ClearCan();
private:
};

#endif