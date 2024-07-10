# Leetcode Problem number : 540 ( Single Element in a Sorted Array)

[link](https://leetcode.com/problems/single-element-in-a-sorted-array/description/)
Example : 2
Input: nums = [3,3,7,7,10,11,11]
Output: 10

## Approach 1

First initialize two pointer
start = 0 , mean first index of the array
end = length of the array -1 ;

- Start a while loop such (while the start pointer is < end pointer)
- a. Find the middle of the array (mid = start + (end - start)/2 or mid = (start +end ) /2)
- if mid is odd then subtract 1 to make it even
- Compare the middle element with the adjacent element on its right

1. If the middle element is not equal to the right adjacent element, then the single element must be on the left side of the middle, so update the end to mid (end = mid).
2. Otherwise the single element must be on the right of the array, so update the left pointer by middle index + 2 ;

- At the end return the element on the index start; nums[start] ;

```java
        public class Solution {
                public static void main(String[] args){
                        int [] nums  = {1,1,2,3,3,4,4,8,8};

                }
                public static int singleElement(int [] nums){
                        int start = 0;
                        int end  = nums.length -1;
                        while(start < end) {
                                int mid = start + ( end - start) / 2;
                                if(mid % 2 ==1) {
                                        mid--;
                                }
                                if(nums[mid] != nums[mid + 1]) {
                                        end = mid ;
                                }
                                else {
                                        start = mid + 2;
                                }

                        }
                        return nums[start];
                }
        }

```

## Approach 2 :

Solving this using bitwise XOR operator

```java
        public class Solution {
                public static void main(String[]args ) {
                        // Driver code here
                }
                public static int singleElementUsingXOR(int[] nums) {
                        int uniqueElement = 0;
                        for(int n : nums) {
                                uniqueElement = uniqueElement ^ n;

                        }
                        return uniqueElement;
                }
        }
```

Let arr = [2, 4, 3, 2,4]
Here in the for loop it n = to the element of the array

* 1st iteration => n = 2;
  unique = 0
  0 ^ 2 = 2;
* 2nd iteration
  n = 4
  unique = 2;
  // New Unique will be
  unique = 2 ^ 4;
  unique = 6
* 3rd iteration
  n = 3
  unique = 6
  // New Unique will be
  unique = 6 ^ 3 = 5
  unique = 5;
* 4th iteration
  n = 2
  unique = 5
  // New Unique will be
  unique = 5 ^ 2 = 7
* 5th iteration
  n = 4
  // New Unique will be
  unique = 7 ^ 4 = 3
* At the end return the unique.
  Result = 3  -- Answer
