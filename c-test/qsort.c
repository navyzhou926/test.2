#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

int sort_function(const void *a, const void *b)
{
    return (strcmp(a, b));
}

int main(int argc, const char *argv[])
{
    int i;
    char list[5][MAX_LENGTH] = {"cat", "car", "capwe", "caphelo", "can"};

    //qsort((void *)list, 5, sizeof(list[0]), sort_function);
    qsort((void *)list, 5, MAX_LENGTH, sort_function);
    for (i = 0; i < 5; i++) 
    {
        printf("%s\n",list[i]);
    }
    
    return 0;
}

