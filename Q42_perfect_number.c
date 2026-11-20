/* Q42: Check whether a number is a perfect number.
   A perfect number equals the sum of its positive proper divisors. */
#include <stdio.h>

int main(void)
{
    long long number, sum = 1, i;

    printf("Enter a positive number: ");
    if (scanf("%lld", &number) != 1 || number <= 0) {
        printf("Invalid input. Enter a positive number.\n");
        return 1;
    }

    if (number == 1) {
        sum = 0;
    } else {
        /* Add divisors in pairs, without adding the number itself. */
        for (i = 2; i <= number / i; i++) {
            if (number % i == 0) {
                sum += i;
                if (i != number / i)
                    sum += number / i;
            }
        }
    }

    if (sum == number)
        printf("%lld is a perfect number.\n", number);
    else
        printf("%lld is not a perfect number.\n", number);

    return 0;
}
