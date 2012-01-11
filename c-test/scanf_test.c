#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a, b;
    char c, d;

    while (1)
    {
        //c = getchar();
        //printf("%c\n",&c);
        //getchar();
        #if 0
        scanf("%c %c",&c, &d);
        getchar();
        printf("%c %c\n",c, d);
        #endif

        scanf(" %d %d ",&a, &b);
        printf("%d %d\n",a, b);
    }

    return 0;
}

