// Problem: Given an array of integers, find the length of the longest subarray whose sum is divisible by k

import java.util.HashMap;

public class Day8 {
    public static int longestSubarrayLength(int[] arr, int k) {
        // Map to store the first occurrence of each remainder
        HashMap<Integer, Integer> remainderMap = new HashMap<>();
        remainderMap.put(0, -1);  // Initialize with remainder 0 at index -1

        int maxLength = 0;
        int cumulativeSum = 0;

        for (int i = 0; i < arr.length; i++) {
            cumulativeSum += arr[i];
            
            // Compute the remainder of cumulativeSum when divided by k
            int remainder = cumulativeSum % k;
            
            // Handle negative remainders by converting them to positive
            if (remainder < 0) {
                remainder += k;
            }

            // If the remainder is seen before, there is a subarray with sum divisible by k
            if (remainderMap.containsKey(remainder)) {
                int subarrayLength = i - remainderMap.get(remainder);
                maxLength = Math.max(maxLength, subarrayLength);
            } else {
                // Store the first occurrence of this remainder
                remainderMap.put(remainder, i);
            }
        }

        return maxLength;
    }

    public static void main(String[] args) {
        int[] arr = {2, 7, 6, 1, 4, 5};
        int k = 3;
        System.out.println("Length of longest subarray divisible by " + k + " is: " + longestSubarrayLength(arr, k));
    }
}
