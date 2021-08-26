#include <bits/stdc++.h>

#include "Population.hpp"
#include "Reversi.hpp"

#define GEN_MAX 1
#define GEN_NUM 100
#define GEN_LEN 100

int main()
{
    Population BlackAI(GEN_NUM, GEN_MAX, GEN_LEN);//個体群を生成//黒
    Population WhiteAI(GEN_NUM, GEN_MAX, GEN_LEN);//個体群を生成//白


    int generation = 0;
    while (generation <= GEN_MAX)//最終世代まで来たら終了
    {
        //各個体同士を対戦させ、各個体に評価値を割り当てる。
        for (int b = 0; b < GEN_NUM; b++)
        {
            for(int w = 0; w < GEN_NUM; w++)
            {
                Reversi board(BlackAI.parents[b], WhiteAI.parents[w]);
                board.AIvsAI();
            }
        }

        //各個体の評価値をもとに、世代交代
        BlackAI.GenerationalChange();
        generation++;
    }

}