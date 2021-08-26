#include "Individual.hpp"


Individual::Individual()
{
}
Individual::Individual(int l)
{
    length = l;
    chromosome.resize(l, 0);
    score = 0;
    init();
}

void Individual::init()
{
    std::random_device seed;
    std::mt19937 engine(seed());
    std::normal_distribution<> dist(0.0, 0.5);

    for (int i = 0; i < length; i++)
    {
        chromosome[i] = dist(engine);
    }
}