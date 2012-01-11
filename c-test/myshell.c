#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cmd
{
    char *command[8];
    char *in;
    char *out;
};

void analysis_cmd(char *a)
{
    int i = 0, j = 0, k = 0;
    int flag = 1, flag1 = 0;
    int in_i = 0, out_i = 0;
    int len;
    struct cmd x, *p = &x;

    for (i = 0; i < 8; i++) 
    {
        p->command[i] = (char *)malloc(256);
    }
    p->in = (char *)malloc(256);
    p->out = (char *)malloc(256);
    strcpy(p->in, "NULL");
    strcpy(p->out, "NULL");
    i = 0;
    while (*(a + i) != '\0') 
    {
        if ((*(a + i) != ' ') && (*(a + i) != '>') && (*(a + i) != '<')) 
        {
            p->command[j][k] = *(a + i);
            k++;
            if (flag == 1) 
            {
                flag = 0;
            }
        }

        if ((*(a + i) == ' ') && (flag == 0)) 
        {
            flag = 1;
            p->command[j][k] = '\0';
            j++;
            k = 0;
        }

        if (*(a + i) == '>') 
        {
            if (flag == 1) 
            {
                out_i = j;
            }
            if (flag == 0)  
            {
                flag = 1;
                p->command[j][k] = '\0';
                k = 0;
                out_i = ++j;
            }
            flag1 = 1;
        }    

        if (*(a + i) == '<') 
        {
            if (flag == 1) 
            {
                in_i = j;
            }
            if (flag == 0)  
            {
                flag = 1;
                p->command[j][k] = '\0';
                k = 0;
                in_i = ++j;
            }
            flag1 = 1;
        }    
        i++;
    }
    
    if (j == 0) 
    {
        if ((*(a + i) == '\0') && (*(a + i - 1) !=0)) 
        {
            j++;
        }
        else
            return;
    }
    if (flag1 == 0) 
        len = j + 1;
    if (flag1 == 1) 
        len = j;
    //if (flag == 1) 
    //{
        //i = 0;
        //while (x.command[j][i] != ' ')
        //{
        //i++;
        //}    
        //x.command[j][k] = '\0';
        //}

    printf("\ncommand: %s\n",p->command[0]);
    for (i = 1; i < len; i++) 
    {
        printf("argument: %s\n",p->command[i]);
    }
    if (in_i > 0) 
    {
        sprintf(p->in, "%s%c", p->command[in_i], '\0');
        printf("\nin_file: %s\n",p->command[in_i]);
        printf("out_file: %s\n\n",p->out);
    }
    if (out_i > 0) 
    {
        printf("\nin_file: %s\n",p->in);
        sprintf(p->out, "%s%c", p->command[out_i], '\0');
        printf("out_file: %s\n\n",p->command[out_i]);
    }

    for (i = 0; i < 8; i++)
    {
        free(p->command[i]);
    }
    free(p->in);
    free(p->out);
}

int main(int argc, const char *argv[])
{
    char a[] = "  ls  -a  ";
    char b[256];
    while (1) 
    {
        gets(b);
        //fgets(b, 256, stdin);
        analysis_cmd(b);
    }
    return 0;
}

