#include <stdio.h>
#include <stdlib.h>

void getSpiral(int m, int n, int arr[m][n], int *spiral) {
    int i, row = 0, col = 0, index = 0;
    int original_m = m, original_n = n; // Preserve original dimensions

    while (row < original_m && col < original_n) {
        for (i = col; i < original_n; ++i)
            spiral[index++] = arr[row][i];
        row++;
        for (i = row; i < original_m; ++i)
            spiral[index++] = arr[i][original_n - 1];
        original_n--;
        if (row < original_m) {
            for (i = original_n - 1; i >= col; --i)
                spiral[index++] = arr[original_m - 1][i];
            original_m--;
        }
        if (col < original_n) {
            for (i = original_m - 1; i >= row; --i)
                spiral[index++] = arr[i][col];
            col++;
        }
    }
}

int getKthElement(int m, int n, int arr[m][n], int k) {
    int totalElements = m * n;
    if (k >= totalElements) {
        printf("K exceeds the number of elements in the matrix.\n");
        return -1;
    }
    
    int *spiral = (int *)malloc(totalElements * sizeof(int));
    getSpiral(m, n, arr, spiral);
    int result = spiral[k];
    free(spiral);
    
    return result;
}

int main() {
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int k = 7; // 0-based index

    int element = getKthElement(4, 4, matrix, k);
    if (element != -1) {
        printf("The %dth element in spiral order is: %d\n", k, element);
    }

    return 0;
}
