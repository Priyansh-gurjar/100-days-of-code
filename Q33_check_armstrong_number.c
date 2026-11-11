#include <stdio.h>

int main()
{
    int n, original, temp, digit, count = 0;
    int i, power, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("%d is not an Armstrong number.", n);
    }
    else
    {
        original = n;
        temp = n;

        if (temp == 0)
        {
            count = 1;
        }

        while (temp > 0)
        {
            count++;
            temp = temp / 10;
        }

        temp = n;

        while (temp > 0)
        {
            digit = temp % 10;
            power = 1;

            for (i = 1; i <= count; i++)
            {
                power = power * digit;
            }

            sum = sum + power;
            temp = temp / 10;
        }

        if (sum == original)
        {
            printf("%d is an Armstrong number.", original);
        }
        else
        {
            printf("%d is not an Armstrong number.", original);
        }
    }

    return 0;
}
