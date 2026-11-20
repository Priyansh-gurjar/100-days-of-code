#include <stdio.h>

int main(void)
{
    int group, star, count;

    /*
       Reproduces the arrangement shown in the question:
       one star, a blank line, three stars, a blank line,
       five stars, a blank line, three stars, a blank line,
       and one star. Each star is on its own line.
    */
    for (group = 1; group <= 5; group++)
    {
        if (group == 1 || group == 5)
        {
            count = 1;
        }
        else if (group == 2 || group == 4)
        {
            count = 3;
        }
        else
        {
            count = 5;
        }

        for (star = 1; star <= count; star++)
        {
            printf("*\n");
        }

        /* Keep the blank-line gap visible between groups. */
        if (group < 5)
        {
            printf("\n");
        }
    }

    return 0;
}
