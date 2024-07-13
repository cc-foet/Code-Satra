/*
Given an n x n matrix and a number x, find the position of x in the matrix if it is present in it. Otherwise, print “Not Found”.
*/

#include<stdio.h>
#include<stdbool.h>

bool staircaseSearch(int mat[4][4], int key){
    int row = 3;
    int col = 0; 

    while(row >= 0 && col < 4){
        if(mat[row][col] == key){
            printf("Key at : (%d,%d)\n", row, col);
            return true;
        } 
        else if(key < mat[row][col]){
            row--;
        } 
        else{
            col++;
        }
    }
    printf("Not Found!\n");
    return false;
}

int main() {
    int mat[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };

    int key = 37;
    staircaseSearch(mat, key);
    return 0;
}
/*
Output : Key at : (2,2)
*/
