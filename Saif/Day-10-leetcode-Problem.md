[Leetcode Problem 162](https://leetcode.com/problems/find-peak-element/description/)

# Find the Peak Element

```java
class Solution {
    public int findPeakElement(int[] nums) {
        int start = 0;
        int end = nums.length - 1;
        while (start <= end) {   // Normal Binary Serach Logic

                int mid = start + (end - start) / 2;
                // Calculating middle element

            if (nums.length == 1) { // If array contain only one element then that element will be the peak element,
                return 0;
            }
            if (mid > 0 && mid < nums.length - 1) { // If mid greater than 0 and mid is less than size of the array (elemination all the edge element `element at the 0th index and element at the last index )
                if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
                    return mid;
                } else if (nums[mid + 1] > nums[mid]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else if (mid == 0 ){ // If the mid is equal to the 0th index of the array

                if (nums[0] > nums[1])
                 return 0;
                else
                    return 1;
            } else if (mid == nums.length - 1) { // If mid is equal to last index of the array
                if (nums[nums.length - 1] > nums[nums.length - 2])
                    return nums.length - 1;
                else
                    return nums.length - 2;
            }

        }
        return -1;
    }
}
```
