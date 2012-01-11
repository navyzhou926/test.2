#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, const char *argv[])
{
    char buf[MAX_SIZE] = {0};
    char *p;

    //p = getcwd(buf, MAX_SIZE);
    p = getcwd(buf, strlen(buf));
    if (p == NULL) 
    {
        //printf("getcwd error !\n");
        perror("getcwd error !");
        exit(1);
    }
    printf("Current working directory is: %s\n",buf);

    
    return 0;
}

