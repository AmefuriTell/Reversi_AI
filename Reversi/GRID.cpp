#include "GRID.hpp"

GRID::GRID()
{
    can_for_d_black.resize(8, 0);
    can_for_d_white.resize(8, 0);
    stat = 0;
    can_black = false;
    can_white = false;
}

void GRID::ClearCan()
{
    for(int i = 0; i < 8; i++)can_for_d_black[i] = 0;
    for(int i = 0; i < 8; i++)can_for_d_white[i] = 0;
    can_black = false;
    can_white = false;
}