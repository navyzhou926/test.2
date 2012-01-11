#include <stdio.h>

#define ROW 8
#define COL 8
#define N 5

int chessboard[ROW][COL];

void print_chessborad(void)
{
    int i,j;
    printf("\n  ");
    for (j = 0; j < COL; j++) 
    {
        printf("%d",j);
    }
    printf("\n");

    printf(" -");
    for (j = 0; j < COL; j++) 
    {
        printf(" -");
    }
    printf("\n");

    for (i = 0; i < ROW; i++) 
    {
        printf("%d|\n",i);
        for (j = 0; j < COL; j++) 
        {
            printf("%d",chessboard[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int get(int *x, int *y)
{
    scanf("%d %d",x, y);
    return 0;
}

int put(int x, int y, int who)
{
    chessboard[x][y] = who;
    return 1;
}

int empty(int x, int y)
{
    if (chessboard[x][y] == 0) 
    {
        return 1;
    }
    return 0;
}

int test(int x, int y)
{
    if (x >= ROW || x < 0) 
    {
        return 0;
    }
    if (y >= COL || y < 0) 
    {
        return 0;
    }
    if (empty(x, y)) 
    {
        return 1;
    }
    return 0;
}

int check(int x, int y)
{
    int i = 0, j = 0;
    int counter = 1;
    int who;
    int nx, ny;

    int dirx[4] = {0, 1, 1, 1};
    int diry[4] = {1, 0, 1, -1};

    who = chessboard[x][y];
    if (who == 0) 
    {
        return 0;
    }

    for (i = 0; i < 4; i++) 
    {
        nx = x;
        ny = y;
        counter = 1;
        for (j = 1; j < N; j++) 
        {
            nx += dirx[i];
            ny += diry[i];
            if (chessboard[nx][ny] == who) 
            {
                counter++;
            }
            if (counter == N) 
            {
                printf("check ok !  %d %d->dir(%d)\n",x, y, i);
                return 1;
            }
        }
    }
    return 0;
}

int  find(void)
{
    int i, j;
    for (i = 0; i < ROW; i++) 
    {
        for (j = 0; j < COL; j++) 
        {
            if (check(i, j)) 
            {
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, const char *argv[])
{
    int x, y;
    int step = 0;
    int who;
    printf("Hello, FIVE CHESS PLAYER!\nReady to go ? GO\n");

    print_chessborad();
    printf("You can input 4 4 to put a chess on board\n");

    while (1) 
    {
        who = step % 2 + 1;
        printf("player %d\n",who);
        get(&x, &y);

        if (test(x, y)) 
        {
            put(x, y, who);
            print_chessborad();
            step++;
            if (find()) 
            {
                printf("Congratulations, player %d win!\n",who);
                return 0;
            }
        }
        else
        {
            printf("%d %d is not permitted ! please reinput.\n\n",x, y);
        }
    }
    return 0;
}
