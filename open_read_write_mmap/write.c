#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
    int fd;
    char a[] = "hello world";

    //fd = open("akaedu", O_RDWR);
    fd = open("akaedu", O_RDWR | O_CREAT, 00776);
    if (fd < 0) 
    {
        perror("open");
        exit(1);
    }

    printf("%d\n",fd);
    write(fd, a, strlen(a));

    close(fd);

    return 0;
}

