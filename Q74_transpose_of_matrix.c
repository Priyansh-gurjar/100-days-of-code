/* Q74: Find the transpose of a matrix */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rows, cols;

    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0)
        return 1;

    int *matrix = (int *)malloc((size_t)rows * cols * sizeof(int));
    if (matrix == NULL) return 1;

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i * cols + j]) != 1) {
                free(matrix);
                return 1;
            }
        }
    }

    printf("Transpose of the matrix:\n");
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++)
            printf("%d\\t", matrix[i * cols + j]);
        printf("\n");
    }

    free(matrix);
    return 0;
}
