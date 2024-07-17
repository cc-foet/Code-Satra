# Leetcode Problem 81

[Question Link](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/)

````java
class Solution {
    public boolean search(int[] nums, int target) {
        int start = 0;
        int end = nums.length -1;
        while(start <= end){ //While start is less than end
            int mid = start + (end - start) /2 ; // Calculating mid
            if(nums[mid] == target) { // Checking if the target is equal to mid if yes then return true
                return true;
            }
            if(nums[start] == nums[mid] && nums[end] == nums[mid]){ // If element at start and element at end is same
            // Increasing start by one and decreasing end by 1;
                ++start;
                --end;
            }
            else if(nums[start] <= nums[mid]){ // If element at the start index is less than or equal to the element at the mid
                if(nums[start] <= target && target < nums[mid]) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }

            }else {
                if(nums[mid] < target && target <= nums[end]){
                    start = mid + 1;

                }
                else {
                    end = mid -1;
                }
            }
        }return false;
    }

}

````