public class Day20 {
  public static void main(String[] args) {
            int[] arr = {10, 20, 30, 40};
            int n = arr.length;
            int k = 2;  
            System.out.println("Minimum time to paint all boards: " + findMinTime(arr, n, k));
        }
    
        public static int findMinTime(int[] arr, int n, int k) {
            int lo = getMax(arr, n);
            int hi = getSum(arr, n);
    
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (isFeasible(arr, n, k, mid)) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
    
            return lo;
        }
    
        public static boolean isFeasible(int[] arr, int n, int k, int maxTime) {
            int painters = 1;
            int currentTime = 0;
    
            for (int i = 0; i < n; i++) {
                currentTime += arr[i];
    
                if (currentTime > maxTime) {
                    painters++;
                    currentTime = arr[i];
    
                    if (painters > k) {
                        return false;
                    }
                }
            }
    
            return true;
        }
    
        public static int getMax(int[] arr, int n) {
            int max = arr[0];
            for (int i = 1; i < n; i++) {
                if (arr[i] > max) {
                    max = arr[i];
                }
            }
            return max;
        }
    
        public static int getSum(int[] arr, int n) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += arr[i];
            }
            return sum;
        }
    }
    