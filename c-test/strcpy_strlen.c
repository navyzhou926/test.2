#include <stdio.h>

char * strcpy_1(char *a, const char *b)
{
    int i;

    while ((*(a + i) = *(b + i)) != '\0') 
    {
        i++;
    }

    return a;
}

int strlen_1(const char *a)
{
    int i = 0;

    while (*(a + i) != '\0') 
    {
        i++;
    }

    return i;
}

int main(int argc, const char *argv[])
{
    char a[20];
    char b[20] = "Hello world !";

    printf("%s\n",b);
    printf("%s\n",strcpy_1(a, b));
    printf("%d\n",strlen_1(a));

    return 0;
}

