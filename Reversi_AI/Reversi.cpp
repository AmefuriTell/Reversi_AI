#include "Reversi.hpp"

Reversi::Reversi(Individual *B, Individual *W)
{
    BlackW = new Individual(B->length);
    WhiteW = new Individual(W->length);

    BlackW = B;
    WhiteW = W;

    BlackNN = ANN(*BlackW);
    WhiteNN = ANN(*WhiteW);
}

Reversi::~Reversi()
{
    delete(BlackW);
    delete(WhiteW);
}

void AIvsAI()
{

}