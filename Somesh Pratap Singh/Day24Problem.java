public class Sudoku {
    public static boolean findEmpty(int[][] sudoku, int[] l) {
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (sudoku[i][j] == 0) {
                    l[0] = i;
                    l[1] = j;
                    return true;
                }
            }
        }
        return false;
    }

    public static boolean isSafe(int[][] sudoku, int row, int col, int num) {
        for (int i = 0; i < 9; i++) {
            if (sudoku[row][i] == num) {
                return false;
            }
            if (sudoku[i][col] == num) {
                return false;
            }
        }

        int startRow = row - row % 3;
        int startCol = col - col % 3;

        for (int k = 0; k < 3; k++) {
            for (int j = 0; j < 3; j++) {
                if (sudoku[k + startRow][j + startCol] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    public static boolean sudokuSolve(int[][] sudoku) {
        int[] l = {0, 0};
        if (!findEmpty(sudoku, l)) {
            return true;
        }

        int row = l[0];
        int col = l[1];

        for (int num = 1; num <= 9; num++) {
            if (isSafe(sudoku, row, col, num)) {
                sudoku[row][col] = num;
                if (sudokuSolve(sudoku)) {
                    return true;
                }
                sudoku[row][col] = 0;
            }
        }
    return false;
    }
    public static void main(String[] args) {
        int[][] sudoku = {{3, 9, 0, 6, 5, 0, 0, 0, 7},
                          {0, 6, 8, 0, 0, 2, 9, 0, 0},
                          {4, 0, 0, 9, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 8, 0, 0},
                          {6, 7, 0, 0, 0, 0, 0, 4, 9},
                          {1, 0, 0, 7, 4, 0, 0, 0, 0},
                          {0, 4, 0, 8, 0, 0, 0, 3, 2},
                          {0, 0, 0, 3, 7, 0, 0, 0, 0},
                          {0, 5, 3, 0, 2, 0, 7, 0, 4}};
        
        if (sudokuSolve(sudoku)) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    System.out.print(sudoku[i][j] + " ");
                }
                System.out.println();
            }
        }
    }    
}
