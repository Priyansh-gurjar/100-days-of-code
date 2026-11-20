/* Q63: Merge two arrays */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n1, n2;

    printf("Enter size of first array: ");
    if (scanf("%d", &n1) != 1 || n1 < 0) return 1;

    int *a = (int *)malloc((size_t)(n1 ? n1 : 1) * sizeof(int));
    if (a == NULL) return 1;

    printf("Enter %d elements: ", n1);
    for (int i = 0; i < n1; i++) {
        if (scanf("%d", &a[i]) != 1) { free(a); return 1; }
    }

    printf("Enter size of second array: ");
    if (scanf("%d", &n2) != 1 || n2 < 0) { free(a); return 1; }

    int *b = (int *)malloc((size_t)(n2 ? n2 : 1) * sizeof(int));
    if (b == NULL) { free(a); return 1; }

    printf("Enter %d elements: ", n2);
    for (int i = 0; i < n2; i++) {
        if (scanf("%d", &b[i]) != 1) { free(a); free(b); return 1; }
    }

    int *merged = (int *)malloc((size_t)(n1 + n2 ? n1 + n2 : 1) * sizeof(int));
    if (merged == NULL) { free(a); free(b); return 1; }

    for (int i = 0; i < n1; i++) merged[i] = a[i];
    for (int i = 0; i < n2; i++) merged[n1 + i] = b[i];

    printf("Merged array: ");
    for (int i = 0; i < n1 + n2; i++) printf("%d ", merged[i]);
    printf("\n");

    free(a);
    free(b);
    free(merged);
    return 0;
}
