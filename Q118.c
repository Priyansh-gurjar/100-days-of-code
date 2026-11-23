#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 0) {
        return 1;
    }

    long long expected_sum = (long long)n * (n + 1) / 2;
    long long actual_sum = 0;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        actual_sum += val;
    }

    printf("%lld\n", expected_sum - actual_sum);
    return 0;
}
