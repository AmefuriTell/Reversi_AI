#include "Reversi.hpp"

void Reversi::Init()
{
    BlackW = nullptr;
    WhiteW = nullptr;
}
void Reversi::Init(Individual *B, Individual *W)
{
    BlackW = new Individual(B->length);
    WhiteW = new Individual(W->length);

    BlackW = B;
    WhiteW = W;

    BlackNN = ANN(*BlackW);
    WhiteNN = ANN(*WhiteW);
}


Reversi::Reversi()
{
    Init();
}
Reversi::Reversi(Individual *B, Individual *W)
{
    Init(B, W);
}
Reversi::~Reversi()
{
    delete(BlackW);
    delete(WhiteW);
}


void Reversi::AIvsAI(Individual *B, Individual *W)
{
    Init(B, W);
    AIvsAI();
}
void Reversi::AIvsAI()
{
    //ここに飛んでくるのは、もうすでに、NNが組みあがっている状態。
    BOARD::Init();
    while (true)
    {
        if(BOARD::can_black == 0 && BOARD::can_white == 0)break;
        if(BOARD::turn == 1)
        {
            if(BOARD::can_black == 0)
            {
                BOARD::ChangeTurn();
                continue;
            }
        }
        else
        {
            if(BOARD::can_white == 0)
            {
                BOARD::ChangeTurn();
                continue;
            }
        }

        BOARD::PrintBoard();
        PutDiskAI();
        BOARD::ChangeTurn();
    }
    
    BOARD::PrintBoard();

    BlackW->score = BOARD::black;
    WhiteW->score = BOARD::white;
}
void Reversi::PutDiskAI()
{
    std::pair<int, int> ans;
    std::vector<std::pair<int, int>> bufv;

    Reversi now = *this, next;

    ANN bufa;
    
    if(turn == 1)
    {
        //黒が指せる全ての手を参照
        bufv = BOARD::can_black_v;
        bufa = BlackNN;
    }
    else
    {
        //白がさせるすべての手を列挙
        bufv = BOARD::can_white_v;
        bufa = WhiteNN;
    }

    //全探索
    //最初の手を見る
    ans = bufv[0];
    next = now;

    next.PutDisk(bufv[0]);
    double maxscore = bufa.EvaluationFunction(*this);
    
    //これより高い手があれば随時更新
    for (int v = 1; v < bufv.size(); v++)
    {
        ans = bufv[v];
        next = now;

        next.PutDisk(bufv[v]);
        double score = bufa.EvaluationFunction(*this);
        if(maxscore < score)
        {
            maxscore = score;
            ans = bufv[v];
        }
    }
    
    //一番高い手を打つ
    BOARD::PutDisk(ans);
}