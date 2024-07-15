package Array;

import java.util.Arrays;

public class Medianof2array
 {

   
    public static int[] mergeArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        int[] arr = Arrays.copyOf(nums1, n1 + n2); 
        System.arraycopy(nums2, 0, arr, n1, n2); 
        Arrays.sort(arr); 
        return arr;
    }

    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] arr = mergeArrays(nums1, nums2); 
        int n = arr.length;
        
        
        if (n % 2 == 0) {
            return (arr[n / 2] + arr[(n / 2) +1]) / 2.0;
        } else 
        {
            return arr[n / 2];
        }
    }

    public static void main(String[] args) 
    {
        int[] nums1 = {4, 6,8,10};
        int[] nums2 = {1,2,3,5};
        System.out.println(findMedianSortedArrays(nums1, nums2));
       
}
 }
