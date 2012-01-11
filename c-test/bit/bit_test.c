#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//typedef  unsigned int uint;
//uint mul(int a, int b)
//{
//int i, len = sizeof(a)*8;
//uint ret = 0;
//for (i = 0; i < len; i++) 
//{
//if(b>>i&0x01)
//ret += a << i;
//}
//return ret;
//}

unsigned int multiply(int m, int n)
{
    int i;
    int temp;
    unsigned int sum = 0;

    for (i = 0; i < sizeof(n)*8; i++) 
    {
        temp = n >> i;
        if(temp & 1)
            sum += (m << i);
    }
    return sum;
}

int main(int argc, const char *argv[])
{
    int a = 15, b = 16;
    int i;
    int num = 0;
    //printf("a = %d, b = %d\n",a, b);
    //printf("a = %d, b = %d\n",(a^b)&b, a&b^a);

    //a = a^b;
    //b = a^b;
    //a = a^b;
    //printf("a = %d, b = %d\n",a, b);
    //printf("a = %d, b = %d\n",a, b);

    printf("%d\n",multiply(11, 14));

    /*
    while (1)
    {
        scanf("%d", &num);
        for (i = 0; i < 32; i++) 
        {
            a = num & 0x80000000;
            if (a)
                printf("%d", 1);
            else
                printf("%d",a);
            num <<= 1;
        }
        printf("\n\n");
    }
    */
    return 0;
}

