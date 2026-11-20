/* Q41: Swap the first and last digit of a number. */
#include <stdio.h>

int main(void)
{
    long long number, temp, place = 1;
    long long first, last, middle, result;

    printf("Enter a non-negative number: ");
    if (scanf("%lld", &number) != 1 || number < 0) {
        printf("Invalid input. Enter a non-negative number.\n");
        return 1;
    }

    if (number < 10) {
        printf("Number after swapping = %lld\n", number);
        return 0;
    }

    temp = number;
    while (temp >= 10) {
        temp /= 10;
        place *= 10;
    }

    first = number / place;
    last = number % 10;
    middle = (number % place) / 10;

    result = last * place + middle * 10 + first;

    printf("Number after swapping first and last digits = %lld\n", result);
    return 0;
}
