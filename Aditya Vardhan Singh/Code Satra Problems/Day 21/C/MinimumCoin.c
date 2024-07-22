#include <limits.h>
#include <stdio.h>

#define SIZE 4

int min(int i, int j) { return i < j ? i : j; }

int minCoins(int *coins, int n, int V) {
  int dp[V + 1];
  for (int i = 0; i < V + 1; i++) {
    dp[i] = INT_MAX;
  }

  dp[0] = 0;

  for (int i = 1; i < V + 1; i++) {
    for (int j = 0; j < n; j++) {
      if (coins[j] <= i) {
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
      }
    }
  }

  if (dp[V] != INT_MAX) {
    return dp[V];
  } else {
    return -1;
  }
}

int main() {

  int coins[SIZE] = {9, 6, 5, 1};
  int V = 11;

  printf("%d\n", minCoins(coins, sizeof coins / sizeof coins[0], V));

  return 0;
}
