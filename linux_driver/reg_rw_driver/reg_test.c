#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define REG_READ  0
#define REG_WRITE 1

typedef struct register_rw
{
    unsigned int reg;
    unsigned int value;
}reg_rw;

int main(int argc, char **argv)
{
    int fd;
    reg_rw test_reg;

    fd = open("/dev/register_rw", 0);
    if (fd < 0) 
    {
        perror("open device register_rw");
        exit(1);
    }

    test_reg.reg = 0x01c4005c;  //read
    if (ioctl(fd, REG_READ, &test_reg) < 0) //读出的值放在 test_reg->value 
        printf("read register error\n");
    else
        printf("1:reg: 0x%x\tvalue: 0x%x\n",test_reg.reg, test_reg.value);

    //由于有些寄存器的某些位是保留的，写1无效，所以即使往里写1，某些位也会是默认值
    test_reg.reg = 0x01c4005c;  //write
    test_reg.value = 0x30305;
    if (ioctl(fd, REG_WRITE, &test_reg) < 0)
        printf("write register error\n");
    else
        printf("2:reg: 0x%x\tvalue: 0x%x\n",test_reg.reg, test_reg.value);

    test_reg.reg = 0x01c4005c;  //read
    if (ioctl(fd, REG_READ, &test_reg) < 0)
        printf("read register error\n");
    else
        printf("3:reg: 0x%x\tvalue: 0x%x\n",test_reg.reg, test_reg.value);

    close(fd);

    return 0;
}


