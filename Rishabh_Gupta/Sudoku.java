public class Sudoku {
    public static boolean findEmptyCell(int[][] grid, int[] position) {
        int minOptions = 10; // More than the maximum number of options (1-9)
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (grid[row][col] == 0) {
                    int options = countOptions(grid, row, col);
                    if (options < minOptions) {
                        minOptions = options;
                        position[0] = row;
                        position[1] = col;
                    }
                }
            }
        }
        return minOptions != 10;
    }

    public static int countOptions(int[][] grid, int row, int col) {
        boolean[] possible = new boolean[10]; // Possible numbers 1-9
        for (int i = 1; i <= 9; i++) {
            possible[i] = true;
        }

        for (int i = 0; i < 9; i++) {
            if (grid[row][i] != 0) {
                possible[grid[row][i]] = false;
            }
            if (grid[i][col] != 0) {
                possible[grid[i][col]] = false;
            }
        }

        int startRow = row - row % 3;
        int startCol = col - col % 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i + startRow][j + startCol] != 0) {
                    possible[grid[i + startRow][j + startCol]] = false;
                }
            }
        }

        int count = 0;
        for (int i = 1; i <= 9; i++) {
            if (possible[i]) {
                count++;
            }
        }
        return count;
    }

    public static boolean isSafeToPlace(int[][] grid, int row, int col, int num) {
        for (int i = 0; i < 9; i++) {
            if (grid[row][i] == num || grid[i][col] == num) {
                return false;
            }
        }

        int startRow = row - row % 3;
        int startCol = col - col % 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i + startRow][j + startCol] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    public static boolean solveSudoku(int[][] grid) {
        int[] position = {0, 0};
        if (!findEmptyCell(grid, position)) {
            return true;
        }

        int row = position[0];
        int col = position[1];

        for (int num = 1; num <= 9; num++) {
            if (isSafeToPlace(grid, row, col, num)) {
                grid[row][col] = num;
                if (solveSudoku(grid)) {
                    return true;
                }
                grid[row][col] = 0;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int[][] sudoku = {
            {3, 9, 0, 6, 5, 0, 0, 0, 7},
            {0, 6, 8, 0, 0, 2, 9, 0, 0},
            {4, 0, 0, 9, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 8, 0, 0},
            {6, 7, 0, 0, 0, 0, 0, 4, 9},
            {1, 0, 0, 7, 4, 0, 0, 0, 0},
            {0, 4, 0, 8, 0, 0, 0, 3, 2},
            {0, 0, 0, 3, 7, 0, 0, 0, 0},
            {0, 5, 3, 0, 2, 0, 7, 0, 4}
        };

        if (solveSudoku(sudoku)) {
            for (int row = 0; row < 9; row++) {
                for (int col = 0; col < 9; col++) {
                    System.out.print(sudoku[row][col] + " ");
                }
                System.out.println();
            }
        }
    }
}
