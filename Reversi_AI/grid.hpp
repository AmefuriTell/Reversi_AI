#ifndef Grid_H
#define Grid_H

#include <bits/stdc++.h>

class GRID
{
public:
    int stat; //空黒白置
    bool can;
    std::vector<int> count_direction; //置いたとき、8方向にどれだけ伸ばせるかそれぞれを数える。
    GRID();
    void init();

    void Stat2Empty();
    void Stat2Black();
    void Stat2White();
};

#endif