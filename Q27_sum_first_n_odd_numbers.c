#include <stdio.h>

int main()
{
    int n, i, odd = 1;
    long long sum = 0;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        sum = sum + odd;
        odd = odd + 2;
    }

    printf("Sum of first %d odd numbers = %lld", n, sum);

    return 0;
}
