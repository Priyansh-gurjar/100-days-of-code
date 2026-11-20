#include <stdio.h>

int main(void)
{
    int row, space, star, spaces, count;

    /*
       Print a centered diamond with star counts:
       1, 3, 5, 7, 5, 3, and 1.
    */
    for (row = 1; row <= 7; row++)
    {
        if (row <= 4)
        {
            spaces = 4 - row;
            count = 2 * row - 1;
        }
        else
        {
            spaces = row - 4;
            count = 2 * (8 - row) - 1;
        }

        for (space = 1; space <= spaces; space++)
        {
            printf(" ");
        }

        for (star = 1; star <= count; star++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
