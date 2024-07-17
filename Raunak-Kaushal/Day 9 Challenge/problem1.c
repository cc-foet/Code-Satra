/*
Day 9 Problem : Given an MXN matrix where M is the number of rows and N is the number of columns and an integer K (<M*N), print the Kth element of the matrix in spiral form.

Input: Matrix = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15, 16}}
k = 7

Output: 16
*/



#include <stdio.h>

int findelementInSpiral(int m, int n, int mat[][4], int k){
    int sr = 0;
    int sc = 0;
    int er = m - 1;
    int ec = n - 1;
    int count = 0;

    while(sr <= er && sc <= ec){
        
        for(int col = sc; col <= ec; col++){
            count++;
            if(count == k){
                return mat[sr][col];
            }
        }
        sr++;

        for(int row = sr; row <= er; row++){
            count++;
            if(count == k){
                return mat[row][ec];
            }
        }
        ec--;

        if(sr <= er){
            for(int col = ec; col >= sc; col--){
                count++;
                if(count == k){
                    return mat[er][col];
                }
            }
            er--;
        }

        if(sc <= ec){
            for(int row = er; row >= sr; row--){
                count++;
                if(count == k){
                    return mat[row][sc];
                }
            }
            sc++;
        }
    }

    return -1;
}

int main() {
    int mat[4][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
    int k = 7;

    int result = findelementInSpiral(4, 4, mat, k);
    
    if(result != -1){
        printf("%dth element in the spiral order is: %d\n", k, result);
    } 
    else{
        printf("%dth element is out of bound.\n", k);
    }
    
    return 0;
}


/*
Output : 7th element in the spiral order is: 16
*/
