# Leetcode question number : 15 (3Sum )

[Link](https://leetcode.com/problems/3sum/)

## Solution
``` java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> list = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if( i != 0 && nums[i] == nums[i -1 ]) continue;
            int left = i + 1;
            int right = nums.length - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    left++;

                } else if (sum > 0) {
                    right--;
                } else {
                    List<Integer> temp = Arrays.asList(nums[i], nums[left], nums[right]);
                    list.add(temp);
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }

        }
        return list;
    }
}
```
## Approach

        Step : 1) Sort the given array:
        `Arrays.sort(nums);`

        `List<List <Interger>> list = new ArrayList<>(); `
        This line creates an empty array list of integers which will be used to store those triplets whose sum is equals to zero

        Iterate over the array nums;
        `for(int i = 0 ; i < nums.length ; i++) `

        Adding check condition `if(i != 0 && nums[i] == nums[i -1]) continue;`

        This line will checks if the current element `nums[i]` is the same as the previous element `nums[i-1]`. If it is, the loop will skip to the next iteration using the `continue` statement. So that we can avoid duplicate elements

        else if the condition is false  then increase left by 1 `int left =  i + 1`
        and decrease the right by 1 `int right = nums.lenght -1`

        Adding while loop `while(left < right)`

        And calculating the sum `int sum = nums[i] + nums[left]  + nums[right];

        Checking if the sum is < 0 if true then
                `left++`

                `else if(sum > 0)` then `right--`;
                `else if equal to 0 ` then saving all the element into a new temp list and then adding that temp arraylist into our result list;

                `list.add(temp)`
                `left ++ ` and `right--`

                At the end two while loop to check for any duplicate element at left and right index into the result.
        And returning the result from the fuction;










