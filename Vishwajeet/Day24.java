// Problem: Sudoku Solver: Given an unsolved Sudoku in the form of a 9x9 matrix, where empty cells are represented by 0, Solve the Sudoku and display the solution.

// Time Complexity: O(9^(n*n)), where n is the number of rows/columns in the Sudoku board. Because we have 9 choices for each cell, and there are n*n cells in total.
// Space Complexity: O(n*n), where n is the number of rows/columns in the Sudoku board. The space is used to store the board.

import java.util.Scanner;

public class Day24 {

    // Function to check if it's valid to place num in board[row][col]
    private static boolean isValid(int[][] board, int row, int col, int num) {
        // Check the row
        for (int x = 0; x < 9; x++) {
            if (board[row][x] == num) {
                return false;
            }
        }

        // Check the column
        for (int x = 0; x < 9; x++) {
            if (board[x][col] == num) {
                return false;
            }
        }

        // Check the 3x3 sub-grid
        int startRow = row - row % 3, startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + startRow][j + startCol] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    // Function to solve the Sudoku puzzle using backtracking
    private static boolean solveSudoku(int[][] board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                // Search for an empty cell
                if (board[row][col] == 0) {
                    for (int num = 1; num <= 9; num++) {
                        if (isValid(board, row, col, num)) {
                            board[row][col] = num;

                            // Recursively try to fill the board
                            if (solveSudoku(board)) {
                                return true;
                            }

                            // Backtrack if placing num doesn't lead to a solution
                            board[row][col] = 0;
                        }
                    }

                    // If no valid number is found, return false
                    return false;
                }
            }
        }
        return true; // Solved successfully
    }

    // Function to print the Sudoku board
    private static void printBoard(int[][] board) {
        for (int r = 0; r < 9; r++) {
            for (int d = 0; d < 9; d++) {
                System.out.print(board[r][d]);
                System.out.print(" ");
            }
            System.out.print("\n");

            if ((r + 1) % 3 == 0)
                System.out.print("");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Example Sudoku puzzle (unsolved)
        int[][] board = {
            {3, 0, 6, 5, 0, 8, 4, 0, 0},
            {5, 2, 0, 0, 0, 0, 0, 0, 0},
            {0, 8, 7, 0, 0, 0, 0, 3, 1},
            {0, 0, 3, 0, 1, 0, 0, 8, 0},
            {9, 0, 0, 8, 6, 3, 0, 0, 5},
            {0, 5, 0, 0, 9, 0, 6, 0, 0},
            {1, 3, 0, 0, 0, 0, 2, 5, 0},
            {0, 0, 0, 0, 0, 0, 0, 7, 4},
            {0, 0, 5, 2, 0, 6, 3, 0, 0}
        };

        System.out.println("Unsolved Sudoku puzzle:");
        printBoard(board);

        if (solveSudoku(board)) {
            System.out.println("\nSolved Sudoku puzzle:");
            printBoard(board);
        } else {
            System.out.println("No solution exists.");
        }

        scanner.close();
    }
}
