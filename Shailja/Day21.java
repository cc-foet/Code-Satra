import java.util.Arrays;

public class Day21 {
    public static void main(String[] args) {
        int[] coins = { 9,6, 5,1 };
        int v = 11;
        int result = minCoins(coins, v);
        if (result == -1) {
            System.out.println("It's not possible to make the change.");
        } else {
            System.out.println("Minimum number of coins required: " + result);
        }
    }
    public static int minCoins(int[] coins, int v) {
        int[] dp = new int[v + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        for (int coin : coins) {
            for (int j = coin; j <= v; j++) {
                if (dp[j - coin] != Integer.MAX_VALUE) {
                    dp[j] = Math.min(dp[j], dp[j - coin] + 1);
                }
            }
        }

        return dp[v] == Integer.MAX_VALUE ? -1 : dp[v];
    }

   
}
