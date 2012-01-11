#include <stdio.h>

#define LEN 10
#define SPACE 3

struct people_t
{
    int ID;
    int out;
};

int josephus_survive(struct people_t *a, int len, int b)
{
    int i = 0, count = 0, sum = 0;
    for (i = 0; i < len; i++) 
    {
        (*(a + i)).ID = i + 1;
        (*(a + i)).out = 0;
    }
    while (1)
    {
        for (i = 0; i < len; i++) 
        {
            if ((*(a + i)).out == 0) 
            {
                count++;
                if (count == b) 
                {
                    count = 0;
                    sum++;
                    //if (sum == 10) 
                    //{
                        //return a[i].ID;
                    //}
                    (*(a + i)).out = 1;
                    printf("%d\t  is out\v\n", (*(a + i)).ID);
                    if (sum == (len-1)) 
                    {
                        for (i = 0; i < len; i++) 
                        {
                            if ((*(a + i)).out == 0) 
                            {
                                return (*(a + i)).ID;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(int argc, const char *argv[])
{
    struct people_t a[LEN]; 
    printf("\n我叫周海军，我是幸存者。\n");
    printf("The surviver's ID is %d\n\n", josephus_survive(a, LEN, SPACE));
    return 0;
}

