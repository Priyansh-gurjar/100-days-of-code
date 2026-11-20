#include <stdio.h>

int main(void)
{
    int row, space, number;

    /* Print the pattern:
           5
          45
         345
        2345
       12345
    */
    for (row = 1; row <= 5; row++)
    {
        /* Right-align each row. */
        for (space = 1; space <= 5 - row; space++)
        {
            printf(" ");
        }

        /* Print digits from (6 - row) up to 5. */
        for (number = 6 - row; number <= 5; number++)
        {
            printf("%d", number);
        }

        printf("\n");
    }

    return 0;
}
