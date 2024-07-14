[1545. Find kth Bit in the Nth Binary String](https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/)

# Approach

1. This is the base case of the recursion. If n is 1, it means we're at the first row of the Sierpinski triangle, which is just a single '0'. So, the method returns '0'.

`if(n == 1 ) return '0' ;`

2. This line calculates the length of the current row in the Sierpinski triangle. The length of the row is 2^n - 1, where n is the row number.

` int l = (int) Math.pow(2,n) -1;`

3. This line calculates the middle index of the current row. The middle index is (length of the row) / 2 + 1.

` int mid = l/2 + 1;`

4. If k is equal to the middle index, it means the kth bit is the middle bit of the current row, which is always '1' in the Sierpinski triangle. So, the method returns '1'.
   `if(k == mid) return '1';`

5. If k is less than the middle index, it means the kth bit is in the left half of the current row. The left half of the current row is the same as the entire previous row, so the method calls itself recursively with n-1 and k.

`    else if (k  < mid) return findKthBit(n-1 , k);`

6. If k is greater than or equal to the middle index, it means the kth bit is in the right half of the current row. The right half of the current row is the same as the entire previous row, but with all bits flipped (i.e., '0' becomes '1' and '1' becomes '0'). So, the method calls itself recursively with n-1 and l+1-k (which is the corresponding index in the previous row), and then flips the result.

`else return findKthBit(n-1, l+1-k) == '0' ? '1' : '0';`

```java
class Solution {
    public char findKthBit(int n, int k) {
        if(n == 1) return '0' ;
        int l = (int) Math.pow(2, n) -1;
        int mid = l/2 + 1;
        if(k == mid ) return '1';
        else if (k  < mid) return findKthBit(n-1 , k);
        else return findKthBit(n-1, l+1-k) == '0' ? '1' : '0' ;
    }
}
```
