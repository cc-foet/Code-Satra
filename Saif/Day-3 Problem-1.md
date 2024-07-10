Problem - 3 (Day-3)
[Question No. 11](https://leetcode.com/problems/container-with-most-water/)

# Approach
        1. First setup two pointer on the array one is `Left` and `right`
        - Initially left will be the `0` element of the array and right will be the last element of the array;
Then start a while loop with condition left< right mean the loop will continue executing till the condition statisfied

inside that loop we will check
```java

        while(left < right) {

            area = Math.max(area, Math.min(height[left], height[right]) * (right-left));
            /* Initially area = 0
                                height[left] = element at 0th index (in first iteration)
                                and height[right] = last element of the given array;

                        Math.min(height[left])
                        In the inner Math.min() => this will return the min of element at left index
                         and the product of element at right index with diff of right , left index

                        then once we'll get the min we will compare it with the area and return
                         the max of area and the min and store it in area, this will continue
            */
            if(height[left] < height[right]){
                /*  Here if the element at the left is less than the element at the right then we will increase the index by one  */
                left +=1;

            }
            else {
                 /* else decrease the index by 1; */
                right = right - 1;
            }
        }

/*  At the end we will get the max area and we will return it from the function */

```

```java
class Solution {
        public static void main(String[] args) {
                int arr = [1,8,6,2,5,4,8,3,7];
                System.out.println(maxArea(arr));
        }

    public int maxArea(int[] height) {
        int area = 0 ;
        int left = 0 ;
        int right = height.length-1;
        while(left < right) {
            area = Math.max(area, Math.min(height[left], height[right]) * (right-left));
            if(height[left] < height[right]){
                left +=1;

            }
            else {
                right = right - 1;
            }
        }
        return area;

    }
}
```
