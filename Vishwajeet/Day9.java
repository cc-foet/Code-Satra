// Problem: Find the K-th element of spiral order traversal of a matrix

public class Day9 {
    public static int findKthSpiralElement(int[][] matrix, int K) {
        int M = matrix.length;    // Number of rows
        int N = matrix[0].length; // Number of columns

        if (K > M * N) {
            throw new IllegalArgumentException("K is greater than the number of elements in the matrix");
        }

        int top = 0, bottom = M - 1;
        int left = 0, right = N - 1;
        int count = 0;

        while (top <= bottom && left <= right) {
            // Traverse from left to right
            for (int i = left; i <= right; i++) {
                count++;
                if (count == K) {
                    return matrix[top][i];
                }
            }
            top++;

            // Traverse from top to bottom
            for (int i = top; i <= bottom; i++) {
                count++;
                if (count == K) {
                    return matrix[i][right];
                }
            }
            right--;

            // Traverse from right to left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    count++;
                    if (count == K) {
                        return matrix[bottom][i];
                    }
                }
                bottom--;
            }

            // Traverse from bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    count++;
                    if (count == K) {
                        return matrix[i][left];
                    }
                }
                left++;
            }
        }

        throw new IllegalArgumentException("K is out of the bounds of the spiral traversal");
    }

    public static void main(String[] args) {
        int[][] matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        };
        int K = 7;
        System.out.println("The " + K + "-th element in spiral order is: " + findKthSpiralElement(matrix, K));
    }
}
