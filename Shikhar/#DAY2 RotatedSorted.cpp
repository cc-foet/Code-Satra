// In this program I am implementing a searching algorithm on "Rootated Sorted Array".
// I am using binary search to implement this program

#include<iostream>
using namespace std;

// This binary search program will help in searching for target in the desired half.
int binarySearch(int* arr, int s, int e, int target){
    int ans = -1;
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
    return ans;
}

// This function help to find the pivot where the array was rotated.
int get_pivot(int* arr, int s, int e){
    int mid = s + (e-s)/2;  //Using this to take care of edge cases in normal 
                            //conditions we can use (s+e)/2;
    while(s<e){
        if(arr[0] > arr[mid]){
            e = mid;
        }
        else if(arr[0] <= arr[mid]){
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

// This function clubs the functionalities of get_pivot and binarySearch to find target.

int rotatedSortedSearch(int* arr, int n, int target)//Passing array, size and target.
{
    int ans;
    int s = 0;
    int e = n-1;
    int pivot = get_pivot(arr, s, e);
    if(arr[0]>target){
        ans = binarySearch(arr, pivot, n-1, target);
    }
    else{
        ans = binarySearch(arr, 0, pivot-1, target);
    }
    return ans;
} 

int main(){
    int arr[10] = {7,8,9,0,1,2,3,4,5,6};
    int ans = rotatedSortedSearch(arr, 10, 9);
    cout<<ans;
}

// The output is '2', since 9 is present on the 2nd index.
// This code will produce -1 in case the target is not present in the array.