
import java.util.HashMap;

public class SubArray {
 
    static int longestSubarray(int[] arr, int len, int k) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

        int modArr[] = new int[len];
        int maxLen = 0;
        int currSum = 0;

        for (int i = 0; i < len; i++) {
            currSum += arr[i];

            modArr[i] = currSum % k;

            if (modArr[i] == 0) {
                maxLen = i + 1;
            } else if (map.containsKey(modArr[i]) == false) {
                map.put(modArr[i], i);
            } else {
                if (maxLen < i - map.get(modArr[i])) {
                    maxLen = i - map.get(modArr[i]);    
                }
            }
        }
        return maxLen;
    }
    public static void main(String[] args) {
        int[] arr = {2, 7, 6, 1, 4, 5};
        int k = 3;

        System.out.println(longestSubarray(arr, arr.length, k));
    }
}
