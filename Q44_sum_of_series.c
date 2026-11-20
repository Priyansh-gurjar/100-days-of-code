/* Q44: Find the sum of the series:
   1 + 3/4 + 5/6 + 7/8 + ... up to n terms. */
#include <stdio.h>

int main(void)
{
    int n, i;
    long double sum = 1.0L;

    printf("Enter the number of terms: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Enter a positive number of terms.\n");
        return 1;
    }

    for (i = 2; i <= n; i++) {
        long double numerator = 2.0L * i - 1.0L;
        long double denominator = 2.0L * i;
        sum += numerator / denominator;
    }

    printf("Sum of the series = %.6Lf\n", sum);
    return 0;
}
