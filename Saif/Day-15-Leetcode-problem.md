[Leetcode Question Num : 4](https://leetcode.com/problems/median-of-two-sorted-arrays/)





````java
    class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int low = 0 , high = n1;
        int left = ( n1 + n2 + 1) /2;
        int n = n1 + n2;
        while(low <= high){
            int mid1 = low + (high - low ) /2 ;
            int mid2 = left - mid1;
            int ele1 = Integer.MIN_VALUE , ele2 = Integer.MIN_VALUE;
            int r1 = Integer.MAX_VALUE, r2 = Integer.MAX_VALUE;
            if(mid1 < n1 ) r1 = nums1[mid1];
            if(mid2 < n2 ) r2 = nums2[mid2];
            if(mid1 -1  >= 0) ele1 = nums1[mid1-1];
            if(mid2 -1  >= 0) ele2 = nums2[mid2-1];
            if(ele1 <= r2  && ele2 <=r1) {
                if(n % 2 == 1){
                    return Math.max(ele1, ele2);
                }
                else {
                    return ((double)(Math.max(ele1, ele2) + Math.min(r1, r2)))/2.0;

                }
            }
            else if (ele1 > r2) high = mid1 -1 ;
            else low = mid1 + 1 ;
        }
        return 0;
    }
}

````