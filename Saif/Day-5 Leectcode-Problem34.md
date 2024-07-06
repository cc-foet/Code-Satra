[Question 34 ](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)




# Approach
First create a function called `findElement()` it does the normal `Binary Search`

Then in the `searchRange()` function we will call the `findElement()` function which return the left index of the array ;
After that we will check if the return value of the `findElement()` function is equal to length of the array OR num[l] is not equal to target if these condition is true that mean element doesn't exist so well wiil return the array with `{-1,-1}` </br>
Else

If the target element is found, it calls the findElement function again to find the first position of the element that
is greater than the target element. This is done by passing target + 1 as the target element to the findElement function.
The first position of the element that is greater than the target element is subtracted by 1 to get the last position of the target element.
The function returns an array with the first and last position of the target element.

```java
import java.util.Arrays;

public class Leetcode34 {
        public static void main(String[] args) {
                int[] arr = { 5, 7, 7, 8, 8, 10 };
                int target = 8;
                System.out.println(Arrays.toString(searchRange(arr, target)));

        }

        public static int[] searchRange(int[] nums, int target) {
                int l = findElement(nums, target);
                if(l == nums.length || nums[l] != target)
                        return new int[] {-1, -1};


                 int r = findElement(nums, target +1) -1;
                return new int[] {l, r};


        }

        private static int findElement(int [] nums , int target){
                int left = 0 ; int right = nums.length-1;
                while(left  < right) {
                         int mid = left + (right - left ) / 2;
                        if(nums[mid] >= target ) {
                                right = mid;
                        }
                        else {
                                left = mid + 1;
                        }
                }
                return left;
        }
}

```
