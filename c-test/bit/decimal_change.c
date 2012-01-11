#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void decimal_to_binary(int num)
{
    char count = 0, i = 0;
    int m;
    int a[256];

    if ((num == 0) || (num == 1)) 
    {
        printf("binary is : %d\n\n", num);
        return;
    }
    else if (num < 0) 
    {
        printf("binary is : ");
        for (i = 0; i < 32; i++) 
        {
            m = num & 0x80000000;
            if (m)
                printf("%d", 1);
            else
                printf("%d",m);
            num <<= 1;
        }
        printf("\n\n");
        return;
    }
    else
    {
        while (m != 1)
        {
            m = num/2;
            a[count++] = num%2;
            num = m;
        }
        a[count] = m;
        printf("binary is : ");
        for (i = count; i > -1; i--) 
        {
            printf("%d", a[i]);
        }
        printf("\n\n");
    }
}

void decimal_to_hex(int num)
{
    int count = 0, i = 0, temp;
    int a[8];
    for (i = 7; i > -1; i--) 
    {
        temp = num & 0xf;
        num >>= 4;
        if (temp > 9) 
        {
            a[i] = temp + 55;
            continue;
        }
        a[i] = temp + '0';
    }

    printf("hex is : 0x");
    for (i = 0; i < 8; i++) 
    {
        printf("%c",a[i]);
    }
    printf("\n\n");
}

int main(int argc, const char *argv[])
{
    int num = 0;
    while (1) 
    {
        if(scanf("%d", &num) == 0)
        {
            printf("please input right data\n\n");
            return 1;
        }
        decimal_to_binary(num);
        decimal_to_hex(num);
    }
    return 0;
}

