#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHAR 1
#define INT 4

int find_number_int1(void *a, int type, int len, void num)
{
    int i;

    for (i = 0; i < len; i++) 
    {
        if (*(int *)(a + type*i) == (int)num) 
        {
            return i;
        }
    } 

    return -1;
}

int find_number_char1(void *a, int type, int len, void num)
{
    int i;

    for (i = 0; i < len; i++) 
    {
        if (*(char *)(a + type*i) == (char)num) 
        {
            return i;
        }
    }

    return -1;
}

int find_number_int2(void *a, int type, int len, void num)
{
    int head, middle, end;

    head = 0;
    middle = (len-1)/2; 
    end = len-1;
    while (head <= end) 
    {
        if ((int)num == *(int *)(a + type*middle)) 
        {
            return middle;
        }
        else if ((int)num > *(int *)(a + type*middle)) 
        {
            head = middle + 1;
            middle = (end + head)/2; 
        }
        else
        {
            end = middle - 1;
            middle = (end + head)/2; 
        }
    }

    return -1;
}

int find_number_char2(void *a, int type, int len, void num)
{
    int head, middle, end;

    head = 0;
    middle = (len-1)/2; 
    end = len-1;
    while (head <= end) 
    {
        if ((char)num == *(char *)(a + type*middle)) 
        {
            return middle;
        }
        else if ((char)num > *(char *)(a + type*middle)) 
        {
            head = middle + 1;
            middle = (end + head)/2; 
        }
        else
        {
            end = middle - 1;
            middle = (end + head)/2; 
        }
    }

    return -1;
}

int find_number_int_char(void *a, int type, int len, char num, int (* fun)(void *a, int type, int len, void num))
{
    return fun(a, type, len, num);
}

int main(int argc, const char *argv[])
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    char str[] = {"abcdefghijk"};
    int temp = 0;

    temp = find_number_int_char(a, INT, sizeof(a)/4, 3, find_number_int1);
    printf("%d\n",temp);
    temp = find_number_int_char(a, INT, sizeof(a)/4, 3, find_number_int2);
    printf("%d\n",temp);

    temp = find_number_int_char(str, CHAR, strlen(str), 'd', find_number_char1);
    printf("%d\n",temp);
    temp = find_number_int_char(str, CHAR, strlen(str), 'd', find_number_char2);
    printf("%d\n",temp);

    return 0;
}

