// Problem Statement:-(LeetCode Question Search Insert Position)
/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.*/

// Problem Link: https://leetcode.com/problems/search-insert-position/

// Solution
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] < target){
                s = mid+1;
            }
            else if(nums[mid] > target){
                e = mid-1;
            }
            else{
                return mid;
            }
        }
        return s;
    }
};