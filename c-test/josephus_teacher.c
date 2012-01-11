#include <stdio.h>
#define N 10

struct people
{
    int id;
    int out;
}a[N];
int main(int argc, const char *argv[])
{
    int i,j,m;
    for (i = 0; i < N; i++) 
    {
        a[i].id = i + 1;
        a[i].out = 0;
    }
    j = 0;
    m = 0;
    for (i = 0; i < 10; i++) 
    {
        for (;;) 
        {
            if (a[m].out == 0) 
            {
                j++;
            }
            if (j == 3) 
            {
                j = 0;
                a[m].out = 1;
                printf("%d\n",a[m].id);
                break;
            }
            m++;
            m = m % N;
        }
    }
    return 0;
}
