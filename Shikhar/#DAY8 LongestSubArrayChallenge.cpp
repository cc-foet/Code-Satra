// Solved the challenge of Day 8

#include<iostream>
using namespace std;

int longSubarrWthSumDivByK(int* arr, int n, int k)
	{
	    int ans=0;
	    for(int i=0; i<n; i++){
	        int sum = 0;
	        for(int j=i; j<n; j++){
	            sum = sum + arr[j];
	            if(sum%k==0){
	                int length = j-i+1;
	                if(length>ans){
	                    ans = length;
	                }
	            }
	        }
	    }
	    
	return ans;
}

int main(){
    int arr[6] = {2, 7, 6, 1, 4, 5};
    int subArr = longSubarrWthSumDivByK(arr, 6, 3);
    cout<<"The longest sub array which has its sum divided by 3 is "<<subArr;
}

// Output
// The longest sub array which has its sum divided by 3 is 4