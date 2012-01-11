#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int i = 0, j = 0, k = 0, a = 0;
    int b[256] = {0};
    int d[256] = {0};
    
    printf("\n输入字母结束输入\n\n");
    while (scanf("%d", &a) > 0)
    {
        b[k++] = a;
    }

    printf("\n");
    for (i = 0; i < k; i++) 
    {
        if (b[i] % 2 == 1) 
        {
            d[j] = b[i];
            printf("%d ",d[j]);
            j++;
        }
    }
    for (i = 0; i < k; i++) 
    {
        if (b[i] % 2 == 0) 
        {
            d[j] = b[i];
            printf("%d ",d[j]);
            j++;
        }
    }
    printf("\n");

    return 0;
}

