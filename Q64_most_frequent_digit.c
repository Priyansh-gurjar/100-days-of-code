/* Q64: Find the digit that occurs most often in an integer number */
#include <stdio.h>

int main(void) {
    long long number;
    int frequency[10] = {0};

    printf("Enter an integer: ");
    if (scanf("%lld", &number) != 1) return 1;

    /* This conversion also safely handles the most negative long long value. */
    unsigned long long value =
        (number < 0) ? 0ULL - (unsigned long long)number
                     : (unsigned long long)number;

    if (value == 0) {
        frequency[0] = 1;
    } else {
        while (value > 0) {
            frequency[value % 10]++;
            value /= 10;
        }
    }

    int digit = 0;
    for (int i = 1; i <= 9; i++) {
        if (frequency[i] > frequency[digit]) digit = i;
    }

    printf("Most frequent digit: %d\n", digit);
    printf("Occurrences: %d\n", frequency[digit]);
    return 0;
}
