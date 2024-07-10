public class Bouquet {
    int getSum(int[] bloomDay, int i, int n) {
        int sum = 0;
        for (int idx = i; idx < n; idx++) {
            sum += bloomDay[idx];
        }
        return sum;
    }

    int getMax(int[] bloomDay, int i, int n) {
        int max = bloomDay[i];
        for (int idx = i+1; idx < n; idx++) {
            if (bloomDay[idx] > max) max = bloomDay[idx];
        }
        return max;
    }

    int bouquet(int[] bloomDay, int M, int K) {
        int n = bloomDay.length;
        int adj_flowers = M * K;

        // required flowers are more than flowers in garden
        if (adj_flowers > n) return -1;

        int min_idx = 0;
        int min_sum = Integer.MAX_VALUE;
        int sum = 0;
        for (int i = 0; i <= n - adj_flowers; i++) {
            sum = getSum(bloomDay, i, i+adj_flowers);
            if (sum < min_sum) {
                min_sum = sum;
                min_idx = i;
            }
        }
        return getMax(bloomDay, min_idx, min_idx + adj_flowers);
    }

    public static void main(String[] args) {
        int M = 2, K = 3;
        int[] bloomDay = {5, 5, 5, 5, 10, 5, 5};

        Bouquet ob = new Bouquet();

        System.out.println(ob.bouquet(bloomDay, M, K));
    }
}