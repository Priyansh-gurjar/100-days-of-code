/* Q66: Insert an element in a sorted array at the appropriate position */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, value;

    printf("Enter size of sorted array: ");
    if (scanf("%d", &n) != 1 || n < 0) return 1;

    int *a = (int *)malloc((size_t)(n + 1) * sizeof(int));
    if (a == NULL) return 1;

    printf("Enter %d elements in sorted order: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) { free(a); return 1; }
    }

    printf("Enter element to insert: ");
    if (scanf("%d", &value) != 1) { free(a); return 1; }

    int pos = 0;
    while (pos < n && a[pos] <= value) pos++;

    for (int i = n; i > pos; i--) a[i] = a[i - 1];
    a[pos] = value;

    printf("Array after insertion: ");
    for (int i = 0; i < n + 1; i++) printf("%d ", a[i]);
    printf("\n");

    free(a);
    return 0;
}
