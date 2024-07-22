#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int N, int V) {
    int dp[V + 1];
    dp[0] = 0;

    for (int i = 1; i <= V; ++i) {
        dp[i] = INT_MAX;
        for (int j = 0; j < N; ++j) {
            if (i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
                dp[i] = dp[i - coins[j]] + 1;
            }
        }
    }

    return (dp[V] == INT_MAX) ? -1 : dp[V];
}

int main() {
    int coins[] = {9, 6, 5, 1};
    int N = sizeof(coins) / sizeof(coins[0]);
    int V = 11;

    int result = minCoins(coins, N, V);
    printf("Minimum number of coins required: %d\n", result);

    return 0;
}
