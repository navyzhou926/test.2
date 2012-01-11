#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fd;
    int ch;
    if ((fd = fopen("file", "w+")) == NULL) 
    {
        perror("Open file error\n");
        exit(1);
    }
    while ((ch = getchar()) != '\n')
    {
        fputc(ch, fd);
    }
    rewind(fd);
    while ((ch = fgetc(fd)) != EOF) 
    {
        putchar(ch);
    }
    putchar('\n');
    fclose(fd);
    
    return 0;
}
