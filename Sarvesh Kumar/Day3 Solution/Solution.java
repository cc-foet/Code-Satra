public class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        // Helper function to check if we can make m bouquets by day `days`
        if (bloomDay.length < m * k) {
            return -1; // Not enough flowers to make m bouquets
        }

        int low = Integer.MAX_VALUE;
        int high = Integer.MIN_VALUE;
        for (int day : bloomDay) {
            low = Math.min(low, day);
            high = Math.max(high, day);
        }

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canMakeBouquets(bloomDay, m, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

    private boolean canMakeBouquets(int[] bloomDay, int m, int k, int days) {
        int bouquets = 0;
        int flowers = 0;

        for (int bloom : bloomDay) {
            if (bloom <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }

            if (bouquets >= m) {
                return true;
            }
        }

        return bouquets >= m;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] bloomDay = {5,5,5,5,10,5,5};
        int m = 2;
        int k = 3;
        System.out.println(solution.minDays(bloomDay, m, k)); 

   
    }
}
