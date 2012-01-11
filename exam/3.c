#include <stdio.h>
#include <string.h>

#define size 256

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

int main(int argc, const char *argv[])
{
    int i, j;
    char str1[size] = "helloworld nihaoworldzhouhaijundajia world hao";
    char str2[size] = "123haoworldzhouhaijun hello";
    char temp[size];
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len = 0;
    char *srcstr = NULL;
    char *deststr = NULL;
    int maxlen = 0;
    int find = 0;

    memset(temp, 0, sizeof(temp));
    if (len1 > len2) 
    {
        len = len2;
        srcstr = str1;
        deststr = str2;
    }
    else
    {
        len = len1;
        srcstr = str2;
        deststr = str1;
    }

    for (j = 0; j < len; j++) 
    {
        for (i = 0; i < j + 1; i++) 
        {
            strncpy(temp, deststr + i, len-j);
            temp[len-j] = '\0';
            maxlen = mystrstr(temp, srcstr);
            if (maxlen != 0) 
            {
                printf("\nThe max substring is \"%s\"\n", temp);
                printf("\nThe max substring's length is %d\n", strlen(temp));
                find = 1;
                break;
            }
        }
        if (find == 1) break;
    }
    printf("\n");

    return 0;
}

