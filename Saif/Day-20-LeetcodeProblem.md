[leetcode Problem : 201 Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range/)
````java
class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        // Creating a counter
        int count = 0 ;
        while( left != right ){
            left >>=1;
            right >>=1;
            count += 1;
        }
        return left <<= count;
    }


}
````