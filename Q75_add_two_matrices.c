/* Q75: Add two matrices */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rows, cols;

    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0)
        return 1;

    size_t count = (size_t)rows * cols;
    int *a = (int *)malloc(count * sizeof(int));
    int *b = (int *)malloc(count * sizeof(int));
    if (a == NULL || b == NULL) {
        free(a);
        free(b);
        return 1;
    }

    printf("Enter elements of first matrix:\n");
    for (size_t i = 0; i < count; i++) {
        if (scanf("%d", &a[i]) != 1) {
            free(a); free(b);
            return 1;
        }
    }

    printf("Enter elements of second matrix:\n");
    for (size_t i = 0; i < count; i++) {
        if (scanf("%d", &b[i]) != 1) {
            free(a); free(b);
            return 1;
        }
    }

    printf("Sum of the matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d\\t", a[i * cols + j] + b[i * cols + j]);
        printf("\n");
    }

    free(a);
    free(b);
    return 0;
}
