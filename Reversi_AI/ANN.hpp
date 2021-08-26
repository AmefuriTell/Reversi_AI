#ifndef ANN_H
#define ANN_H

#include <bits/stdc++.h>
#include "Individual.hpp"
#include "Reversi.hpp"

class ANN
{
public:
    ANN();
    ANN(Individual);
    double EvaluationFunction(Reversi);
private:
    Individual weight;
};

#endif