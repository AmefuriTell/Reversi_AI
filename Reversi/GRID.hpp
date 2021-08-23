#include <bits/stdc++.h>

class GRID
{
public:
    int stat;
    bool can_black, can_white;
    std::vector<int> can_for_d_black, can_for_d_white;

    GRID()
    {
        can_for_d_black.resize(8, 0);
        can_for_d_white.resize(8, 0);
        stat = 0;
        can_black = false;
        can_white = false;
    }

    void ClearCan()
    {
        for(int i = 0; i < 8; i++)can_for_d_black[i] = 0;
        for(int i = 0; i < 8; i++)can_for_d_white[i] = 0;
        can_black = false;
        can_white = false;
    }
private:
};
