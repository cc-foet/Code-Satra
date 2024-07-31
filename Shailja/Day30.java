public class Day30 {
    public static void main(String[] args) {
        int[][] books = {{1, 3}, {2, 4}, {3, 2}};
        int shelfWidth = 6;
        int ans= minHeightShelves(books, shelfWidth);
        System.out.println(ans); 
    }
    public static int minHeightShelves(int[][] books, int shelfWidth) {
        int n = books.length;
        int[] dp = new int[n + 1];
        dp[0] = 0; 

        for (int i = 1; i <= n; i++) {
            int width = 0, height = 0;
            dp[i] = Integer.MAX_VALUE;
            for (int j = i - 1; j >= 0; j--) {
                width += books[j][0];
                if (width > shelfWidth) break;
                height = Math.max(height, books[j][1]);
                dp[i] = Math.min(dp[i], dp[j] + height);
            }
        }

        return dp[n];
    }

    
}
