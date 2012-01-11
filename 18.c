#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char string[10], str1[10];
    int i;

    for(i=0; i<10;i++)
    {
        str1[i] ='a';
    }
    str1[7] = '\0';
    strcpy(string, str1);
    printf("%s\n",string);

    return 0;
}

