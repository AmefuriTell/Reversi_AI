#include "Reversi.hpp"

Reversi::Reversi(Individual b, Individual w)
{
    BlackW = b;
    WhiteW = w;

    BlackNN = ANN(b);
    WhiteNN = ANN(w);
}

void AIvsAI()
{

}