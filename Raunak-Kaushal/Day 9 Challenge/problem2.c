/*
Print output in form of spiral matrix in 2-D array
*/

#include <stdio.h>

void printSpiral(int m, int n, int mat[][4]){
    int sr = 0;
    int sc = 0;
    int er = m - 1;
    int ec = n - 1;

    while(sr <= er && sc <= ec){
        // Top
        for(int col = sc; col <= ec; col++){
            printf("%d ", mat[sr][col]);
        }
        sr++;

        // Right
        for(int row = sr; row <= er; row++){
            printf("%d ", mat[row][ec]);
        }
        ec--;

        // Bottom
        if(sr <= er){
            for(int col = ec; col >= sc; col--){
                printf("%d ", mat[er][col]);
            }
            er--;
        }

        // Left
        if (sc <= ec) {
            for(int row = er; row >= sr; row--){
                printf("%d ", mat[row][sc]);
            }
            sc++;
        }
    }
}

int main() {
    int mat[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };

    printf("Matrix in spiral order:\n");
    printSpiral(4, 4, mat);

    return 0;
}

/*
Output :
Matrix in spiral order:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/
