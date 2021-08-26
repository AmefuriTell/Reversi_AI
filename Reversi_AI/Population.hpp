#ifndef Population_H
#define Population_H

#include <bits/stdc++.h>
#include "Individual.hpp"

class Population
{
public:
    int GEN_NUM, GEN_MAX;
    int GEN_LEN;
    std::vector<Individual> parents;

    Population(int, int, int);
    void GenerationalChange();
};

#endif