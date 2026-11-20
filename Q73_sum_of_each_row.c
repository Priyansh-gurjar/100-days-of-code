/* Q73: Find the sum of each row of a matrix and store it in an array */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rows, cols;

    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0)
        return 1;

    int *matrix = (int *)malloc((size_t)rows * cols * sizeof(int));
    long long *rowSum = (long long *)calloc((size_t)rows, sizeof(long long));
    if (matrix == NULL || rowSum == NULL) {
        free(matrix);
        free(rowSum);
        return 1;
    }

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i * cols + j]) != 1) {
                free(matrix);
                free(rowSum);
                return 1;
            }
            rowSum[i] += matrix[i * cols + j];
        }
    }

    printf("Sum of each row:\n");
    for (int i = 0; i < rows; i++)
        printf("Row %d: %lld\n", i + 1, rowSum[i]);

    free(matrix);
    free(rowSum);
    return 0;
}
