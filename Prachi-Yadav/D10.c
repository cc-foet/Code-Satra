#include <stdio.h>
#include <stdlib.h>

int countBSTs(int *inorder, int n) {
    int dp[n][n];
    for (int i = 0; i < n; ++i)
        dp[i][i] = 1;

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = 0;
            for (int k = i; k <= j; ++k) {
                int left = (k > i) ? dp[i][k-1] : 1;
                int right = (k < j) ? dp[k+1][j] : 1;
                dp[i][j] += left * right;
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    int inorder[] = {4, 5,7};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    printf("%d\n", countBSTs(inorder, n));
    return 0;
}
