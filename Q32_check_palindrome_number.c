#include <stdio.h>

int main()
{
    int n, original, remainder, reverse = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    original = n;

    if (n < 0)
    {
        printf("%d is not a palindrome.", original);
    }
    else
    {
        while (n != 0)
        {
            remainder = n % 10;
            reverse = reverse * 10 + remainder;
            n = n / 10;
        }

        if (original == reverse)
        {
            printf("%d is a palindrome.", original);
        }
        else
        {
            printf("%d is not a palindrome.", original);
        }
    }

    return 0;
}
