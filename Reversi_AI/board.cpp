#include "board.hpp"

BOARD::BOARD()
{
    grid.resize(8, std::vector<GRID>(8));
    init();
}

void BOARD::init()
{
    for (int i = 0; i < 8; i++)for (int j = 0; j < 8; j++)grid[i][j].Stat2Empty();

    grid[3][3].Stat2Black();
    grid[4][4].Stat2Black();
    grid[3][4].Stat2White();
    grid[4][3].Stat2White();

    white = 2;
    black = 2;
    turn = 1;
    can_num = 0;

    CheckCanPlace();
}

void BOARD::PrintBoard()
{
    printf("You can place num = %d\n", can_num);
    printf("  | abcdefgh\n");
    printf("--+---------\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%d | ", i);
        for (int j = 0; j < 8; j++)
        {
            printf("%c", grid[i][j].stat == 1 ? 'B' : grid[i][j].stat == -1 ? 'W' : grid[i][j].can ? '#' : '.');
        }
        printf("\n");
    }
    
}

void BOARD::game(int mode)
{
    return;
}

void BOARD::CheckCanPlace()
{
    can_num = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            grid[i][j].can = false;
            if(grid[i][j].stat != 0)continue;//�󔒂łȂ���u���Ȃ��̂ł��߁B

            for (int k = 0; k < 8; k++)
            {
                int ni = i + di[k];
                int nj = j + dj[k];

                grid[i][j].count_direction[k] = 0;

                if(0 > ni || ni >= 8 || 0 > nj || nj >= 8)continue;//�Ֆʂ͈̔͊O�Ȃ�A���߁B
                if(grid[ni][nj].stat != -turn)continue;//�ׂ��A�����Ɣ��΂̐F����Ȃ���A���߁B


                //�ׂ��A�����Ƃ͔��΂̐F�ł������ꍇ�A�˂��i�ށB
                for (int l = 2; l < 8; l++)
                {
                    ni = i + di[k] * l;
                    nj = j + dj[k] * l;

                    if(0 > ni || ni >= 8 || 0 > nj || nj >= 8)break;//�Ֆʂ͈̔͊O�Ȃ�A����
                    if(grid[ni][nj].stat == 0)break;//�˂��i�񂾌��ʁA�󔒂���ɗ�����A���߁B

                    if(grid[ni][nj].stat == turn)//�����Ɠ����F��������A�L�^���ďI���B
                    {
                        grid[i][j].can = true;
                        grid[i][j].count_direction[k] = l - 1;
                        break;
                    }
                }
            }

            if(grid[i][j].can)can_num += 1;
        }
    }
    
    return;
}

std::pair<int, int> BOARD::InputDisk()
{
    int i;
    char c;
    printf("�ǂ��ɒu��������͂��Ă������� > ");

    std::cin >> i >> c;

    return std::make_pair(i, (int)c - (int)'a');
}

bool BOARD::PutDisk()
{
    return PutDisk(InputDisk());
}
bool BOARD::PutDisk(std::pair<int, int> in)
{
    return PutDisk(in.first, in.second);
}
bool BOARD::PutDisk(int i, int j)
{
    if(0 > i || i > 7 || 0 > j || j > 7)
    {
        printf("���͂������ł��B\n");
        return true;
    }
    if(!grid[i][j].can)
    {
        printf("���̃}�X�ɂ͒u���܂���B\n");
        return true;
    }

    for (int k = 0; k < 8; k++)
    {
        for(int l = 0; l <= grid[i][j].count_direction[k]; l++)
        {
            int ni = i + di[k] * l;
            int nj = j + dj[k] * l;

            grid[ni][nj].stat = turn;
        }
    }

    return false;
}