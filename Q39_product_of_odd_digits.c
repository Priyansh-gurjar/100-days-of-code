/* Q39: Find the product of the odd digits of a number. */
#include <stdio.h>

int main(void)
{
    long long number, n, product = 1;
    int digit, found = 0;

    printf("Enter a number: ");
    if (scanf("%lld", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (number < 0) {
        printf("Please enter a non-negative number.\n");
        return 1;
    }

    n = number;

    while (n > 0) {
        digit = (int)(n % 10);
        if (digit % 2 != 0) {
            product *= digit;
            found = 1;
        }
        n /= 10;
    }

    if (found)
        printf("Product of odd digits = %lld\n", product);
    else
        printf("The number has no odd digits.\n");

    return 0;
}
