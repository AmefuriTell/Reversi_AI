#include <bits/stdc++.h>

class GRID
{
public:
    int stat;
    bool can_black, can_white;
    std::vector<int> can_for_d_black, can_for_d_white;

    GRID()
    {
        can_for_d_black.resize(8, 0);
        can_for_d_white.resize(8, 0);
        stat = 0;
        can_black = false;
        can_white = false;
    }

    void ClearCan()
    {
        for(int i = 0; i < 8; i++)can_for_d_black[i] = 0;
        for(int i = 0; i < 8; i++)can_for_d_white[i] = 0;
        can_black = false;
        can_white = false;
    }
private:
};

class BOARD
{
public:
    BOARD()
    {
        std::srand((unsigned int)time(NULL) );
        grid.resize(8, std::vector<GRID>(8));
        Init();
    }

    void Game(int mode)// 0:PVP 1:PVE 2:EVP 3:EVE
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

    void PrintBoard()
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

private:
    std::vector<std::vector<GRID>> grid;
    std::vector<std::pair<int, int>> can_black_v, can_white_v;

    int black, white, can_black, can_white;
    int turn;

    int di[8] = {1, 1, 1, 0, -1, -1, -1, 0};
    int dj[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    void Init()
    {
        //grid��������
        for(int i = 0; i < 8; i++)for(int j = 0; j < 8; j++)grid[i][j].stat = 0;
        grid[3][3].stat = -1;
        grid[4][4].stat = -1;
        grid[3][4].stat = 1;
        grid[4][3].stat = 1;

        //�u����ꏊ��������
        UpdateCan();

        //�^�[���A���A����������
        turn = 1;
        black = 2;
        white = 2;
    }
    void ChangeTurn()
    {
        turn *= -1;
    }

    std::pair<int, int> InputPos()
    {
        int i;
        char c;
        while(true)
        {
            std::cout << "�u�������ꏊ���s ��̏��œ��͂��Ă������� > ";
            std::cin >> i >> c;

            if(1 > i || i > 8 || 'a' > c || c > 'h')
            {
                std::cout << "�Ֆʂ͈̔͊O�ł��B" << std::endl;
                continue;
            }
            if(turn == 1)
            {
                if(grid[i - 1][(int)c - 'a'].can_black == false)
                {
                    std::cout << "���̃}�X�ɂ͒u���܂���B" << std::endl;
                    continue;
                }
            }
            else
            {
                if(grid[i - 1][(int)c - 'a'].can_white == false)
                {
                    std::cout << "���̃}�X�ɂ͒u���܂���B" << std::endl;
                    continue;
                }
            }
            break;
        }
        return std::make_pair(i - 1, (int)c - 'a');
    }

    void PutDiskPlayer()
    {
        PutDisk(InputPos());
    }
    void PutDisk(std::pair<int, int> pos)
    {
        int i = pos.first;
        int j = pos.second;

        //�������łɒu���邱�Ƃ͊m�肵�Ă���̂ŁA�u�����������B
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
    void PutDiskAI()
    {
        PutDisk(AI());
    }

    std::pair<int, int> AI()
    {
        //�Ƃ肠���������_���ɑłB
        if(turn == 1)
        {
            return can_black_v[rand() % can_black_v.size()];
        }
        return can_white_v[rand() % can_white_v.size()];
    }

    void UpdateCan()
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

                //��
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

                //��
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
};

int main()
{
    BOARD board;
    board.Game(3);
}