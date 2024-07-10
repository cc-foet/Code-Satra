public class PrintSpiral {
    static int[][] SpiralOrder(int[][] matrix, int r, int c) {
        int topRow = 0, bottomRow = r - 1, leftCol = 0, rightCol = c - 1;
        int totalElements = 0;
        int[][] ans = new int[r][c];
        int I = 0, J = 0;

        while (totalElements < r * c) {
            // topRow -> leftCol to rightCol
            for (int j = leftCol; j <= rightCol && totalElements < r * c; j++) {
                ans[I][J] = matrix[topRow][j];
                totalElements++;
                J++;
            }
            topRow++;
            I++;

            // rightCol -> topRow to BottomRow
            for (int i = topRow; i <= bottomRow && totalElements < r * c; i++) {
                ans[I][J] = matrix[i][rightCol];
                totalElements++;
                I++;
            }
            rightCol--;
            J--;

            // bottomRow -> rightCol to leftCol
            for (int j = rightCol; j >= leftCol && totalElements < r * c; j--) {
                ans[I][J] = matrix[bottomRow][j];
                totalElements++;
                J--;
            }
            bottomRow--;
            I--;

            // leftCol -> bottomRow to topRow
            for (int i = bottomRow; i >= topRow && totalElements < r * c; i--) {
                ans[I][J] = matrix[i][leftCol];
                totalElements++;
                I--;
            }
            leftCol++;
            J++;
        }
        return ans;
    }

    public static void main(String[] args) {
        int[][] arr = {{1, 2, 3, 4},
                       {5, 6, 7, 8},
                       {9, 10, 11, 12},
                       {13, 14, 15, 16}};
        int[][] ans = SpiralOrder(arr, 4, 4);
        int k = 7;
        int c =4,r=4;

        // Retrieve the Kth element from the spiral order
        int kRow = (k - 1) / c; // Row index
        int kCol = (k - 1) % c; // Column index
        int kElement = ans[kRow][kCol];

        System.out.println("Kth element in spiral order: " + kElement);
    }
}
