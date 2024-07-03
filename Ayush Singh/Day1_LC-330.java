/*
Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.

Return the minimum number of patches required.
*/




class Solution {
    public int minPatches(int[] nums, int n) {
        long missing = 1;
        int patches = 0;
        int index = 0;

        while (missing <= n) {
            if (index < nums.length && nums[index] <= missing) {
                missing += nums[index];
                index++;
            } else {
                missing += missing;
                patches++;
            }
        }

        return patches;
    }
}
