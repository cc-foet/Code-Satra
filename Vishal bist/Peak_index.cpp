// Program to find the index of the peak element in an array
#include<iostream>
#include<vector>
using namespace std;

int PeakIndex(vector<int>& nums, int start, int end) {
       if(nums.size() == 1)  return 0;
        int mid;
        while(start < end) {
            mid = start + (end - start)/2;
            
            if(nums[mid] > nums[mid + 1]) 
                end = mid;
            else 
                start = mid + 1;
        }
        return start;
    };

int main(){
  vector<int>nums = {1,9,11,16,18,29,34,77,96};
  int result = PeakIndex(nums,0,nums.size()-1);
  cout<<"index: "<<result<<endl<<"Element "<< nums[result]<<endl;
}
