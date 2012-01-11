#include <stdio.h>

int power(int x, int y) //x^y
{
    int out = 1;

    if (y == 0) 
    {
        return 1;
    }
    else
    {
        out = x*power(x, --y);

        return out;
    }
}

int power1(int x, int y)
{
    int sum =0;

    if (y == 0) 
    {
        return sum;
    }
    else
    {
        sum = x*power(x, --y);
    }
}

int power_of_x(int x, int y) //x^y
{
    int i;
    int out = 1;

    for (i = 0; i < y; i++) 
    {
        out = out*x;
    }

    return out;
}

int sum(m, n)
{
    int i;
    int out = 0;

    for (i = 0; i < n; i++) 
    {
        out = out + (n-i)*power_of_x(10, i);
        //out = out + (n-i)*power(i, 10);
    }
    return (out*m);
}

int main(int argc, const char *argv[])
{
    printf("%d\n",power1(3, 3));

    printf("%d\n",sum(2, 5));

    printf("%d\n",power(3, 5));
    printf("%d\n",power_of_x(3, 5));

    return 0;
}


