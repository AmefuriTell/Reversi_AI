#include "grid.hpp"

GRID::GRID()
{
    count_direction.resize(8);
    init();
}

void GRID::init()
{
    stat = 0;
    can = false;
    for (int i = 0; i < 8; i++)count_direction[i] = 0;
    return;
}

void GRID::Stat2Empty()
{
    stat = 0;
    return;
}

void GRID::Stat2Black()
{
    stat = 1;
    return;
}

void GRID::Stat2White()
{
    stat = -1;
    return;
}