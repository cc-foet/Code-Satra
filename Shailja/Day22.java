
public class Day22 {
    public static int lcs(String str1, String str2, String str3) {
        int len1 = str1.length();
        int len2 = str2.length();
        int len3 = str3.length();

        int[][][] dp = new int[len1 + 1][len2 + 1][len3 + 1];

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                for (int k = 1; k <= len3; k++) {
                    if (str1.charAt(i - 1) == str2.charAt(j - 1) && str1.charAt(i - 1) == str3.charAt(k - 1)) {
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    } else {
                        dp[i][j][k] = Math.max(Math.max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
                    }
                }
            }
        }

        return dp[len1][len2][len3];
    }

    public static void main(String[] args) {
        String str1 = "abc";
        String str2 = "ac";
        String str3 = "bca";
        int result = lcs(str1, str2, str3);
        System.out.println("Length of Longest Common Subsequence: " + result);
    }
    
}




































































































































































