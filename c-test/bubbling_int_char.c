#include <stdio.h>
#include <string.h>

#define min_to_max 0
#define max_to_min 1

void print_int_array(int *a, int len)
{
    int i;
    for (i = 0; i < len; i++) 
    {
        printf("%d ",*(a + i));
    }
    printf("\n");
}

void bubbling_int(void *a, int len, int arrangement)
{
    int i, j, k;
    int temp;
    for (j = 0; j <len - 1; j++) 
    {
        for (i = 0; i < len - 1 - j; i++) 
        {
            k = 4*i;
            if (arrangement == 0) 
            {
                if (*(int *)(a + k) > *(int *)( a + k + 4)) 
                {
                    temp = *(int *)(a + k);
                    *(int *)(a + k) = *(int *)(a + k + 4);
                    *(int *)(a + k + 4) = temp;
                }
            }
           if (arrangement == 1) 
             {
                if (*(int *)(a + k) < *(int *)( a + k + 4)) 
                {
                    temp = *(int *)(a + k);
                    *(int *)(a + k) = *(int *)(a + k + 4);
                    *(int *)(a + k + 4) = temp;
                }
            }
        }
    }
}

void bubbling_char(void *a, int len, int arrangement)
{
    int i, j;
    char temp;
    for (j = 0; j <len - 1; j++) 
    {
        for (i = 0; i < len - 1 - j; i++) 
        {
            if (arrangement == 0) 
            {
                if (*(char *)(a + i) > *(char *)( a + i + 1)) 
                {
                    temp = *(char *)(a + i);
                    *(char *)(a + i) = *(char *)(a + i + 1);
                    *(char *)(a + i + 1) = temp;
                }
            }
           if (arrangement == 1) 
             {
                if (*(char *)(a + i) < *(char *)( a + i + 1)) 
                {
                    temp = *(char *)(a + i);
                    *(char *)(a + i) = *(char *)(a + i + 1);
                    *(char *)(a + i + 1) = temp;
                }
            }
        }
    }
}

void bubbling(void *a, int type, int len, int arrangement, void (*fun)(void *a, int len, int arrangement))
{
    if (type == 0) 
    {
        bubbling_char(a, len, arrangement);
    }
    if (type == 1) 
    {
        bubbling_int(a, len, arrangement);
    }
}

int main(int argc, const char *argv[])
{
    int a[] = {7,5,6,3,1,6,3,9,2}; 
    char b[] = {"ialljlaslbnvz"};
    print_int_array(a, sizeof(a)/4);
    bubbling(a, 1, sizeof(a)/4, 0, bubbling_int);
    print_int_array(a, sizeof(a)/4);
    bubbling(a, 1, sizeof(a)/4, 1, bubbling_int);
    print_int_array(a, sizeof(a)/4);
     
    printf("%s\n",b);
    bubbling(b, 0, strlen(b), 0, bubbling_char);
    printf("%s\n",b);
    bubbling(b, 0, strlen(b), 1, bubbling_char);
    printf("%s\n",b);
    return 0;
}

