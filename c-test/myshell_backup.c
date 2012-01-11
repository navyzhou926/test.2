#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cmd
{
    //char *command[8];
    char command[8][256];
    char in[256];
    char out[256];
}x, *p = &x;

void analysis_cmd(char *a)
{
    int i = 0, j = 0, k = 0;
    int flag = 1;
    int in_i = 0, out_i = 0;
    int len;
    //p = (struct cmd *)malloc(300);
    while (*(a + i) != '\0') 
    {
        if ((*(a + i) != ' ') && (*(a + i) != '>') && (*(a + i) != '<')) 
        {
            x.command[j][k] = *(a + i);
            k++;
            if (flag == 1) 
            {
                flag = 0;
            }
        }

        if ((*(a + i) == ' ') && (flag == 0)) 
        {
            flag = 1;
            x.command[j][k] = '\0';
            j++;
            k = 0;
        }

        if ((*(a + i) == '>') && (flag == 1)) 
        {
            len = j;
            out_i = j;
        }    
        if ((*(a + i) == '<') && (flag == 1)) 
        {
            len = j;
            in_i = j;
        }
        i++;
    }

    //if (flag == 1) 
    //{
        //i = 0;
        //while (x.command[j][i] != ' ')
        //{
        //i++;
        //}    
        //x.command[j][k] = '\0';
        //}
    if (in_i > 0) 
    {
        strcpy(x.in, x.command[in_i]);
    }
    if (out_i > 0) 
    {
        strcpy(x.out, x.command[out_i]);
    }
    printf("\ncommand: %s\n",x.command[0]);
    for (i = 1; i < len; i++) 
    {
        printf("argument: %s\n",x.command[i]);
    }
    printf("in_file: %s\n",x.in);
    printf("out_file: %s\n\n",x.out);
}

int main(int argc, const char *argv[])
{
    char a[] = "  ls  -a  ";
    char b[256];
    strcpy(x.in, "NULL");
    strcpy(x.out, "NULL");
    gets(b);
    analysis_cmd(b);
    return 0;
}

