/* Q67: Insert an element in an array at a given position */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, position, value;

    printf("Enter size of array: ");
    if (scanf("%d", &n) != 1 || n < 0) return 1;

    int *a = (int *)malloc((size_t)(n + 1) * sizeof(int));
    if (a == NULL) return 1;

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) { free(a); return 1; }
    }

    printf("Enter position (1 to %d) and value: ", n + 1);
    if (scanf("%d %d", &position, &value) != 2) { free(a); return 1; }

    if (position < 1 || position > n + 1) {
        printf("Invalid position.\n");
        free(a);
        return 1;
    }

    int index = position - 1;
    for (int i = n; i > index; i--) a[i] = a[i - 1];
    a[index] = value;

    printf("Array after insertion: ");
    for (int i = 0; i < n + 1; i++) printf("%d ", a[i]);
    printf("\n");

    free(a);
    return 0;
}
