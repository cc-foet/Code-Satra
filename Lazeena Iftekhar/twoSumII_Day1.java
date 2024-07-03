

/* 1-indexed array nums is given in non-decreasing order. Find two numbers that add up to 'target'. 
 Return the indices(1-indexed) of the two numbers. Return [-1,-1] if not found.

 For eg : [9, 7, 15, 16] --> target = 25 --> Output --> 1 and 4 (as 9 and 16 sum up to 25)
 */

class twoSumII_Day1{

    public static int[] twoSum(int[] nums, int target) {

        int min = 0;

        int max = nums.length - 1;

        while (min < max) {
            if(nums[min] + nums[max] == target)
            return new int[]{min + 1, max + 1};

            else if(nums[min] + nums[max] < target)
            min ++;

            else
            max --;
        }

        return new int[] {-1, -1};

}

public static void main(String[] args) {
    int[] arr = {9, 7, 15, 16};

    int[] res = twoSum(arr, 25);

    for ( int val : res) {
        System.out.print(val + "\t");
    }
}

}