/* Q68: Delete an element from an array using its position */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, position;

    printf("Enter size of array: ");
    if (scanf("%d", &n) != 1 || n < 0) return 1;

    int *a = (int *)malloc((size_t)(n ? n : 1) * sizeof(int));
    if (a == NULL) return 1;

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) { free(a); return 1; }
    }

    if (n == 0) {
        printf("Array is empty; nothing to delete.\n");
        free(a);
        return 0;
    }

    printf("Enter position to delete (1 to %d): ", n);
    if (scanf("%d", &position) != 1) { free(a); return 1; }

    if (position < 1 || position > n) {
        printf("Invalid position.\n");
        free(a);
        return 1;
    }

    int index = position - 1;
    for (int i = index; i < n - 1; i++) a[i] = a[i + 1];

    printf("Array after deletion: ");
    for (int i = 0; i < n - 1; i++) printf("%d ", a[i]);
    printf("\n");

    free(a);
    return 0;
}
