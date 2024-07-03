// In this file I have implemented a binary search program using C++.
// The binary search algorithm can only be applied to sorted arrays.
// The time complexity of binary search is O(log(n)).

#include<iostream>
using namespace std;

int binarySearch(int* arr, int s, int e, int target){
    int ans;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(arr[mid] < target){
            s = mid+1;
        }
        else if(arr[mid] > target){
            e = mid-1;
        }
        else{
            ans = mid;
            return ans;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int main(){
    int arr[5]={2,4,5,7,9};
    int ans = binarySearch(arr, 0, 4, 9);
    cout<<ans;
}