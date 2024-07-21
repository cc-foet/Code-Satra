// Problem: Given are N boards  with length of each given in the form of array, and K painters, such that each painter takes 1 unit of time to paint 1 unit of board. The task is to find the minimum time to paint all the boards under the constraints that any painter will only paint continuous sections of boards using Dynamic Programming.

// Time Complexity: O(k * n^2) where n is the number of boards and k is the number of painters.
// Space Complexity: O(k * n) where n is the number of boards and k is the number of painters.


import java.util.Arrays;

public class Day20 {
    
    public static int minTimeToPaintBoards(int[] boards, int k) {
        int n = boards.length;
        
        // Edge cases
        if (n == 0 || k == 0) return 0;
        if (k > n) k = n; // More painters than boards
        
        // Create a prefix sum array
        int[] prefixSum = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + boards[i - 1];
        }
        
        // DP table
        int[][] dp = new int[k + 1][n + 1];
        
        // Initialize the DP table
        for (int i = 1; i <= n; i++) {
            dp[1][i] = prefixSum[i]; // One painter paints all boards up to i
        }
        
        for (int i = 2; i <= k; i++) { // i painters
            for (int j = 1; j <= n; j++) { // j boards
                int min = Integer.MAX_VALUE;
                for (int p = 1; p <= j; p++) {
                    min = Math.min(min, Math.max(dp[i - 1][p], prefixSum[j] - prefixSum[p]));
                }
                dp[i][j] = min;
            }
        }
        
        return dp[k][n];
    }

    public static void main(String[] args) {
        int[] boards = {10, 20, 30, 40};
        int k = 2;
        System.out.println("Number of boards: " + boards.length); // Output: 4
        System.out.println("Length of boards: " + Arrays.toString(boards)); // Output: [10, 20, 30, 40]
        System.out.println("Number of painters: " + k); // Output: 2
        System.out.println("Minimum time to paint all boards: " + minTimeToPaintBoards(boards, k)); // Output: 60
    }
}
