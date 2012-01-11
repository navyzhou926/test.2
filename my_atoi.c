#include <stdio.h>
#include <stdlib.h>

int my_atoi(const char *str)
{
    int i = 0;
    int ret = 0;

    while (*(str + i) != '\0') 
    {
        if (*(str + i) > '9' || *(str + i) < '0') 
        {
            return ret;
        }
        ret = ret*10 + (*(str + i)-'0');
        i++;
    }

    return ret;
}

int main(int argc, const char *argv[])
{
    printf("atoi is: %d\n",atoi("hello world"));
    printf("atoi is: %d\n",my_atoi("123hello world"));
    printf("atoi is: %d\n",my_atoi("123456"));
    
    return 0;
}

