#include <stdio.h>

typedef struct  
{
    char ch;
    int len;
    int pos;
}info_t;

void substr(char str[], info_t *res)
{
    int max_i = 0, max_l = 0, cur_i = 0, cur_l = 0, i = 0;

    for (i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] == str[i + 1]) 
        {
            cur_l++;
        }
        else
        {
            if (++cur_l > max_l) 
            {
                max_l = cur_l;
                max_i = cur_i;
            }
            cur_i = i + 1, cur_l = 0;
        }
    }
    res->ch = str[max_i];
    res->len = max_l;
    res->pos = max_i;

    return ;
}

int main(int argc, const char *argv[])
{
    char *str = "aabbbcchhhhheee";
    info_t res;

    substr(str, &res);
    printf("\n%c\n",res.ch);
    printf("%d\n",res.len);
    printf("%d\n\n",res.pos);

    return 0;
}

