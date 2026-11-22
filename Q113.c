#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort (ascending order)
int compareInt(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int main(void) {
    int n, k;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    int *arr = (int *)malloc((size_t)n * sizeof(int));
    if (!arr) {
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    if (scanf("%d", &k) != 1 || k <= 0 || k > n) {
        printf("Invalid k\n");
        free(arr);
        return 1;
    }

    qsort(arr, (size_t)n, sizeof(int), compareInt);
    printf("%d\n", arr[k - 1]);

    free(arr);
    return 0;
}
