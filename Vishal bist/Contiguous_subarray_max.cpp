/*Program to find the contiguous sub-array(containing at least one number) that has the maximum sum.
 The expected time complexity: O(n)
 */

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

long long maxSubarraySum(vector<int> &arr) {
        int prefix = 0;
        int n = arr.size();
        int ans = INT_MIN;
        for(int i = 0; i<n; ++i){
            prefix += arr[i];
            ans = max(prefix,ans);
            if(prefix < 0)  prefix = 0;
        }
        return (long long)ans;
};

int main(){
  vector<int>arr = {-1, -2, -3, -4};
  cout<<"Max sum of sub-array: "<<maxSubarraySum(arr)<<endl;
}
