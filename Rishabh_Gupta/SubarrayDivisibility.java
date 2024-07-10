import java.util.*;
public class SubarrayDivisibility {
    public static int longestSubarray(int[] arr, int k) {
        int n = arr.length;
        int prefixSum = 0;
        int maxLength = 0;
        Map<Integer, Integer> prefixSumMod = new HashMap<>();
        prefixSumMod.put(0, -1);

        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];
            int currentMod = (prefixSum % k + k) % k; 
            // Ensure positive number is being taken for divisiblity
            if (prefixSumMod.containsKey(currentMod)) {
                maxLength = Math.max(maxLength, i - prefixSumMod.get(currentMod));
            } else {
                prefixSumMod.put(currentMod, i);
            }
        }

        return maxLength;
    }

    public static void main(String[] args) {
        int[] arr = {2, 7, 6, 1, 4, 5};
        int k = 3;
        int result = longestSubarray(arr, Math.abs(k));
        System.out.println("Length of longest subarray divisible by " + k + ": " + result);
    }
}
