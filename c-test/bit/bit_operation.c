#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define ESC 27

void decimal_to_binary(int num)
{
    char count = 0, i = 0;
    int m;
    int a[256];
    if ((num == 0) || (num == 1)) 
    {
        printf("binary is : %d\n", num);
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
        printf("\n");
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
        printf("\n");
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

char upper_lower_change(char ch)
{
    if ((ch >= 'a') && (ch <= 'z')) 
    {
        return ch - 32;
    }
    else if ((ch >= 'A') && (ch <= 'Z')) 
    {
        return ch + 32;
    }
    else
    {
        return 0;
    }
}

char encrypt_char(char ch)
{
    char temp = '&';
    return temp^ch;
}

void meun(void)
{
    printf("1. HexBinDec_change\n");
    printf("2. multiply_operation\n");
    printf("3. character_upper_lower_change\n");
    printf("4. character_encryption\n");
    printf("5. exit\n\n");
    printf("please select one of choices above:\n\n");
}

int main(int argc, const char *argv[])
{
    int num = 0;
    int n1 = 0, n2 = 0;
    int choice = 0;
    char ch;

    system("clear");
    meun();
    scanf("%d",&choice);
    while (1)
    {
        switch (choice)
        {
            case 1:
            {
                printf("\nplease input decimal number:\n");
                if(scanf("%d",&num) == 0)
                {
                    printf("Please input right number\n\n");
                    usleep(1500000);
                    system("./a.out");
                    system("clear");
                    return 1;
                }
                decimal_to_binary(num);
                decimal_to_hex(num);
                break;
            }
            case 2:
            {
                printf("\nplease input two numbers:\n");
                if(scanf("%d%d",&n1, &n2) == 1)
                {
                    printf("Please input right number\n\n");
                    usleep(1500000);
                    system("./a.out");
                    system("clear");
                    return 1;
                }
                printf("The out of the multiply is:%d\n\n",multiply(n1, n2));
                break;
            }
            case 3:
            {
                getchar();
                printf("\nplease input one character:\n");
                printf("Press ESC to back to meun\n\n");
                scanf("%c",&ch);
                if (ch == ESC) 
                {
                    system("clear");
                    meun();
                    scanf("%d",&choice);
                    break;
                }
                ch = upper_lower_change(ch);
                //fflush(stdin);
                if (ch == 0) 
                {
                    printf("please input right character\n\n");
                    //usleep(2000000);
                    sleep(2);
                    break;
                }
                printf("%c\n\n",ch);
                break;
            }
            case 4:
            {
                getchar();
                printf("\nplease input one character to encrypt:\n");
                printf("Press ESC to back to meun\n\n");
                scanf("%c",&ch);
                if (ch == ESC) 
                {
                    system("clear");
                    meun();
                    scanf("%d",&choice);
                    break;
                }
                ch = encrypt_char(ch);
                if (ch < 33) 
                {
                    printf("After encrypted it becomes invisible character:%c\n\n",ch);
                    break;
                }
                printf("After encrypted it becomes visible character:%c\n\n",ch);
                break;
            }
            case 5:
            {
                return 0;
            }
            default :
            {
                printf("Wrong choice\n\n");
                sleep(1);
                system("clear");
                meun();
                scanf("%d",&choice);
                break;
            }
        }
    }
    return 0;
}
