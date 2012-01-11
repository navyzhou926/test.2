#include <stdio.h>

int main(int argc, const char *argv[])
{
    int score = 35;

    (score >= 90)?(printf("A\n")):((score < 60)?(printf("C\n")):(((score > 60)&&(score < 89))?(printf("B\n")):(printf("error score\n")))); 

    return 0;

}
