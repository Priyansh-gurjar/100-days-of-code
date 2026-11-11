#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Please enter a positive number.");
    }
    else
    {
        printf("Factors of %d are: ", n);

        for (i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                printf("%d ", i);
            }
        }
    }

    return 0;
}
