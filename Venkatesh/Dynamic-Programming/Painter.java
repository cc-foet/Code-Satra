public class Painter {
    public static int sum(int[] arr, int start, int end) {
        int sum = 0;
        for (int i = start; i <= end; i++) {
            sum += arr[i];
        }
        return sum;
    }

    public static int partition(int[] arr, int n, int k) {
        if (k == 1) {
            return sum(arr, 0, n - 1);
        }
        if (n == 1) {
            return arr[0];
        }
        int best = Integer.MAX_VALUE;

        for (int i = 1; i <= n; i++) {
            best = Math.min(best, Math.max(partition(arr, i, k - 1), sum(arr, i, n - 1)));
        }
        return best;
    }

    public static void main(String[] args) {
        int n = 4;
        int[] arr = {10, 20, 30, 40};
        int k = 2;

        System.out.println(partition(arr, n, k));
    }
}
