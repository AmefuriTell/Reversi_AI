#include "BOARD.hpp"

BOARD::BOARD()
{
    std::srand((unsigned int)time(NULL) );
    grid.resize(8, std::vector<GRID>(8));
    Init();
}

void BOARD::Game(int mode)
{
    Init();
    while (true)
    {
        if(can_black == 0 && can_white == 0)break;
        if(turn == 1)
        {
            if(can_black == 0)
            {
                ChangeTurn();
                continue;
            }
            else
            {
                PrintBoard();
                if(mode == 0 || mode == 1)PutDiskPlayer();
                else PutDiskAI();
                ChangeTurn();
            }
        }
        else
        {
            if(can_white == 0)
            {
                ChangeTurn();
                continue;
            }
            else
            {
                PrintBoard();
                if(mode == 0 || mode == 2)PutDiskPlayer();
                else PutDiskAI();
                ChangeTurn();
            }
        }
    }
    PrintBoard();
    std::cout << "black:" << black << " white:" << white << std::endl;
}

void BOARD::PrintBoard()
{
    std::cout << turn << " " << can_black << " " << can_white << std::endl;
    std::cout << " | abcdefgh" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << i + 1 << "| ";
        for (int j = 0; j < 8; j++)
        {
            if(grid[i][j].stat == 0)
            {
                if(turn == 1 && grid[i][j].can_black)std::cout << "#";
                else if(turn == -1 && grid[i][j].can_white)std::cout << "#";
                else std::cout << ".";
            }
            else if(grid[i][j].stat == 1)
            {
                std::cout << "B";
            }
            else
            {
                std::cout << "W";
            }
        }
        std::cout << std::endl;
    }
    
}

void BOARD::Init()
{
    //gridを初期化
    for(int i = 0; i < 8; i++)for(int j = 0; j < 8; j++)grid[i][j].stat = 0;
    grid[3][3].stat = -1;
    grid[4][4].stat = -1;
    grid[3][4].stat = 1;
    grid[4][3].stat = 1;

    //置ける場所を初期化
    UpdateCan();

    //ターン、黒、白を初期化
    turn = 1;
    black = 2;
    white = 2;
}

void BOARD::ChangeTurn()
{
    turn *= -1;
}

std::pair<int, int> BOARD::InputPos()
{
    int i;
    char c;
    while(true)
    {
        std::cout << "置きたい場所を行 列の順で入力してください > ";
        std::cin >> i >> c;

        if(1 > i || i > 8 || 'a' > c || c > 'h')
        {
            std::cout << "盤面の範囲外です。" << std::endl;
            continue;
        }
        if(turn == 1)
        {
            if(grid[i - 1][(int)c - 'a'].can_black == false)
            {
                std::cout << "そのマスには置けません。" << std::endl;
                continue;
            }
        }
        else
        {
            if(grid[i - 1][(int)c - 'a'].can_white == false)
            {
                std::cout << "そのマスには置けません。" << std::endl;
                continue;
            }
        }
        break;
    }
    return std::make_pair(i - 1, (int)c - 'a');
}

void BOARD::PutDiskPlayer()
{
    PutDisk(InputPos());
}

void BOARD::PutDisk(std::pair<int, int> pos)
{
    int i = pos.first;
    int j = pos.second;

    //もうすでに置けることは確定しているので、置く操作をする。
    for (int k = 0; k < 8; k++)
    {
        for (int l = 0; l < (turn == 1 ? grid[i][j].can_for_d_black[k] : grid[i][j].can_for_d_white[k]); l++)
        {
            int ni = i + di[k] * l;
            int nj = j + dj[k] * l;
            grid[ni][nj].stat = turn; 

        }
    }

    UpdateCan();
}

void BOARD::PutDiskAI()
{
    PutDisk(AI());
}

std::pair<int, int> BOARD::AI()
{
    //とりあえずランダムに打つ。
    if(turn == 1)return can_black_v[rand() % can_black_v.size()];
    return can_white_v[rand() % can_white_v.size()];
}

void BOARD::UpdateCan()
{
    can_black_v.clear();
    can_black_v.shrink_to_fit();
    can_white_v.clear();
    can_white_v.shrink_to_fit();
    
    can_black = 0;
    can_white = 0;
    black = 0;
    white = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            grid[i][j].ClearCan();
            if(grid[i][j].stat == 1)black++;
            else if(grid[i][j].stat == -1)white++;

            if(grid[i][j].stat != 0)continue;

            //黒
            for (int k = 0; k < 8; k++)
            {
                
                int ni = i + di[k];
                int nj = j + dj[k];
                
                if(0 > ni || ni > 7 || 0 > nj || nj > 7)continue;
                if(grid[ni][nj].stat != -1)continue;

                for (int l = 2; l < 8; l++)
                {
                    ni += di[k];
                    nj += dj[k];

                    if(0 > ni || ni > 7 || 0 > nj || nj > 7)break;
                    if(grid[ni][nj].stat == -1)continue;
                    if(grid[ni][nj].stat == 1)
                    {
                        grid[i][j].can_for_d_black[k] = l;
                        grid[i][j].can_black = true;
                    }
                    break;
                }
            }
            if(grid[i][j].can_black)
            {
                can_black_v.push_back(std::make_pair(i, j));
                can_black ++;
            }

            //白
            for (int k = 0; k < 8; k++)
            {
                
                int ni = i + di[k];
                int nj = j + dj[k];
                
                if(0 > ni || ni > 7 || 0 > nj || nj > 7)continue;
                if(grid[ni][nj].stat != 1)continue;

                for (int l = 2; l < 8; l++)
                {
                    ni += di[k];
                    nj += dj[k];

                    if(0 > ni || ni > 7 || 0 > nj || nj > 7)break;
                    if(grid[ni][nj].stat == 1)continue;
                    if(grid[ni][nj].stat == -1)
                    {
                        grid[i][j].can_for_d_white[k] = l;
                        grid[i][j].can_white = true;
                    }
                    break;
                }
            }
            if(grid[i][j].can_white)
            {
                can_white_v.push_back(std::make_pair(i, j));
                can_white ++;
            }
        }
        
    }
    
}