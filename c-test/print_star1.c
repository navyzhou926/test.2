#include <stdio.h>

typedef void (* print_t)(char);
typedef float (* flo)(char, char, char);

float average(char a, char b, char c)
{
    float e;

    e = (a + b + c)/3.0;

    return e;
}

void print_symbol(char width)
{
    char i;

    for (i = 0; i < width; i++) 
    {
        printf("* ");
    }
}

void print_matrix(char length)
{
    char i;
    //void  (* fun1)(char );
    print_t fun1;
    fun1 = print_symbol;
    for (i = 0; i < length; i++) 
    {
        fun1(length);
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    float f;
    flo ave = average;
    argv++;
    f = ave((*(argv[0])-'0'), (*(argv[1])-'0'), (*(argv[2])-'0'));
    //f = ave((*(argv[0])-'0'), ((argv[0][1])-'0'), ((argv[0][2])-'0'));
    printf("\nThe average of three number is %f\n", f);
    
    print_t fun = print_matrix;
    printf("\nThe rank of matrix is %s\n",*argv);
    fun((*(argv[0])-'0'));
    //(fun)(**(argv)-'0');

    return 0;
}

