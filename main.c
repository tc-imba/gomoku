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
 * 你的代码开始 
 */

/* 
 * You can define your own struct and variable here
 * 你可以在这里定义你自己的结构体和变量
 */

#define DEBUG
// #define RELEASE

unsigned int round;

#define OPENING_NUM 26
const int openings[OPENING_NUM][3][2];
const char *formula[OPENING_NUM][4];
const int formula_pos[OPENING_NUM][2];
int openingId;


#ifdef DEBUG

#include "includes/openings.h"

#else
const int openings[OPENING_NUM][3][2]={{{7,7},{7,8},{7,6},},{{7,7},{8,7},{7,6},},{{7,7},{8,7},{7,6},},{{7,7},{8,5},{7,6},},{{7,7},{7,5},{7,6},},{{7,7},{7,9},{7,6},},{{7,7},{9,7},{7,6},},{{7,7},{8,8},{8,6},},{{7,7},{8,7},{8,6},},{{7,7},{7,8},{8,6},},{{7,7},{9,6},{8,6},},{{7,7},{8,9},{8,6},},{{7,7},{6,9},{8,6},},{{7,7},{9,8},{8,6},},{{7,7},{9,7},{8,6},},{{7,7},{7,9},{8,6},},{{7,7},{9,6},{7,6},},{{7,7},{9,8},{7,6},},{{7,7},{8,8},{7,6},},{{7,7},{8,9},{7,6},},{{7,7},{9,9},{7,6},},{{7,7},{9,5},{7,6},},{{7,7},{6,8},{8,6},},{{7,7},{9,5},{8,6},},{{7,7},{9,9},{8,6},},{{7,7},{5,9},{8,6},},};
const char* formula[OPENING_NUM][4]={{"I8 G7 I7 J7","J7 G7 I7 I8",},{"G8 I10","J8 I7","I9 J8 G8","I7 J10",},{"H6 I8","J8 I6","H10 I7 I8 J9","I10 G8 I8",},{"I8 G9","I9 J9","I7 G9 J9 J10","J10 I8 G9 G8",},{"I10 G8 G9 I9","J10 F8 G9","H11 G7 I9","J9 F8 G9 I9",},{"I10 I7","I7 G7 I6 J7","H7 I5 I7","J7 G7 I8",},{"G8 I10","I10 I7","G7 I7 I8 I9","I9 I7 I8",},{"G9 J7 J8","H7 G9 J6 J8","H6 G9 I6 J6 J7","J6 G8 G9 H9 H10",},{"J8 H10","G8 H7","H9 G8 J8","H7 G10",},{"J8 H10","I8 I7","K8 H7 H10 I7","H7 I10 J8 J10",},{"H9 G9","H6 G8 I8","G8 H6 I8","G9 H9 I8",},{"I10 H7","J8 H7","H9 G9","G9 J7",},{"H9 G9","I10 G9 E8","I8 H6 I6","J7 H6 H9",},{"I7 H6 I6","I5 G8 I6","J8 I7 K7","H7 I6 J6",},{"I8 I7","H7 I7","I7 I8","H6 I8 J9",},{"H9 G9","G9 J9","I10 I7 J8","H7 F8 G7 I7",},{"J8 I7","G8 I10","G7 I8 I10","J10 I7 I8",},{"G8 I10","I10 G8","G7 I6","I9 J9",},{"G9 F9",},{"G10 I8","F7 G8","I10 G8","G7 G7 I7 J7",},{"G8 F7",},{"I9 G9 I9 I11 J8 J9","I8 I9 J7 J9","G7 I9 I11","G8 I9 I10",},{"H9 J9","I10 I7","G9 F7 F8","G8 F6 F7 H6",},{"H10 J8","H9 G9 I8 I10 I11 J8 J9","I7 H10 I8 I10 K9","H11 I8 I11 J8 J9",},{"G7 J9","I7 H6 I6 I8 K7","G8 J7","H9 I7 J9",},{"I10 I8",},};
const int formula_pos[OPENING_NUM][2]={{2,2},{4,3},{4,1},{4,1},{4,4},{4,1},{4,2},{4,1},{4,3},{4,1},{4,1},{4,1},{4,1},{4,1},{4,3},{4,3},{4,2},{4,4},{1,1},{4,3},{1,1},{4,1},{4,1},{4,1},{4,2},{1,1},};
#endif


int verifyOpening(const char board[BOARD_SIZE][BOARD_SIZE])
{
    int order[3] = {OTHER, ME, OTHER};
    for (int i = 0; i < OPENING_NUM; i++)
    {
        int count = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[openings[i][j][0]][openings[i][j][1]] == order[j])
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

struct Position getPos(char *str)
{

}

void initOpening()
{
    if (openingId >= 0 && openingId < OPENING_NUM)
    {
        return;
    }
    for (int i = 0; i < formula_pos[openingId][0]; i++)
    {
        const char *p = formula[openingId][i];
        while (p++)
        {
            
        }
    }
}

/*
 * You should init your AI here
 * 在这里初始化你的AI
 */
void initAI()
{
#ifdef DEBUG
    printf("Begin to initialize the brain\n");
#endif
    round = 0;

    // 初始化开局定式


}


/*
 * Game Start, you will put the first chess.
 * Warning: This method will only be called when after the initialize ofi the  map, it is your turn to put the chess. 
 * Or this method will not be called.
 * You should return a valid Position variable.
 * 棋局开始，首先由你来落子
 * 请注意：只有在当棋局初始化后，轮到你落子时才会触发这个函数。如果在棋局初始化完毕后，轮到对手落子，则这个函数不会被触发。详见项目要求。
 * 在这里，me的取值只可能是ME(1)，即board(棋盘)上为ME(1)的位置表示你的棋子，board(棋盘)上为OTHER(2)的位置表示对手的棋子。
 * 你需要返回一个结构体Position，在x属性和y属性填上你想要落子的位置。 
 */
struct Position aiBegin(const char board[BOARD_SIZE][BOARD_SIZE], int me)
{
    /*
     * TODO: Write your own ai here!
     * Here is a simple AI which just put chess at empty position!
     * 代做：在这里写下你的AI。 
     * 这里有一个示例AI，它只会寻找第一个可下的位置进行落子。 
     */

    // 先开局时一定为白4
    round = 4;

    openingId = verifyOpening(board);
#ifdef DEBUG
    printf("The opening id is %d\n", openingId);
#endif

    // 开局定式
    initOpening();
    /*switch (opening)
    {
    case 0: // 花月

    default:
        // 不满足开局定式，直接开始搜索
        // 理论上评测系统不会出现该情况
        break;
    }*/

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
 * 棋局进行中，对方上一步落子在(otherX, otherY)的位置，轮到你落子了。
 * 在这里，me的取值只可能是ME(1)，即board(棋盘)上为ME(1)的位置表示你的棋子，board(棋盘)上为OTHER(2)的位置表示对手的棋子。
 * 你需要返回一个结构体Position，在x属性和y属性填上你想要落子的位置。 
 */
struct Position aiTurn(const char board[BOARD_SIZE][BOARD_SIZE], int me, int otherX, int otherY)
{
    /*
     * TODO: Write your own ai here!
     * Here is a simple AI which just put chess at empty position!
     * 代做：在这里写下你的AI。 
     * 这里有一个示例AI，它只会寻找第一个可下的位置进行落子。 
     */

    // 后开局时一定为黑5
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
 * 你的代码结束 
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
