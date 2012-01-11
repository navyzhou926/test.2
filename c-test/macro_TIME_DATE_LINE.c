#include <stdio.h>

int main(int argc, const char *argv[])
{
    printf("%d\n",__LINE__);
    printf("%s\n",__FILE__);
    printf("%s at %s\n", __DATE__, __TIME__);
    printf("%d\n",__STDC__);

    return 0;
}
