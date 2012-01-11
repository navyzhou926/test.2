#include <stdio.h>
#include <string.h>

int find_number_int1(int *a, int len, int num)
{
    int i;

    for (i = 0; i < len; i++) 
    {
        if (*(a + i) == num) 
        {
            return i;
        }
    }
    return -1;
}

int find_number_char1(char *a, int len, char ch)
{
    int i;
    for (i = 0; i < len; i++) 
    {
        if (*(a + i) == ch) 
        {
            return i;
        }
    }
    return -1;
}

int find_number_int2(int *a, int len, int num)
{
    int i, head, middle, end;
    head = 0;
    middle = (len-1)/2; 
    end = len-1; 
    while (head <= end) 
    {
        if (num == *(a + middle)) 
        {
            return middle;
        }
        else if (num > *(a + middle)) 
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

int find_number_char2(char *a, int len, char ch)
{
    int i, head, middle, end;
    head = 0;
    middle = (len-1)/2; 
    end = len-1;
    while (head <= end) 
    {
        if (ch == *(a + middle)) 
        {
            return middle;
        }
        else if (ch > *(a + middle)) 
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

int main(int argc, const char *argv[])
{
    //int a[] = {3,5,2,5,7,8,-6,1,10,-3};
    int a[] = {1,2,3,4,5,6,7,8,9};
    char str[] = {"abcdefghijk"};
    int temp = 0;

    temp = find_number_int1(a, sizeof(a)/4, 3);
    printf("%d\n",temp);
    temp = find_number_int2(a, sizeof(a)/4, 3);
    printf("%d\n",temp);

    temp = find_number_char1(str, strlen(str), 'd');
    printf("%d\n",temp);
    temp = find_number_char2(str, strlen(str), 'd');
    printf("%d\n",temp);

    return 0;
}


