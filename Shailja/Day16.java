//? leetcode question 219
public class Day16 {
    public static void main(String[] args) {
        int[] nums1 = {1, 2, 3, 1};
        int k1 = 3;
  boolean ans = containsNearbyDuplicate(nums1, k1);
        System.out.println(ans); 
    }
    
        public static boolean containsNearbyDuplicate(int[] nums, int k) {
            for (int i=0; i<nums.length; i++){
                for (int j=i+1 ; j<=i+k && j<nums.length; j++){
                    if( (nums[i] == nums[j]) ){
                        return true;
                    }
                }
            }
            return false;
        }
    }
 