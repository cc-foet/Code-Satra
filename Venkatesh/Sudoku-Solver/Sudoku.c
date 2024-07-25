#include <stdio.h>
#include <stdbool.h>

bool findEmpty(int sudoku[9][9], int l[2]){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if(sudoku[i][j] == 0){
                l[0] = i;
                l[1] = j;
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int sudoku[9][9], int row, int col, int num){
    for (int i = 0; i < 9; i++){
        if(sudoku[row][i] == num){
            return false;
        }
        if(sudoku[i][col] == num){
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(sudoku[i + startRow][j + startCol] == num){
                return false;
            }
        }
    }
    return true;
}   

bool solveSudoku(int sudoku[9][9]){
    int l[2] = {0,0};
    if (!findEmpty(sudoku,l)){
        return true;
    }

    int row = l[0];
    int col = l[1];

    for (int num = 1; num <= 9; num++){
        if(isSafe(sudoku, row, col, num)){
            sudoku[row][col] = num;
            if(solveSudoku(sudoku)){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}

void main (){
    int sudoku[9][9] = {{0, 1, 7, 2, 3, 0, 0, 0, 0},
                        {4, 3, 0, 0, 0, 0, 0, 7, 1},
                        {0, 0, 0, 0, 7, 0, 3, 6, 0},
                        {0, 4, 0, 0, 5, 0, 0, 0, 0},
                        {2, 7, 0, 6, 0, 0, 0, 5, 0},
                        {5, 0, 9, 0, 8, 0, 7, 0, 3},
                        {0, 0, 0, 0, 0, 0, 0, 0, 5},
                        {8, 5, 6, 0, 0, 0, 1, 2, 7},
                        {0, 0, 0, 5, 0, 8, 0, 0, 6}};

    if (solveSudoku(sudoku)){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
    }
}