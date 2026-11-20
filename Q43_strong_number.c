/* Q43: Check whether a number is a strong number.
   A strong number equals the sum of the factorials of its digits. */
#include <stdio.h>

int main(void)
{
    long long number, temp;
    unsigned long long sum = 0;
    int digit, i;

    printf("Enter a non-negative number: ");
    if (scanf("%lld", &number) != 1 || number < 0) {
        printf("Invalid input. Enter a non-negative number.\n");
        return 1;
    }

    temp = number;
    do {
        unsigned long long factorial = 1;
        digit = (int)(temp % 10);

        for (i = 1; i <= digit; i++)
            factorial *= (unsigned long long)i;

        sum += factorial;
        temp /= 10;
    } while (temp > 0);

    if (sum == (unsigned long long)number)
        printf("%lld is a strong number.\n", number);
    else
        printf("%lld is not a strong number.\n", number);

    return 0;
}
