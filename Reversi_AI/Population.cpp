#include "Population.hpp"

Population::Population(int GN, int GM, int CL)
{
    GEN_NUM = GN;
    GEN_MAX = GM;
    GEN_LEN = CL;

    parents.resize(GN, 100);
}

void Population::GenerationalChange()
{
    return;
}