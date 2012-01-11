#include <stdio.h>
#include <string.h>
#include <time.h>

#define size 13
#define size1 52 

int a[4][size] = {0};
int b[size1] = {0};

struct poker
{
    int spade[size];
    int hearts[size];
    int plum_blossom[size];
    int diamonds[size];
}name[4] = {0};

int my_rand(void)
{
    int i, j, temp, count, flag;

    for (j = 0; j < 4; j++) 
    {
        temp = 0;
        count = 1;
        flag = 0;
        a[j][0] = rand()%size + 1;
        while (count < size) 
        {
            temp = rand()%size + 1;
            for (i = 0; i < count; i++) 
            {
                if (temp == a[j][i]) 
                {
                    flag = 1;
                }
            }
            if (flag == 1) 
            {
                flag = 0;
            }
            else
            {
                a[j][count++] = temp;
            }
        }
    }

    printf("\n");
    for (j = 0; j < 4; j++) 
    {
        for (i = 0; i < size; i++) 
        {
            printf("%-5d",a[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}

int my_rand1(void)
{
    int i, j, temp, count, flag;

    b[0] = rand()%size1 + 1;
    while (count < size1) 
    {
        temp = rand()%size1 + 1;
        for (i = 0; i < count; i++) 
        {
            if (temp == b[i]) 
            {
                flag = 1;
            }
        }
        if (flag == 1) 
        {
            flag = 0;
        }
        else
        {
            b[count++] = temp;
        }
    }

    return 0;
}

int deal_poker(void)
{
    int i, j, k = 0;
    int i1, j1, k1, m1;
    int people[4][size] = {0};

    for (i = 0; i < size; i++) 
    {
        for (j = 0; j < 4; j++) 
        {
            people[j][i] = b[k];
            k++;
        }
    }
    //for (i = 0; i < 4; i++) 
    //{
        //for (j = 0; j < size; j++) 
        //{
            //printf("%-5d",people[i][j]);
        //}
        //printf("\n");
    //}

    for (i = 0; i < 4; i++) 
    {
        i1 = 0;
        j1 = 0;
        k1 = 0;
        m1 = 0;
        for (j = 0; j < size; j++) 
        {
            switch ((people[i][j]-1)/size)
            {
                case 0:
                        name[i].spade[i1++] = people[i][j];
                        break;
                case 1:
                        name[i].hearts[j1++] = people[i][j]-size;
                        break;
                case 2:
                        name[i].plum_blossom[k1++] = people[i][j]-size*2;
                        break;
                case 3:
                        name[i].diamonds[m1++] = people[i][j]-size*3;
                        break;
                default : break;        
            }
        }
    }

    return 0;
}

int print_poker(void)
{
    int i = 0, k = 0;
    for (i = 0; i < 4; i++) 
    {
        printf("\n\npeople %d\n",i + 1);
        printf("spade: \n");
        for (k = 0; (name[i].spade[k] != 0) && (k < (size + 1)); k++) 
        {
            printf("%-5d",name[i].spade[k]);
        }

        printf("\nhearts: \n");
        for (k = 0; (name[i].hearts[k] != 0) && (k < (size + 1)); k++) 
        {
            printf("%-5d",name[i].hearts[k]);
        }

        printf("\nplum_blossom: \n");
        for (k = 0; (name[i].plum_blossom[k] != 0) && (k < (size + 1)); k++) 
        {
            printf("%-5d",name[i].plum_blossom[k]);
        }

        printf("\ndiamonds: \n");
        for (k = 0; (name[i].diamonds[k] != 0) && (k < (size + 1)); k++) 
        {
            printf("%-5d",name[i].diamonds[k]);
        }
    }
    printf("\n\n");

    return 0;
}

int main(int argc, const char *argv[])
{
    int i, j, data = 0;

    srand((unsigned int)time(NULL));

    my_rand1();
    deal_poker();
    print_poker();

    return 0;
}

