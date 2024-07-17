// Program to find the least weight capacity of a boat to ship all weights given in an array within d days.

#include<iostream>
using namespace std;

int MinWeightCapacity(int arr[], int n, int d) {
        int start = 0,end = 0,mid,ans;
        
        for(int i = 0; i<n; ++i){
            start = max(start,arr[i]);
            end+=arr[i];
        }
        
        while(start<=end){
            mid = start + (end - start)/2;
            int weight = 0, day = 1;
            for(int i = 0; i<n; ++i){
              weight+=arr[i];
                if(weight>mid){
                    day++;
                    weight = arr[i];
                }
            }
            
            if(day <= d){
                ans = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return ans;
};

int main(){
  int arr[] = {9,8,10};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<"Minimum capacity of boat: "<<MinWeightCapacity(arr,n,3)<<endl;
}