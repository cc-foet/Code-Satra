// To make one bouquet we need k adjacent flowers from the garden. Here the garden consists of N different flowers, the ith flower will bloom in the bloomDay[i]. Each flower can be used inside only one bouquets. We have to find the minimum no of days need to wait to make M bouquets from the garden . If we cannot make M bouquets then return -1.

public class Day3 {
    public int minDays(int[] bloomDay, int M, int K) {
        int N = bloomDay.length;
        
        // If it's impossible to make m bouquets
        if (N < M * K) {
            return -1;
        }

        int left = 1, right = 1;
        for (int day : bloomDay) {
            right = Math.max(right, day);
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMakeBouquets(bloomDay, M, K, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    private boolean canMakeBouquets(int[] bloomDay, int M, int K, int days) {
        int bouquets = 0;
        int flowers = 0;

        for (int day : bloomDay) {
            if (day <= days) {
                flowers++;
                if (flowers == K) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }

            if (bouquets >= M) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Day3 sol = new Day3();
        int[] bloomDay = {5, 5, 5, 5, 10, 5, 5};
        int M = 2;
        int K = 3;
        System.out.println(sol.minDays(bloomDay, M, K)); // Output: 3
    }
}
