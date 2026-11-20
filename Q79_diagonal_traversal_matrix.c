/* Q79: Perform diagonal traversal of a matrix.
   Traversal order: diagonals run from top-left toward bottom-right.
   Each diagonal is printed starting at the top row, then the first column. */
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

    printf("Diagonal traversal: ");
    /* Start each diagonal from the top row. */
    for (int startCol = 0; startCol < cols; startCol++) {
        int i = 0, j = startCol;
        while (i < rows && j < cols) {
            printf("%d ", matrix[i * cols + j]);
            i++;
            j++;
        }
    }

    /* Continue with diagonals starting below the top-left corner. */
    for (int startRow = 1; startRow < rows; startRow++) {
        int i = startRow, j = 0;
        while (i < rows && j < cols) {
            printf("%d ", matrix[i * cols + j]);
            i++;
            j++;
        }
    }
    printf("\n");

    free(matrix);
    return 0;
}
