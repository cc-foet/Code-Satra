#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int change(int coins[], int n, int value) {
    int dp[n + 1][value + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= value; j++) {
            if (j == 0) {
                dp[i][j] = 0;
            } else if (i == 0) {
                dp[i][j] = 100000;
            } else if (coins[i - 1] <= j) {
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][value];
}

void main() {
    int coins[] = {9, 6, 5, 1};
    int v = 11;

    int n = sizeof(coins) / sizeof(coins[0]);

    printf("%d", change(coins, n, v));
}