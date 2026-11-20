#include <stdio.h>

int main(void)
{
    int row, star, count;

    /*
       Print an hourglass pattern with 1, 3, 5, 7, 9,
       7, 5, 3, and 1 stars.
    */
    for (row = 1; row <= 9; row++)
    {
        if (row <= 5)
        {
            count = 2 * row - 1;
        }
        else
        {
            count = 2 * (10 - row) - 1;
        }

        for (star = 1; star <= count; star++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
