#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i, j;

    for (i = 1; i < 10; i++) 
    {
        for (j = 1; j < i + 1; j++) 
        {
            printf("%d*%d = %-3d ",j, i, i*j);
        }
        printf("\n");
    }

    return 0;
}
