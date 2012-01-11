#include <stdio.h>
#include <stdlib.h>
#include <sys/type.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>

int main(int argc, const char *argv[])
{
    int fd = 0; 
    struct hiddev_devinfo device_info; 

    if (argc != 2)   
    { 
        fprintf(stderr, "usage: %s hiddevice - probably /dev/usb/hiddev0\n", argv[0]); 
        exit(1); 
    } 
    if ((fd = open(argv[1], O_RDONLY)) < 0)   
    { 
        perror("hiddev open"); 
        exit(1); 
    } 
    else 
    { 
        printf("Open_OK!"); 
    } 

    ioctl(fd, HIDIOCGDEVINFO, &device_info); 

    printf("vendor 0x%04hx product 0x%04hx version 0x%04hx ",device_info.vendor, device_info.product, device_info.version); 

    return 0;
}

