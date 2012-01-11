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

void bubbling_int(int *a, int len, int arrangement)
{
    int i, j;
    int temp;
    for (j = 0; j < len - 1; j++) 
    {
        for (i = 0; i < len - 1 - j; i++) 
        {
            if (arrangement == 0) 
            {
                if (*(a + i) > *( a + i + 1)) 
                {
                    temp = *(a + i);
                    *(a + i) = *(a + i + 1);
                    *(a + i + 1) = temp;
                }
            }
            if (arrangement == 1) 
            {
                if (*(a + i) < *( a + i + 1)) 
                {
                    temp = *(a + i);
                    *(a + i) = *(a + i + 1);
                    *(a + i + 1) = temp;
                }
            }
        }
    }
}

void bubbling_char(char *a, int len, int arrangement)
{
    int i, j;
    char temp;

    for (j = 0; j <len-1; j++) 
    {
        for (i = 0; i < len-1-j; i++) 
        {
            if (arrangement == 0) 
            {
                if (*(a + i) > *( a + i + 1)) 
                {
                    temp = *(a + i);
                    *(a + i) = *(a + i + 1);
                    *(a + i + 1) = temp;
                }
            }
            if (arrangement == 1) 
            {
                if (*(a + i) < *( a + i + 1)) 
                {
                    temp = *(a + i);
                    *(a + i) = *(a + i + 1);
                    *(a + i + 1) = temp;
                }
            }
        }
    }
}

int main(int argc, const char *argv[])
{
    int a[] = {7,5,6,3,1,6,3,9,2}; 
    char b[] = {"ialljlaslbnvz"};

    bubbling_int(a, sizeof(a)/4, 1);
    print_int_array(a, sizeof(a)/4);
    bubbling_int(a, sizeof(a)/4, 0);
    print_int_array(a, sizeof(a)/4);

    bubbling_char(b, strlen(b), 1);
    printf("%s\n",b);
    bubbling_char(b, strlen(b), 0);
    printf("%s\n",b);

    return 0;
}

