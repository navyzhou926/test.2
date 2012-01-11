#include <stdio.h>
#include <string.h>
#include <time.h>

#define size 4


void flush(void) 
{ 
    char c; 
    while ((c = getchar()) != '\n' && c != EOF) 
    {
        //if (c == ESC) 
        //{
            //exit(0);
        //}
    }
}

int my_rand(int *a)
{
    int i, j, temp, count, flag;

    a[0] = rand()%size;
    while (count < size) 
    {
        temp = rand()%size;
        for (i = 0; i < count; i++) 
        {
            if (temp == a[i]) 
            {
                flag = 1;
            }
        }
        if (flag == 1) 
        {
            flag = 0;
        }
        else
        {
            a[count++] = temp;
        }
    }

    return 0;
}

int generate_rand(int *a)
{
    int i;

    a[0] = rand()%10;
    while ((a[1] = rand()%10) == a[0]);
    while (((a[2] = rand()%10) == a[1]) || (a[2] == a[0]));
    while (((a[3] = rand()%10) == a[2]) || (a[3] == a[1]) || (a[3] == a[0]));
}

int error_deal1(int *a)
{
    while (a[1] == a[0])
        return 1;
    while ((a[2] == a[1]) || (a[2] == a[0]))
        return 1;
    while ((a[3] == a[2]) || (a[3] == a[1]) || (a[3] == a[0]))
        return 1;

    return 0;
}

int error_deal2(int *a)
{
    int i;
    for (i = 0; i < size; i++) 
    {
        if ((*(a + i) > 9) || (*(a + i) < 0)) 
        {
            printf("\ninvalid number %d\n",*(a + i));
            printf("Please input again\n\n");
            return 1;
        }
    }
    return 0;
}

int  guess_number(int *a)
{
    int i, j;
    int b[5];
    int A, B, C;
    int flag = 0;

    while (A != 4) 
    {
        A = 0;
        B = 0;
        C = 0;
  again:scanf(" %d %d %d %d", &b[0], &b[1], &b[2], &b[3]);
        flush();
        if (error_deal1(b) == 1) 
        {
            printf("\nReduplicate number !\n");
            printf("Please input again\n\n");
            goto again;
        }
        if (error_deal2(b) == 1) 
        {
            goto again;
        }

        for (i = 0; i < size; i++) 
        {
            for (j = 0; j < size; j++) 
            {
                while (a[j] == b[i])
                {
                    if (i == j) 
                        A++;
                    else
                        B++;
                    flag = 1;
                    break;
                }
            }
            if ((j == size) && (flag != 1)) 
            {
                C++;
            }
            flag = 0;
        }
        printf("%dA %dB %dC\n\n",A, B, C);
    }

    return 1;
}

int main(int argc, const char *argv[])
{
    int i;
    int a[size] = {0};
    int win = 0;

    srand((unsigned int)time(NULL));
    generate_rand(a);

    printf("\nThe right answer is:");
    for (i = 0; i < size; i++) 
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    printf("please input number from 0 to 9\n\n");

    win = guess_number(a);
    if (win == 1) 
    {
        printf("\ncongratulations you win\n\n");
    }

    return 0;
}

