# Leetcode problem number 378
[Question Link](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)

### BruteForce Approach

```java
import java.util.ArrayList;
import java.util.Arrays;
public class KthSmallest {

        public static void main(String[] args) {

                int nums[][] = { { -5 },
                };
                        System.out.println(kthSmallest(AddingAllElementInList(nums), 1));
       }

        public static Integer[] AddingAllElementInList(int[][] nums) {
                ArrayList<Integer> list = new ArrayList<>();
                for (int i = 0; i < nums.length; i++) {
                        for (int j = 0; j < nums[i].length; j++) {
                                list.add(nums[i][j]);
                        }
                }
                return list.toArray(new Integer[0]);
        }
        public static int kthSmallest(Integer[] nums, int k ){
                Arrays.sort(nums);
                for(int i = 1 ; i<= nums.length ;i++)
                {
                        if(i == k){
                                return nums[i -1];
                        }
                }
                return -1;
        }
}

```

### Optimal Approach using binary search

```java
class Solution {
        public static void main ( String[] args ) {
                // Driver Code here
        }
  public static int kthSmallest(int[][] matrix, int k) {
    int l = matrix[0][0];
    int r = matrix[matrix.length - 1][matrix.length - 1];

    while (l < r) {
      final int m = l + (r - l) / 2;
      if (numsNoGreaterThan(matrix, m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  public static int numsNoGreaterThan(int[][] matrix, int m) {
    int count = 0;
    int j = matrix[0].length - 1;
    // For each row, find the first index j s.t. row[j] <= m s.t. the number of
    // numbers <= m for this row will be j + 1.
    for (int[] row : matrix) {
      while (j >= 0 && row[j] > m)
        --j;
      count += j + 1;
    }
    return count;
  }
}

```
