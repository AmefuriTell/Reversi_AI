#ifndef B_H_
#define B_H_

#include <bits/stdc++.h>

class GRID
{
public:
    int stat; //空黒白置
    int can[8]; //置いたとき、8方向にどれだけ伸ばせるかそれぞれを数える。
    GRID();
    void init();

    void Stat2Empty();
    void Stat2Black();
    void Stat2White();
};

#endif