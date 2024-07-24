import java.util.ArrayList;
import java.util.List;

public class Day23 {
 
    public static void main(String[] args) {
        int N = 4; 
        int[][] solution = solveNQueens(N);
        printSolution(solution);
    }

    public static int[][] solveNQueens(int N) {
        int[][] board = new int[N][N];
        solveNQueensUtil(board, 0, N);
        return board;
    }

    private static boolean solveNQueensUtil(int[][] board, int row, int N) {
        if (row >= N) {
            return true;
        }

        for (int col = 0; col < N; col++) {
            if (isSafe(board, row, col, N)) {
                board[row][col] = 1; 
                if (solveNQueensUtil(board, row + 1, N)) {
                    return true;
                }
                board[row][col] = 0; 
            }
        }
        return false; 
    }

    private static boolean isSafe(int[][] board, int row, int col, int N) {
  
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 1) {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

   
        for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    private static void printSolution(int[][] board) {
        for (int[] row : board) {
            for (int cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
    }
}


