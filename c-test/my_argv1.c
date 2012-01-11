#include <stdio.h>
#include <string.h>

#define MAXSIZE 4096

int main(int argc, const char *argv[])
{
    int i = 0;
    char buf[MAXSIZE] = "    abc     123   efg   456  hello     ";
    char *my_argv[10];
    char *p = NULL;
    int my_argc = 0;

    while (*(buf + i) == ' ')
        i++;

    my_argv[my_argc] = buf + i;
    for (; *(buf + i) != '\0' ; i++) 
    {
        if (*(buf + i) == ' ') 
        {
            while (*(buf + i) == ' ')
            {
                *(buf + i) = '\0';
                i++;
            }
            i--;
            *(buf + i) = '\0';
            my_argc++;
            my_argv[my_argc] = buf + i + 1;
        }
    }

    printf("my_argc = %d\n",my_argc);
    for (i = 0; i < my_argc; i++) 
    {
        printf("%s.\n",my_argv[i]);
    }

    return 0;
}

