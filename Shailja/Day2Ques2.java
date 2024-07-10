import java.util.Arrays;

public class Day2Ques2 {
    public static void main(String[] args) {
        int[] nums = {3, 2, 4, 1, 5,7,6};
        int[] ans = cyclicSort(nums);
        System.out.println(Arrays.toString(ans));
    }
 //? Function to perform cyclic sort
 
    public static int[] cyclicSort(int[] nums) {
        int i = 0;
        while (i < nums.length) {
            int correctindex = nums[i] - 1;
            if (nums[i] != nums[correctindex]) {
                int temp = nums[i];
                nums[i] = nums[correctindex];
                nums[correctindex] = temp;
            } else {
                i++;
            }
        }
        return nums;
    }
}
