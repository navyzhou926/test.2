#include <stdio.h>
#include <string.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

extern unsigned char girl[];
extern unsigned char girl1[];

int main(int argc, const char *argv[])
{
    unsigned int i;
    unsigned char *p; 

    int fd = open("/dev/fb0", O_RDWR);
    p = mmap(NULL, 1024*768*4, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

    for (i = 0; i < 1024*768*4; i++) 
    {
        //p[i] = girl[i];
        p[i] = girl1[i];
    }
    close(fd);
    return 0;
}

