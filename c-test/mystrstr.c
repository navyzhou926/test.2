#include <stdio.h>
#include <string.h>

#define size 256

int mystrch(char ch, char *str)
{
    int i = 0;
    int count = 0;
    while (*(str + i) != '\0') 
    {
        if (*(str + i) == ch) 
        {
            count++;
        }
        i++;
    }
    return count;
}

int mystrstr(char const *str, char const *srcstr)
{
    int i, j = 0, k = 0;
    int count = 0;
    int len = strlen(str);
    int len1 = strlen(srcstr);

    if ((len == 0) || (len1 == 0)) 
    {
        return 0;
    }

    while (j < (len1-len + 1)) 
    //while (j < (len1/len + 1)) 
    {
        for (i = j; i < len + j; i++) 
        {
            if (*(str + k) != *(srcstr + i)) 
            {
                break;
            }
            k++;
        }
        if (i == (len + j)) 
        {
            count++;
        }
        j++;
        //j = len + j;
        k = 0;
    }

    return count;
}

int str_exchange(char *str, const char *desstr, char *srcstr)
{
    int i, j = 0, k = 0;
    int count = 0;
    int len = strlen(str);
    int len1 = strlen(srcstr);

    if ((len == 0) || (len1 == 0)) 
    {
        return 0;
    }

    while (j < (len1-len + 1)) 
    {
        for (i = j; i < len + j; i++) 
        {
            if (*(str + k) != *(srcstr + i)) 
            {
                break;
            }
            k++;
        }
        if (i == (len + j)) 
        {
            count++;
            i = j;
            for (k = 0; k < len; k++,i++) 
            {
                *(srcstr + i) = *(desstr + k);
            }
        }
        j++;
        k = 0;
    }

    return count;
}

int main(int argc, const char *argv[])
{
    int sum = 0;
    char srcstr[size] = "akasisdsis";
    char str[size] = "sis";
    char changestr[size] = "aka";
    char ch = 's';

    //sum = mystrstr(ch, srcstr);
    //if (sum == 0) 
    //{
        //printf("cannot find %c\n",ch);
        //exit(0);
    //}

    //sum = mystrstr(srcstr, str);

    printf("\n%s\n",srcstr);
    sum = str_exchange(str, changestr, srcstr);
    printf("change %d strings\n",sum);
    printf("%s\n\n",srcstr);

    return 0;
}

