/* Q69: Find the second largest distinct element in an array */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int n;

    printf("Enter size of array: ");
    if (scanf("%d", &n) != 1 || n < 2) {
        printf("At least two elements are required.\n");
        return 1;
    }

    int *a = (int *)malloc((size_t)n * sizeof(int));
    if (a == NULL) return 1;

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) { free(a); return 1; }
    }

    int largest = INT_MIN, second = INT_MIN;
    int has_largest = 0, has_second = 0;

    for (int i = 0; i < n; i++) {
        if (!has_largest || a[i] > largest) {
            if (has_largest) {
                second = largest;
                has_second = 1;
            }
            largest = a[i];
            has_largest = 1;
        } else if (a[i] < largest && (!has_second || a[i] > second)) {
            second = a[i];
            has_second = 1;
        }
    }

    if (has_second)
        printf("Second largest distinct element: %d\n", second);
    else
        printf("No second largest distinct element exists.\n");

    free(a);
    return 0;
}
