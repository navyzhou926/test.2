#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i = 0;
    int count = 0;
    char *b[256];
    char a[] = "I like this game !";
    char *p, *q;
    char *s = NULL;
    //if (argc < 1) 
    //{
    //printf("please input a separator !\n");
    //return 0;
    //}
    p = q = a;
    while (1)
    {
        //s = strtok_r(p, argv[1], &q);
        s = strtok_r(p, " ", &q);
        if (s == NULL) 
        {
            break;
        }
        b[count] = s;
        count++;
        //printf("s = %s\n",s);
        //printf("q = %s\n\n",q);
        p = q;
    }
    for (i = 0; i < count; i++) 
    {
        printf("%s\n",*(b + i));
    }
    return 0;
}
