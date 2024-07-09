/* Leetcode 74.Search a 2D Matrix.
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
 */

public class Day8 {
    public static boolean searchMatrix(int[][] matrix, int target) {
        int m=matrix.length;
        int n=matrix[0].length;
        int st=0,end=m*n-1;
        while (st<=end){
            int mid = st+(end-st)/2;
            if ((matrix[mid/n][mid%n])==target) return true;
            else if ((matrix[mid/n][mid%n])>target) end=mid-1;
            else st=mid+1;
        }
        return false;
    }
    public static void main(String[] args) {
        int[][] matrix ={ {1,3,5,7},{10,11,16,20},{23,30,34,60} };
        int target = 3;
         System.out.println(searchMatrix(matrix,target));
    }
}

