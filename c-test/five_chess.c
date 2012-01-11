#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define N 8
#define ESC 27

struct game 
{
    char name[256];
    int x;
    int y;
}player[2];

struct game *p = &player[0];
struct game *q = &player[1];

int a[N][N] = {0};
int flag;

void flush(void) 
{ 
    char c; 
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (c == ESC) 
        {
            exit(0);
        }
    }
}

void initial_array_a(void)
{
    int i, j;
    p->x = p->y = 0;
    q->x = q->y = 0;
    for (i = 0; i < N; i++) 
    {
        for (j = 0; j < N; j++) 
        {
            *(*(a + i) + j) = 0;
        }
    }
}

void game_init(int a[N][N])
{
    system("clear");
    printf("\n Welcome to play five-in-a-row !\n\n");
    printf(" Please input your game-name:\n\n");
    printf(" Player1: ");
    scanf("%s",p->name); flush();

    printf(" Player2: ");
    scanf("%s",q->name); flush();
    printf("\n Starting game ...\n");
    //sleep(1);
    usleep(1500000);
    system("clear");
    //print_chess_board(a);
}

void  print_chess_board(int a[N][N])
{
    int i, j;
    p = player;
    printf("\n\t    *** five-in-a-row game ***\n\n");
    printf("  Player1: %-10s\t|\tPlayer2: %-10s\n",p->name, q->name);
    printf("        x: %d\t\t|\t      x: %d\n",p->x, q->x);
    printf("        y: %d\t\t|\t      y: %d\n\n\v",p->y, q->y);
    printf("\t       x 0 1 2 3 4 5 6 7\n");
    printf("\t         ---------------\n");
    printf("\t     y\n");
    for (i = 0; i < N; i++) 
    {
        printf("\t     %d|  ",i);
        for (j = 0; j < N; j++) 
        {
            printf("%d ", *(*(a + i) + j));
        }
        printf("\n");
    }
    //printf("\t         ---------------\n");
    //printf("\t         0 1 2 3 4 5 6 7 x\n");
    printf("\n\n");
}

void get_coordinate(void)
{
    int x, y;
    char name[256];
again1:   if (flag == 0) 
    {
        sprintf(name, "%s",p->name);
    }
    else
    {
        sprintf(name, "%s",q->name);
    }
    printf(" in turns to player %s\n",name);
    printf(" Please input coordinate: ");
    scanf(" %d %d",&x, &y); flush();
    if (x >= N || y >= N) 
    {
        printf("\nCoordinate overflow, Please input again !\n\n");
        sleep(1);
        goto again1;
    }
    if (flag == 0) 
    {
        if (*(*(a + y) + x) == 0)
        {
            *(*(a + y) + x) = 1;
        }
        else
        {
            printf("\nWarning... This coordinate is not blank ! Try again...\n\n");
            sleep(1);
            goto again1;
        }
        p->x = x;
        p->y = y;
        flag = 1;
    }
    else
    {
        if (*(*(a + y) + x) == 0)
        {
            *(*(a + y) + x) = 2;
        }
        else
        {
            printf("\nWarning... This coordinate is not blank ! Try again...\n\n");
            sleep(1);
            goto again1;
        }
        q->x = x;
        q->y = y;
        flag = 0;
    }
}

int judge_who_win(void)
{
    int i, j;
    /*   line scan    */
    for (i = 0; i < N; i++) 
    {
        for (j = 0; j < N-4; j++) 
        {
            if (*(*(a + i) + j) != 0) 
            {
                if (*(*(a + i) + j) == *(*(a + i) + j + 4))
                {
                    if (*(*(a + i) + j) == *(*(a + i) + j + 3))
                    {
                        if (*(*(a + i) + j) == *(*(a + i) + j + 2))
                        {
                            if (*(*(a + i) + j) == *(*(a + i) + j + 1))
                            {
                                return *(*(a + i) + j);
                            }
                        }
                    }
                }
            }
        }
    }


    /*   column scan    */
    for (j = 0; j < N; j++) 
    {
        for (i = 0; i < N-4; i++) 
        {
            if (*(*(a + i) + j) != 0) 
            {
                if (*(*(a + i) + j) == *(*(a + i + 4) + j))
                {
                    if (*(*(a + i) + j) == *(*(a + i + 3) + j))
                    {
                        if (*(*(a + i) + j) == *(*(a + i + 2) + j))
                        {
                            if (*(*(a + i) + j) == *(*(a + i + 1) + j))
                            {
                                return *(*(a + i) + j);
                            }
                        }
                    }
                }
            }
        }
    }

    /*   sideling scan    */
    for (i = 0; i < N-4; i++) 
    {
        if (i == 0) 
        {
            for (j = 0; j < N-4; j++) 
            {
                if (*(*(a + j) + j) != 0) 
                {
                    if (*(*(a + j) + j) == *(*(a + j + 4) + j + 4))
                    {
                        if (*(*(a + j) + j) == *(*(a + j + 3) + j + 3))
                        {
                            if (*(*(a + j) + j) == *(*(a + j + 2) + j + 2))
                            {
                                if (*(*(a + j) + j) == *(*(a + j + 1) + j + 1))
                                {
                                    return *(*(a + j) + j);
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            for (j = 0; j < N-i-4; j++) 
            {
                if (*(*(a + j) + i + j) != 0) 
                {
                    if (*(*(a + j) + i + j) == *(*(a + j + 4) + i + j + 4))
                    {
                        if (*(*(a + j) + i + j) == *(*(a + j + 3) + i + j + 3))
                        {
                            if (*(*(a + j) + i + j) == *(*(a + j + 2) + i + j + 2))
                            {
                                if (*(*(a + j) + i + j) == *(*(a + j + 1) + i + j + 1))
                                {
                                    return *(*(a + j) + i + j);
                                }
                            }
                        }
                    }
                }
            }

            for (j = 0; j < N-i-4; j++) 
            {
                if (*(*(a + i + j) + j) != 0) 
                {
                    if (*(*(a + i + j) + j) == *(*(a + i + j + 4) + j + 4))
                    {
                        if (*(*(a + i + j) + j) == *(*(a + i + j + 3) + j + 3))
                        {
                            if (*(*(a + i + j) + j) == *(*(a + i + j + 2) + j + 2))
                            {
                                if (*(*(a + i + j) + j) == *(*(a + i + j + 1) + j + 1))
                                {
                                    return *(*(a + i + j) + j);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main(int argc, const char *argv[])
{
    char ch = 0;
    int winner = 0;

again4:    game_init(a);
again2:    while (1) 
    {
        print_chess_board(a);
        get_coordinate();
        if (winner = judge_who_win()) 
        {
            system("clear");
            print_chess_board(a);
            printf("\n\t       Congratulations !");
            if (winner == 1) 
            {
                printf("\n\n\t\t  %s win !\n",p->name);
            }
            if (winner == 2) 
            {
                printf("\n\n\t\t  %s win !\n\n",q->name);
            }
            sleep(2);
            printf("\n\n\t *** Press ESC to quit game ***");
  again3:   printf("\n\n\t  Do you want to restart ?(Y/n)\n\t\t      ");
            scanf("%c",&ch); flush();
            if ((ch == 'Y') || (ch == 'y')) 
            {
                initial_array_a();
                system("clear");
                goto again2;
            }
            else if ((ch == 'N') || (ch == 'n')) 
            {
                flag = 0;
                initial_array_a();
                goto again4;
            }
            else if (ch  == ESC ) 
            {
                system("clear");
                return 0;
            }
            else
            {
                goto again3;
            }
            return 0;
        }
        system("clear");
    }
    return 0;
}

