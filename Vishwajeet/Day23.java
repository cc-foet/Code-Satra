// Problem: Given an integer N, place N queens on an NxN chessboard so that no two queens threat each other. Return output in the form of a 2D array with 1 showing the position of the queen and 0 showing an empty space.

// N-Queens Problem [Backtracking]

// Time Complexity: O(N!) because we are trying to place N queens on the board in N rows and N columns. In each row, we are checking if the queen can be placed in the current cell or not. So, the time complexity is O(N!) where N is the number of queens to be placed on the board.

// Space Complexity: O(N^2) because we are using a 2D array of size NxN to store the board configuration.

import java.util.Scanner;

public class Day23 {
    // Function to check if a queen can be placed at board[row][col]
    private static boolean isSafe(int[][] board, int row, int col, int N) {
        // Check this row on left side
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 1) {
                return false;
            }
        }

        // Check upper diagonal on left side
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        // Check lower diagonal on left side
        for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    // Function to solve the N-Queens problem using backtracking
    private static boolean solveNQueensUtil(int[][] board, int col, int N) {
        // Base case: If all queens are placed, then return true
        if (col >= N) {
            return true;
        }

        // Consider this column and try placing this queen in all rows one by one
        for (int i = 0; i < N; i++) {
            if (isSafe(board, i, col, N)) {
                // Place this queen in board[i][col]
                board[i][col] = 1;

                // Recur to place rest of the queens
                if (solveNQueensUtil(board, col + 1, N)) {
                    return true;
                }

                // If placing queen in board[i][col] doesn't lead to a solution
                // then remove the queen from board[i][col]
                board[i][col] = 0; // Backtrack
            }
        }

        // If the queen cannot be placed in any row in this column, then return false
        return false;
    }

    // Function to solve the N-Queens problem
    public static int[][] solveNQueens(int N) {
        int[][] board = new int[N][N];

        if (!solveNQueensUtil(board, 0, N)) {
            System.out.println("Solution does not exist");
            return new int[0][0]; // Return an empty array if no solution exists
        }

        return board;
    }

    // Main method to test the function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input N from user
        System.out.println("Enter the value of N:");
        int N = scanner.nextInt();

        // Solve the N-Queens problem and print the solution
        int[][] solution = solveNQueens(N);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(solution[i][j] + " ");
            }
            System.out.println();
        }

        scanner.close();
    }
}
