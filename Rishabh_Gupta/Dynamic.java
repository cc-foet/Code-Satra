public class Dynamic{
    public static int sum(int[] arr, int start, int end) {
        int sum = 0;
        for (int i = start; i <= end; i++) {
            sum += arr[i];
        }
        return sum;
    }

    public static int partition(int[] arr, int n, int k) {
        int[][] dp = new int[k + 1][n + 1];
        int[] prefixSum = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
        }

        for (int i = 1; i <= n; i++) {
            dp[1][i] = prefixSum[i];
        }

        for (int i = 1; i <= k; i++) {
            dp[i][1] = arr[0];
        }

        for (int i = 2; i <= k; i++) {
            for (int j = 2; j <= n; j++) {
                int best = Integer.MAX_VALUE;
                for (int p = 1; p < j; p++) {
                    best = Math.min(best, Math.max(dp[i - 1][p], prefixSum[j] - prefixSum[p]));
                }
                dp[i][j] = best;
            }
        }

        return dp[k][n];
    }

    public static void main(String[] args) {
        int n = 4;
        int[] arr = {10, 20, 30, 40};
        int k = 2;

        System.out.println(partition(arr, n, k));
    }
}
