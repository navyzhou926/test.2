#include <stdio.h>

int main(int argc, const char *argv[])
{
    char x,y,z;
    char a[50];
    char b[50];
    int c[3];
    int i=0;

    while ((x = getchar()) != ' ') 
    {
        a[i++] = x;
    }
    a[i] = '\0';
    i = 0;
    while ((x = getchar()) != '\n') 
    {
        b[i++] = x;
    }
    b[i] = '\0';
    printf("%s %s\n",b,a);

    return 0;
}

