public class Backtracking {
    public static boolean isSafe(int[][] board, int row, int col, int n) {
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 1) {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }
        return true;
    }

    public static boolean solve(int[][] board, int col, int n) {
        if (col >= n) {
            return true;
        }
        for (int i = 0; i < n; i++) {
            if (isSafe(board, i, col, n)) {
                board[i][col] = 1;
                if (solve(board, col + 1, n)) {
                    return true;
                }
                board[i][col] = 0;
            }
        }
        return false;
    }

    public static int[][] nQueens(int n) {
        int[][] board = new int[n][n];
        if (!solve(board, 0, n)) {
            return new int[0][0];
        }
        return board;
    }

    public static void printSolution(int[][] board, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int n = 4;
        int[][] soln = nQueens(n);
        if (soln.length == 0) {
            System.out.println("No solution exists");
        } else {
            printSolution(soln, n);
        }
    }
}
