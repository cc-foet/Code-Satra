/*
    https://leetcode.com/problems/permutations/description/
    this is from leetcode question i solved today ( 04-07-2024)

    Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

    - this question ask to return all possible combination in array formate 

    Example 1:
    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    
    Example 2:
    Input: nums = [0,1]
    Output: [[0,1],[1,0]]
    
    Example 3:
    Input: nums = [1]
    Output: [[1]]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    void solve(vector<int>& nums,vector<vector<int>>& ans, unsigned int index){
        // base case 
        if(index>=nums.size()-1){
            ans.push_back(nums);
            return;
        }

        for( unsigned int j=index;j < nums.size();j++){
            swap(nums[index],nums[j]);
            solve(nums,ans,index+1);
            // backtrack
            swap(nums[j],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        solve(nums,ans,index);
        return ans;
    }
};

int main(){
    vector<int> nums={1,2,3};
    Solution solution;
    vector<vector<int>> ans = solution.permute(nums);
    for ( unsigned int i = 0; i < ans.size(); i++)
    {
        for ( unsigned int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}