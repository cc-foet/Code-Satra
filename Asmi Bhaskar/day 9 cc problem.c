#include <stdio.h>

int findKthElementInSpiral(int matrix[][4], int m, int n, int k) {
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    int count = 0;
    int targetIndex = k - 1;
    
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            if (count == targetIndex) {
                return matrix[top][i];
            }
            count++;
        }
        top++;
        
        for (int i = top; i <= bottom; i++) {
            if (count == targetIndex) {
                return matrix[i][right];
            }
            count++;
        }
        right--;
        
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                if (count == targetIndex) {
                    return matrix[bottom][i];
                }
                count++;
            }
            bottom--;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                if (count == targetIndex) {
                    return matrix[i][left];
                }
                count++;
            }
            left++;
        }
    }
    
    return -1;
}

int main() {
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int k = 7;
    int m = 4;
    int n = 4;
    
    int result = findKthElementInSpiral(matrix, m, n, k);
    if (result != -1) {
        printf("The %dth element in the spiral order is %d\n", k, result);
    } else {
        printf("The %dth element is out of bounds\n", k);
    }
    
    return 0;
}
