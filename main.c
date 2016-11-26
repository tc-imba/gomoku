#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 15
#define EMPTY 0
#define ME 1
#define OTHER 2

#define TRUE 1
#define FALSE 0

#define MAX_BYTE 10000

#define START "START"
#define PLACE "PLACE"
#define DONE  "DONE"
#define TURN  "TURN"
#define BEGIN "BEGIN"
#define END   "END"

struct Position
{
    int x;
    int y;
};

char buffer[MAX_BYTE] = {0};
char board[BOARD_SIZE][BOARD_SIZE] = {0};

void debug(const char *str)
{
    printf("DEBUG %s\n", str);
    fflush(stdout);
}

/*
 * YOUR CODE BEGIN
 * ��Ĵ��뿪ʼ 
 */

/* 
 * You can define your own struct and variable here
 * ����������ﶨ�����Լ��Ľṹ��ͱ���
 */

#define DEBUG

unsigned int round;

#define OPENING_NUM 26
struct Position openings[OPENING_NUM][3];
int opening;

void initOpenings()
{
#ifdef DEBUG

#include "openings.txt"
#else
    openings[0][0].x = 7;
    openings[0][0].y = 7;
    openings[0][2].x = 7;
    openings[0][2].y = 6;
    openings[0][1].x = 7;
    openings[0][1].y = 8;

    openings[1][0].x = 7;
    openings[1][0].y = 7;
    openings[1][2].x = 7;
    openings[1][2].y = 6;
    openings[1][1].x = 8;
    openings[1][1].y = 7;

    openings[2][0].x = 7;
    openings[2][0].y = 7;
    openings[2][2].x = 7;
    openings[2][2].y = 6;
    openings[2][1].x = 8;
    openings[2][1].y = 7;

    openings[3][0].x = 7;
    openings[3][0].y = 7;
    openings[3][2].x = 7;
    openings[3][2].y = 6;
    openings[3][1].x = 8;
    openings[3][1].y = 5;

    openings[4][0].x = 7;
    openings[4][0].y = 7;
    openings[4][2].x = 7;
    openings[4][2].y = 6;
    openings[4][1].x = 7;
    openings[4][1].y = 5;

    openings[5][0].x = 7;
    openings[5][0].y = 7;
    openings[5][2].x = 7;
    openings[5][2].y = 6;
    openings[5][1].x = 7;
    openings[5][1].y = 9;

    openings[6][0].x = 7;
    openings[6][0].y = 7;
    openings[6][2].x = 7;
    openings[6][2].y = 6;
    openings[6][1].x = 9;
    openings[6][1].y = 7;

    openings[7][0].x = 7;
    openings[7][0].y = 7;
    openings[7][2].x = 8;
    openings[7][2].y = 6;
    openings[7][1].x = 8;
    openings[7][1].y = 8;

    openings[8][0].x = 7;
    openings[8][0].y = 7;
    openings[8][2].x = 8;
    openings[8][2].y = 6;
    openings[8][1].x = 8;
    openings[8][1].y = 7;

    openings[9][0].x = 7;
    openings[9][0].y = 7;
    openings[9][2].x = 8;
    openings[9][2].y = 6;
    openings[9][1].x = 7;
    openings[9][1].y = 8;

    openings[10][0].x = 7;
    openings[10][0].y = 7;
    openings[10][2].x = 8;
    openings[10][2].y = 6;
    openings[10][1].x = 9;
    openings[10][1].y = 6;

    openings[11][0].x = 7;
    openings[11][0].y = 7;
    openings[11][2].x = 8;
    openings[11][2].y = 6;
    openings[11][1].x = 8;
    openings[11][1].y = 9;

    openings[12][0].x = 7;
    openings[12][0].y = 7;
    openings[12][2].x = 8;
    openings[12][2].y = 6;
    openings[12][1].x = 6;
    openings[12][1].y = 9;

    openings[13][0].x = 7;
    openings[13][0].y = 7;
    openings[13][2].x = 8;
    openings[13][2].y = 6;
    openings[13][1].x = 9;
    openings[13][1].y = 8;

    openings[14][0].x = 7;
    openings[14][0].y = 7;
    openings[14][2].x = 8;
    openings[14][2].y = 6;
    openings[14][1].x = 9;
    openings[14][1].y = 7;

    openings[15][0].x = 7;
    openings[15][0].y = 7;
    openings[15][2].x = 8;
    openings[15][2].y = 6;
    openings[15][1].x = 7;
    openings[15][1].y = 9;

    openings[16][0].x = 7;
    openings[16][0].y = 7;
    openings[16][2].x = 7;
    openings[16][2].y = 6;
    openings[16][1].x = 9;
    openings[16][1].y = 6;

    openings[17][0].x = 7;
    openings[17][0].y = 7;
    openings[17][2].x = 7;
    openings[17][2].y = 6;
    openings[17][1].x = 9;
    openings[17][1].y = 8;

    openings[18][0].x = 7;
    openings[18][0].y = 7;
    openings[18][2].x = 7;
    openings[18][2].y = 6;
    openings[18][1].x = 8;
    openings[18][1].y = 8;

    openings[19][0].x = 7;
    openings[19][0].y = 7;
    openings[19][2].x = 7;
    openings[19][2].y = 6;
    openings[19][1].x = 8;
    openings[19][1].y = 9;

    openings[20][0].x = 7;
    openings[20][0].y = 7;
    openings[20][2].x = 7;
    openings[20][2].y = 6;
    openings[20][1].x = 9;
    openings[20][1].y = 9;

    openings[21][0].x = 7;
    openings[21][0].y = 7;
    openings[21][2].x = 7;
    openings[21][2].y = 6;
    openings[21][1].x = 9;
    openings[21][1].y = 5;

    openings[22][0].x = 7;
    openings[22][0].y = 7;
    openings[22][2].x = 8;
    openings[22][2].y = 6;
    openings[22][1].x = 6;
    openings[22][1].y = 8;

    openings[23][0].x = 7;
    openings[23][0].y = 7;
    openings[23][2].x = 8;
    openings[23][2].y = 6;
    openings[23][1].x = 9;
    openings[23][1].y = 5;

    openings[24][0].x = 7;
    openings[24][0].y = 7;
    openings[24][2].x = 8;
    openings[24][2].y = 6;
    openings[24][1].x = 9;
    openings[24][1].y = 9;

    openings[25][0].x = 7;
    openings[25][0].y = 7;
    openings[25][2].x = 8;
    openings[25][2].y = 6;
    openings[25][1].x = 5;
    openings[25][1].y = 9;
#endif
}

int verifyOpening(const char board[BOARD_SIZE][BOARD_SIZE])
{
    int order[3] = {OTHER, ME, OTHER};
    for (int i = 0; i < OPENING_NUM; i++)
    {
        int count = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[openings[i][j].x][openings[i][j].y] == order[j])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        if (count == 3)
        {
            return i;
        }
    }
    return -1;
}

/*
 * You should init your AI here
 * �������ʼ�����AI
 */
void initAI()
{
#ifdef DEBUG
    printf("Begin to initialize the brain\n");
#endif
    round = 0;

    // ��ʼ�����ֶ�ʽ
    initOpenings();

}

/*
 * Game Start, you will put the first chess.
 * Warning: This method will only be called when after the initialize ofi the  map, it is your turn to put the chess. 
 * Or this method will not be called.
 * You should return a valid Position variable.
 * ��ֿ�ʼ����������������
 * ��ע�⣺ֻ���ڵ���ֳ�ʼ�����ֵ�������ʱ�Żᴥ������������������ֳ�ʼ����Ϻ��ֵ��������ӣ�������������ᱻ�����������ĿҪ��
 * �����me��ȡֵֻ������ME(1)����board(����)��ΪME(1)��λ�ñ�ʾ������ӣ�board(����)��ΪOTHER(2)��λ�ñ�ʾ���ֵ����ӡ�
 * ����Ҫ����һ���ṹ��Position����x���Ժ�y������������Ҫ���ӵ�λ�á� 
 */
struct Position aiBegin(const char board[BOARD_SIZE][BOARD_SIZE], int me)
{
    /*
     * TODO: Write your own ai here!
     * Here is a simple AI which just put chess at empty position!
     * ������������д�����AI�� 
     * ������һ��ʾ��AI����ֻ��Ѱ�ҵ�һ�����µ�λ�ý������ӡ� 
     */

    // �ȿ���ʱһ��Ϊ��4
    round = 4;

    opening = verifyOpening(board);
#ifdef DEBUG
    printf("The opening id is %d\n", opening);
#endif

    // ���ֶ�ʽ
    if (opening >= 0 && opening < OPENING_NUM)
    {

    }
    switch (opening)
    {
    case 0: // ����

    default:
        // �����㿪�ֶ�ʽ��ֱ�ӿ�ʼ����
        // ����������ϵͳ������ָ����
        break;
    }

    int i, j;
    struct Position preferedPos;

    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (EMPTY == board[i][j])
            {
                preferedPos.x = i;
                preferedPos.y = j;
                return preferedPos;
            }
        }
    }

    return preferedPos;
}


/*
 * Game ongoing, the competitor put the chess at the position (otherX, otherY). You should put your chess.
 * You should return a valid Position variable.
 * ��ֽ����У��Է���һ��������(otherX, otherY)��λ�ã��ֵ��������ˡ�
 * �����me��ȡֵֻ������ME(1)����board(����)��ΪME(1)��λ�ñ�ʾ������ӣ�board(����)��ΪOTHER(2)��λ�ñ�ʾ���ֵ����ӡ�
 * ����Ҫ����һ���ṹ��Position����x���Ժ�y������������Ҫ���ӵ�λ�á� 
 */
struct Position aiTurn(const char board[BOARD_SIZE][BOARD_SIZE], int me, int otherX, int otherY)
{
    /*
     * TODO: Write your own ai here!
     * Here is a simple AI which just put chess at empty position!
     * ������������д�����AI�� 
     * ������һ��ʾ��AI����ֻ��Ѱ�ҵ�һ�����µ�λ�ý������ӡ� 
     */

    // �󿪾�ʱһ��Ϊ��5
    if (round == 0)
    {
        round = 5;
    }
    else
    {
        round += 2;
    }


    int i, j;
    struct Position preferedPos;

    static int count = 0;

    if (count++ % 3 != 0)
    {
        for (i = BOARD_SIZE - 1; i >= 0; i--)
        {
            for (j = 0; j < BOARD_SIZE; j++)
            {
                if (EMPTY == board[i][j])
                {
                    preferedPos.x = i;
                    preferedPos.y = j;
                    return preferedPos;
                }
                if (board[i][j] == OTHER)
                {
                    break;
                }
            }
        }
    }


    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (EMPTY == board[i][j])
            {
                preferedPos.x = i;
                preferedPos.y = j;
                return preferedPos;
            }
        }
    }


    return preferedPos;
}

/*
 * YOUR CODE END
 * ��Ĵ������ 
 */

void place(int x, int y, int z)
{
    board[x][y] = z;
}

void done()
{
    printf("OK\n");
    fflush(stdout);
}

void start()
{
    memset(board, 0, sizeof(board));
    initAI();
}

void turn(int x, int y)
{
    board[x][y] = OTHER;

    // AI
    struct Position pos = aiTurn((const char (*)[20]) board, ME, x, y);
    board[pos.x][pos.y] = ME;
    printf("%d %d\n", pos.x, pos.y);
    fflush(stdout);
}

void end(int x)
{

}

void loop()
{
    while (TRUE)
    {
        memset(buffer, 0, sizeof(buffer));
        gets(buffer);

        if (strstr(buffer, START))
        {
            start();
        }
        else if (strstr(buffer, PLACE))
        {
            char tmp[MAX_BYTE] = {0};
            int x, y, z;
            sscanf(buffer, "%s %d %d %d", tmp, &x, &y, &z);
            place(x, y, z);
        }
        else if (strstr(buffer, DONE))
        {
            done();
        }
        else if (strstr(buffer, BEGIN))
        {
            // AI
            struct Position pos = aiBegin((const char (*)[20]) board, ME);
            board[pos.x][pos.y] = ME;
            printf("%d %d\n", pos.x, pos.y);
            fflush(stdout);
        }
        else if (strstr(buffer, TURN))
        {
            char tmp[MAX_BYTE] = {0};
            int x, y;
            sscanf(buffer, "%s %d %d", tmp, &x, &y);
            turn(x, y);
        }
        else if (strstr(buffer, END))
        {
            char tmp[MAX_BYTE] = {0};
            int x;
            sscanf(buffer, "%s %d", tmp, &x);
            end(x);
        }
    }
}


int main(int argc, char *argv[])
{
    loop();
    return 0;
}
