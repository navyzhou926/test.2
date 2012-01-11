#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define N 1024

int main(int argc, const char *argv[])
{
    int fd1, fd2;
    char str[N];
    struct stat buf;

    if (argc != 3) 
    {
        printf("input wrong !\n");
        exit(1);
    }

    fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0) 
    {
        perror("open");
        exit(1);
    }

    fd2 = open(argv[2], O_RDWR | O_CREAT, 00776);
    if (fd2 < 0) 
    {
        perror("open");
        exit(1);
    }

    stat(argv[1], &buf);

    while (read(fd1, str, buf.st_size) > 0)
    {
        write(fd2, str, buf.st_size);
    }

    close(fd1);
    close(fd2);

    return 0;
}

