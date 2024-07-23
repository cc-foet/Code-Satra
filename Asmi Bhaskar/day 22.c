#include <stdio.h>
#include <string.h>

int max(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    return c;
}

int lcsOf3(char* X, char* Y, char* Z, int m, int n, int o) {
    int L[m+1][n+1][o+1];
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= o; k++) {
                if (i == 0 || j == 0 || k == 0)
                    L[i][j][k] = 0;
                else if (X[i-1] == Y[j-1] && X[i-1] == Z[k-1])
                    L[i][j][k] = L[i-1][j-1][k-1] + 1;
                else
                    L[i][j][k] = max(L[i-1][j][k], L[i][j-1][k], L[i][j][k-1]);
            }
        }
    }
    
    return L[m][n][o];
}

int main() {
    char X[] = "abcd1e2";
    char Y[] = "bc12ea";
    char Z[] = "bd1ea";
    
    int m = strlen(X);
    int n = strlen(Y);
    int o = strlen(Z);
    
    printf("Length of LCS is %d\n", lcsOf3(X, Y, Z, m, n, o));
    
    return 0;
}
