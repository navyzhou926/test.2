#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct substring_t 
{
    int addr;
    int len;
}ch, *p = &ch;

get_max_substring_1(char *a)
{
    int i = 0, j = 1;
    int max_len = 1;
    int address, address1;

    while (*(a + i) != '\0') 
    {
        i++;
        if (*(a + i - 1) == *(a + i)) 
        {
            j++;
            if (j == 2) 
            {
                address1 = i - 1;
            }
        }
        else
        {
            if (j > max_len) 
            {
                max_len = j;
                address = address1;
            }
            j = 1;
        }
    }
    ch.addr = address;
    ch.len = max_len;
}

get_max_substring_2(char *a)
{
    int i = 0, j = 1;
    int max_len = 1;
    int address, address1;
    //struct substring_t *q;
    while (*(a + i) != '\0') 
    {
        i++;
        if (*(a + i - 1) == *(a + i)) 
        {
            j++;
            if (j == 2) 
            {
                address1 = i - 1;
            }
        }
        else
        {
            if (j > max_len) 
            {
                max_len = j;
                address = address1;
            }
            j = 1;
        }
    }
    p->addr = address;
    p->len = max_len;
}

char *b;
char * get_max_substring_3(char *a)
{
    int i = 0, j = 1;
    int max_len = 1;
    int address, address1;
    //char b[sizeof(a)];
    while (*(a + i) != '\0') 
    {
        i++;
        if (*(a + i - 1) == *(a + i)) 
        {
            j++;
            if (j == 2) 
            {
                address1 = i - 1;
            }
        }
        else
        {
            if (j > max_len) 
            {
                max_len = j;
                address = address1;
            }
            j = 1;
        }
    }
    for (i = 0; i <max_len; i++) 
    {
        *(b + i) = *(a + address + i);
    }
    *(b + i) = '\0';
    return b;
}

int main(int argc, const char *argv[])
{
    char a[] = "aabhhhhhhhhhhbbcddddddd"; 
    int i = 0;

    printf("\n%s\n",a);
    b = (char *)malloc(sizeof(a));
    printf("\n%s\n\n",get_max_substring_3(a));
    free(b);

    get_max_substring_1(a);
    for (i = ch.addr; i < (ch.len + ch.addr); i++) 
    {
        printf("%c", a[i]);
    }
    printf("\n\n");

    get_max_substring_2(a);
    for (i = (p->addr); i < ((p->len) + (p->addr)); i++) 
        //for (i = ((*p).addr); i < (((*p).len) + ((*p).addr)); i++) 
    {
        printf("%c", a[i]);
    }
    printf("\n\n");

    return 0;
}

