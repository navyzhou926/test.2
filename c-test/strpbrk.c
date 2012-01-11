#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char *string1 = "abcdefghijklmnopqrstuvwxyz";
    char *string2 = "conm";
    char *p;

    p = strpbrk(string1, string2);

    if (p) 
    {
        printf("strpbrk found fisrt character: %c\n",*p);
    }
    else
    {
        printf("strpbrk didn't find character in set\n");
    }
    
    return 0;
}
