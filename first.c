#include <stdio.h>

#define COUNT 5

int main(int agrc, const char *argv[])
{
    int i, temp = 0, count = 0, flag = 0;
    int a[COUNT] = {0};

    srand((unsigned int)(time(0)));

    while(count < COUNT)
    {
        temp = rand()%COUNT + 1;
        for (i = 0; i < count; i++) 
        {
            if (temp == a[i]) 
                flag = 1;
        }
        if (flag == 1) 
            flag = 0;
        else
            a[count++] = temp;
    }

    for (i = 0; i < COUNT; i++) 
        printf("%d  ",a[i]);
    printf("\n");

    return 0;
}

