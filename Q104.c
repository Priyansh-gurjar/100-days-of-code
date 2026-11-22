#include <stdio.h>
#include <math.h>

// Find the pivot integer x in O(1) time complexity
// Sum(1..x) == Sum(x..n)  =>  x^2 == n * (n + 1) / 2
int findPivotInteger(int n) {
    long long total = (long long)n * (n + 1) / 2;
    long long x = (long long)sqrt((double)total);

    // Adjust for any floating-point rounding inaccuracy
    while ((x + 1) * (x + 1) <= total) {
        x++;
    }
    while (x * x > total) {
        x--;
    }

    if (x * x == total) {
        return (int)x;
    }
    return -1;
}

int main(void) {
    int n;
    printf("Enter a positive integer n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    int pivot = findPivotInteger(n);
    printf("%d\n", pivot);

    return 0;
}
