import java.util.HashMap;

public class Day8ques1 {
    public static void main(String[] args) {
        int[] nums = { 2, 7, 6, 1, 4, 5 };
        int k = 3;
        int result = longestSubarrayDivisibleByK(nums, k);
        System.out.println("Length of the longest subarray: " + result); 
    }

    public static  int longestSubarrayDivisibleByK(int[] nums, int k) {
        int maxLength = 0;
        int prefixSum = 0;
        HashMap<Integer, Integer> remainderMap = new HashMap<>();

        remainderMap.put(0, -1);

        for (int i = 0; i < nums.length; i++) {
            prefixSum += nums[i];
            int remainder = prefixSum % k;

           
            if (remainder < 0) {
                remainder += k;
            }

            if (remainderMap.containsKey(remainder)) {
                int previousIndex = remainderMap.get(remainder);
                maxLength = Math.max(maxLength, i - previousIndex);
            } else {
                remainderMap.put(remainder, i);
            }
        }

        return maxLength;
}
}
