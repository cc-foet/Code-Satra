package Array;
import java.util.Arrays;

public class Increment {
    public static int unique(int[] arr, int n) {
        int c = 0;
        Arrays.sort(arr);
        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[i - 1]) {
                int in = arr[i - 1] - arr[i] + 1;
                arr[i] += in;
                c += in;
            }
        }
        return c;
    }
    public static void main(String[] args) {
        int[] arr = {4, 5, 4, 1, 3, 7, 6, 3, 3};
        int n = arr.length;
        System.out.println(unique(arr, n)); 
    }
}
