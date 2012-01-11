#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int i = 0, n =10;
    int *p;
    int a;

    p = (int *)malloc(4*n);
    if (p == NULL) 
    {
    return 1;
    }
    scanf("%d", &a);
    while (1) 
    {
        if (i > n) 
        {
            n = n + 10;
            p = (int *)realloc(p, 4*n); 
            if (p == NULL) 
            {
                return 1;
            }
        }
        if (a < 0) 
        {
            break;
        }
        *(p + i) = a;
        i++;
        scanf("%d", &a);
    }
    for (i = 0; *(p + i) != '\0'; i++) 
    {
        printf("%d ",*(p + i));
    }
    printf("\n");
    free(p);

    return 0;
}
