#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int fd1;
    int fd2;
    struct stat buf;
    unsigned char *src = NULL, *dest = NULL;

    if (argc != 3) 
    {
        printf("\ninput wrong !\n");
        printf("The input format is:\n");
        printf("%s src dest\n\n",argv[0]);
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
    src = mmap(NULL, buf.st_size, PROT_READ, MAP_SHARED, fd1, 0);
    if (src == MAP_FAILED) 
    {
        perror("map");
        exit(1);
    }

    lseek(fd2, buf.st_size-1, SEEK_SET);
    write(fd2, "0", 1);
    dest = mmap(NULL, buf.st_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd2, 0);
    if (dest == MAP_FAILED) 
    {
        perror("map");
        exit(1);
    }

    memcpy(dest, src, buf.st_size);

    munmap(src, buf.st_size);
    munmap(dest, buf.st_size);
    close(fd1);
    close(fd2);
    printf("File copy finished\n");

    return 0;
}

