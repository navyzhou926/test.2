#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i = 1;
    int j = 1;
    int k = 1;

    printf("%d %d %d \n",i++, ++i, i++);
    printf("i = %d\n\n",i);
    printf("%d %d %d \n",++j, j++, j++);
    printf("j = %d\n\n",j);
    printf("%d %d %d \n",k++, k++, ++k);
    printf("k = %d\n\n",k);

    i = 1; j = 1; k = 1;
    printf("%d %d %d \n",++i, ++i, i++);
    printf("i = %d\n\n",i);
    printf("%d %d %d \n",++j, j++, ++j);
    printf("j = %d\n\n",j);
    printf("%d %d %d \n",k++, ++k, ++k);
    printf("k = %d\n\n",k);

    return 0;
}
