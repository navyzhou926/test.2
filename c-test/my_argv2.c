#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char buf[1024] = "   abc      123     efg   456       hello  world  ";
    char *my_argv[10];
    int i = 0;
    int my_argc = 0;
    int state = 0;

    #if 0
    while (buf[i] != '\0') 
    {
        if (buf[i] != ' ' && state == 0) 
        {
            my_argv[my_argc++] = buf + i;
            state = 1;
        }
        if (buf[i] == ' ' && state == 1) 
        {
            buf[i] = '\0';
            state = 0;
        }
        i++;
    }
    #else
    while (buf[i] != '\0')
    {
        if (buf[i] != ' ' && state == 0) 
        {
            my_argv[my_argc++] = buf + i;
            state = 1;
        }
        if (buf[i] == ' ' && state == 1) 
        {
            buf[i] = '\0';
            state = 0;
        }
        i++;
    }
    #endif

    printf("my_argc = %d\n",my_argc);
    for (i = 0; i < my_argc; i++) 
    {
        printf("%s.\n",my_argv[i]);
    }

    return 0;
}

