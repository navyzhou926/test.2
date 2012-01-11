#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if (argc != 2) 
    {
        printf("\ninput wrong\n");
        printf("The format is:\n");
        printf("%s string\n\n", argv[0]);
        exit(1);
    }

    int i = 0; 
    int j = 0;
    int find = 1;

    for (i = 0; *(argv[1] + i) != '\0'; i++) 
    {
        for (j = 0; *(argv[1] + j) != '\0'; j++) 
        {
            if (i != j) 
            {
                if (*(argv[1] + i) == *(argv[1] + j)) 
                {
                    find = 0;
                    break;
                }
            }
        }
        if (find == 1) 
        {
            printf("The first one is '%c'\n", *(argv[1] + i));
            break;
        }
        find = 1;
    }

    return 0;
}
