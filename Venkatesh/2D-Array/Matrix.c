#include <stdio.h>
#include <stdlib.h>

void spiral(int m, int n, int matrix[m][n], int* result) {
    int rowStart = 0, rowEnd = m - 1;
    int colStart = 0, colEnd = n - 1;
    int index = 0;

    while (rowStart <= rowEnd && colStart <= colEnd) {
        for (int i = colStart; i <= colEnd; i++) {
            result[index++] = matrix[rowStart][i];
        }
        rowStart++;

        for (int i = rowStart; i <= rowEnd; i++) {
            result[index++] = matrix[i][colEnd];
        }
        colEnd--;

        if (rowStart <= rowEnd) {
            for (int i = colEnd; i >= colStart; i--) {
                result[index++] = matrix[rowEnd][i];
            }
        }
        rowEnd--;

        if (colStart <= colEnd) {
            for (int i = rowEnd; i >= rowStart; i--) {
                result[index++] = matrix[i][colStart];
            }
        }
        colStart++;
    }
}

void main() {
    int m = 4, n = 4;
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int k = 7;

    int* result = (int*)malloc(m * n * sizeof(int));

    spiral(m, n, matrix, result);

    printf("%d", result[k-1]);

    free(result);
}