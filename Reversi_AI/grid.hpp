#ifndef Grid_H
#define Grid_H

#include <bits/stdc++.h>

class GRID
{
public:
    int stat; //�󍕔��u
    bool can;
    std::vector<int> count_direction; //�u�����Ƃ��A8�����ɂǂꂾ���L�΂��邩���ꂼ��𐔂���B
    GRID();
    void init();

    void Stat2Empty();
    void Stat2Black();
    void Stat2White();
};

#endif