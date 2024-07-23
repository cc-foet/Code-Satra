public class LongestSubsequence {

    public static int subsequence(String str1, String str2, String str3, int len1, int len2, int len3) {
        int[][][] L = new int[len1+1][len2+1][len3+1];

        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                for (int k = 0; k <= len3; k++) {
                    if (i == 0 || j == 0 || k == 0) {
                        L[i][j][k] = 0;
                    } else if (str1.charAt(i-1) == str2.charAt(j-1) && str2.charAt(j-1) == str3.charAt(k-1)) {
                        L[i][j][k] = L[i-1][j-1][k-1] + 1;
                    } else {
                        L[i][j][k] = Math.max(Math.max(L[i-1][j][k], L[i][j-1][k]), L[i][j][k-1]);
                    }
                }
            }
        }
        return L[len1][len2][len3];
    }
    public static void main(String[] args) {
        String str1 = "abcd1e2";
        String str2 = "bc12ea";
        String str3 = "bd1ea";

        int len1 = str1.length();
        int len2 = str2.length();
        int len3 = str3.length();

        System.out.println(subsequence(str1, str2, str3, len1, len2, len3));
    }
}