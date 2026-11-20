/* Q40: Find and print the 1's complement of a binary number.
   This solution uses arithmetic and loops, not arrays or strings. */
#include <stdio.h>

int main(void)
{
    long long binary, temp, complement = 0, place = 1;
    int digit, digits = 0;

    printf("Enter a binary number: ");
    if (scanf("%lld", &binary) != 1 || binary < 0) {
        printf("Invalid input. Enter a non-negative binary number.\n");
        return 1;
    }

    temp = binary;
    if (temp == 0)
        digits = 1;

    /* Check every digit and construct the complemented number. */
    while (temp > 0) {
        digit = (int)(temp % 10);
        if (digit != 0 && digit != 1) {
            printf("Invalid binary number. Use only 0 and 1.\n");
            return 1;
        }

        complement += (long long)(1 - digit) * place;
        digits++;
        temp /= 10;
        if (temp > 0)
            place *= 10;
    }

    /* For input 0, its 1's complement is 1. */
    if (binary == 0)
        complement = 1;

    /* Keep the original number of bits, including a leading zero. */
    printf("1's complement = %0*lld\n", digits, complement);

    return 0;
}
