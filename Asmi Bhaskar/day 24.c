#include <stdio.h>
#include <stdbool.h>

#define N 9

bool isSafe(int board[N][N], int row, int col, int num) {
    for (int i = 0; i < N; ++i) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; ++i) {
        for (int j = startCol; j < startCol + 3; ++j) {
            if (board[i][j] == num)
                return false;
        }
    }
    return true;
}

bool solveSudoku(int board[N][N]) {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board))
                            return true;
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printSudoku(int board[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int sudoku[N][N] = {
        // Your input Sudoku goes here
        // Replace 0s with the known numbers
    };

    if (solveSudoku(sudoku)) {
        printf("Solved Sudoku:\n");
        printSudoku(sudoku);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
