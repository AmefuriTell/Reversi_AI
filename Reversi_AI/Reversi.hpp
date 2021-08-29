#ifndef Reversi_H
#define Reversi_H

#include <bits/stdc++.h>
#include "BOARD.hpp"
#include "Individual.hpp"
#include "ANN.hpp"

class Reversi : public BOARD
{
public:
    Individual *BlackW, *WhiteW;
    ANN BlackNN, WhiteNN;
    Reversi(Individual&, Individual&);
    ~Reversi();
    void AIvsAI();
    
};

#endif