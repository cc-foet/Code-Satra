import java.util.Arrays;

public class Ferwick {
    public static void update(int[] BIT, int index, int value, int len) {
        while (index <= len) {
            BIT[index] += value;
            index += index & -index;
        }
    }
    public static int query(int[] BIT, int index) {
        int sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= index & -index;
        }
        return sum;
    }
    public static int countInversions(int[] arr) {
        int n = arr.length;
        int[] temp = arr.clone();
        Arrays.sort(temp);
        for (int i = 0; i < n; i++) {
            arr[i] = Arrays.binarySearch(temp, arr[i]) + 1;
        }
        int[] BIT = new int[n + 1];
        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            count += query(BIT, arr[i] - 1);
            update(BIT, arr[i], 1, n);
        }
        return count;
    }
    public static void main(String[] args) {
        int[] arr = {8, 4, 2, 1};
        
        System.out.println(countInversions(arr));
    }
}