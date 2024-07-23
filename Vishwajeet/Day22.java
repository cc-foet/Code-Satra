// Problem: Longest Common Subsequence: Given 3 strings, find the length of the longest common subsequence among all three given sequences.

// Time Complexity: O(m*n*o) where m, n and o are the lengths of the three strings X, Y and Z respectively.
// Space Complexity: O(m*n*o) where m, n and o are the lengths of the three strings X, Y and Z respectively.

import java.util.Scanner;

public class Day22 {
    // Function to find the length of the longest common subsequence among three strings
    public static int findLCSLength(String X, String Y, String Z) {
        int m = X.length();
        int n = Y.length();
        int o = Z.length();

        // Create a 3D array to store lengths of longest common subsequence
        int[][][] dp = new int[m + 1][n + 1][o + 1];

        // Build the dp array
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= o; k++) {
                    if (X.charAt(i - 1) == Y.charAt(j - 1) && X.charAt(i - 1) == Z.charAt(k - 1)) {  // If characters match
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1; // Add 1 to the length of LCS of X[0..i-1], Y[0..j-1] and Z[0..k-1]
                    } else {
                        dp[i][j][k] = Math.max(dp[i - 1][j][k],  // Find the maximum of LCS of X[0..i-2], Y[0..j-1] and Z[0..k-1]
                                        Math.max(dp[i][j - 1][k], dp[i][j][k - 1])); // LCS of X[0..i-1], Y[0..j-2] and Z[0..k-1] and LCS of X[0..i-1], Y[0..j-1] and Z[0..k-2]
                    }
                }
            }
        }

        // The value in dp[m][n][o] will be the length of LCS of X, Y and Z
        return dp[m][n][o];
    }

    // Main method to test the function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input strings from user
        System.out.println("Enter first string:");
        String X = scanner.nextLine();

        System.out.println("Enter second string:");
        String Y = scanner.nextLine();

        System.out.println("Enter third string:");
        String Z = scanner.nextLine();

        // Find and print the length of the longest common subsequence
        System.out.println("The length of the longest common subsequence is: " + findLCSLength(X, Y, Z));

        scanner.close();


        /* String X = "abcd1e2";
        String Y = "bc12ea";
        String Z = "bd1ea"; 
        System.out.println("The length of the longest common subsequence is: " + findLCSLength(X, Y, Z));
        */
    }
}
