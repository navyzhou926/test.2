#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertion(int *a, int len)
{
    int i, j, temp;
    for (i = 0; i < len; i++) 
    {
        temp = a[i + 1];
        for (j = i; temp < a[j] && j>=1; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

int main(int argc, const char *argv[])
{
    int i;
    int a[] = {9,5,7,6,5,1,8,3};

    printf("a[8] is %d\n",a[8]);
    insertion(a, sizeof(a)/4);
    for (i = 0; i < sizeof(a)/4; i++) 
    {
        printf("%d ",*(a + i));
    }
    printf("\n");
    return 0;
}
