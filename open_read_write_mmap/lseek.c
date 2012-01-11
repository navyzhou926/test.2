#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define N 100

int main(int argc, const char *argv[])
{
    int fd;
    char a[N] = "hello world !";
    off_t currpos;

    //fd = open("akaedu", O_RDWR);
    fd = open("akaedu", O_RDWR | O_CREAT, 00776);
    if (fd < 0) 
    {
        perror("open akaedu");
        exit(1);
    }
    
    currpos = lseek(fd, 100, SEEK_SET);
    if (currpos == -1) 
    {
        perror("lseek");
        exit(1);
    }
    printf("%ld\n", currpos);
    write(fd, a, strlen(a));

    close(fd);

    return 0;
}

