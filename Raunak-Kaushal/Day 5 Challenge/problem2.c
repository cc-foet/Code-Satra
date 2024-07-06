/*
Problem :  Find the maximum sum of a subarray from an array of integers?
Intput : arr[] = {1,-2, 6,-1, 3}
Output : 8
*/
#include <stdio.h>
#include<limits.h>
void maxSum(int arr[], int n){
    int max = INT_MIN;
    int maxend = 0;
    
    for(int i=0; i<n; i++){
        maxend += arr[i] ;
        
        if(arr[i] > maxend)
            maxend = arr[i];
        if(maxend > max)
            max = maxend;
    }
    printf("Maximum sum of subarray is : %d", max);
}
int main(){
    int arr[] = {1,-2,6,-1,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    maxSum(arr,n);
    return 0;
}

/*
Output : Maximum sum of subarray is : 8
*/
