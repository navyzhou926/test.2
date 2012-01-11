#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    char source[15] = "world hello";
    char target[15] = {0};

    swab(source, target, strlen(source));  //change byte
    printf("This is source: %s\n",source);
    printf("This is target: %s\n",target);
    
    return 0;
}

