public class Coins {
    public static int change(int[] coins, int value) {
        int[] dp = new int[value + 1];
        dp[0] = 0;
        for (int i = 1; i <= value; i++) {
            dp[i] = Integer.MAX_VALUE;
            for (int j = 0; j < coins.length; j++) {
                if (coins[j] <= i) {
                    int sub_res = dp[i - coins[j]];
                    if (sub_res != Integer.MAX_VALUE && sub_res + 1 < dp[i]) {
                        dp[i] = sub_res + 1;
                    }
                }
            }
        }
        return dp[value];
    }

    public static void main(String[] args) {
        int[] coins = {9, 6, 5, 1};
        int v = 11;

        System.out.println(change(coins, v));
    }
}
