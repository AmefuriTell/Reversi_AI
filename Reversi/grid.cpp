#include "grid.hpp"

GRID::GRID()
{
    init();
}

void GRID::init()
{
    stat = 0;
    for (int i = 0; i < 8; i++)can[i] = 0;
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