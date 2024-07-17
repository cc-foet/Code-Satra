/* Day 8 Problem 
Given an arr[] containing n integers and a positive integer k, find the length of the longest subarray with the sum of the elements divisible by the given value k.

Input:
arr[] = {2, 7, 6, 1, 4, 5}
k = 3

Output: 4
*/

#include<stdio.h>
#include<limits.h>

int longSubArray(int arr[], int n, int k){
    int maxlength = INT_MIN;

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum = sum + arr[j];
            if(sum % k == 0){
                if(j - i + 1 > maxlength){
                    maxlength = j - i + 1;
                }
            }
        }
    }
    
    return maxlength;
}

int main() {
    int arr[] = {2, 7, 6, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int result = longSubArray(arr, n, k);
    printf("length of the longest subarray is %d\n", result);

    return 0;
}

/*
Output : length of the longest subarray is 4
*/