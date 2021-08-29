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
    Reversi();
    Reversi(Individual*, Individual*);
    ~Reversi();

    void Init();
    void Init(Individual*, Individual*);

    void AIvsAI();
    void AIvsAI(Individual*, Individual*);

    void PutDiskAI();
};

#endif