#ifndef Individual_H
#define Individual_H

#include <bits/stdc++.h>

class Individual
{
public:
    std::vector<long double> chromosome;
    int score;
    int length;

    Individual();
    Individual(int);
private:
    void init();
};

#endif