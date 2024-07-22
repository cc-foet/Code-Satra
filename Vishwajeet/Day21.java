// Problem: Given an array coins[] of size N and a target value V,  where coins[i] represent the coins of different denominations. You have an infinite supply of each coin. The task is to find the minimum number of coins required to make the given value V. If it's not possible to make a change, print -1.
// KNAPSACK PROBLEM [DYNAMIC PROGRAMMING BOTTOM-UP APPROACH]

// Time Complexity: O(N * V) where N is the number of coins and V is the target value
// Space Complexity: O(V) where V is the target value


import java.util.Arrays;

public class Day21 {
    public static int minCoins(int[] coins, int N, int V) {
        // Create a table to store the minimum number of coins for each value from 0 to V
        int[] dp = new int[V + 1];

        // Initialize the table with a value greater than any possible number of coins
        Arrays.fill(dp, V + 1);

        // Base case: no coins needed to make 0 value
        dp[0] = 0;

        // Compute the minimum number of coins for each value from 1 to V
        for (int i = 1; i <= V; i++) {
            for (int j = 0; j < N; j++) {
                if (coins[j] <= i) {
                    dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        // If dp[V] is still greater than V, it means it's not possible to make the value V
        return dp[V] > V ? -1 : dp[V];
    }

    public static void main(String[] args) {
        int[] coins = {9, 5, 6, 1};
        int N = coins.length;
        int V = 11;

        int result = minCoins(coins, N, V);
        if (result == -1) {
            System.out.println("Not possible to make the value " + V);
        } else {
            System.out.println("Minimum coins required to make the value " + V + " is " + result);
        }
    }
}
