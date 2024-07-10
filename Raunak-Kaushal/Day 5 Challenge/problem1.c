/*
Day 3 Problem ? 
Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the kth position of the final sorted array.
Input:
arr1[] = {2, 3, 6, 7, 9} 
arr2[] = {1, 4, 8, 10) 
k = 5
Output: 6
*/

#include <stdio.h>

int main() {
    int arr1[] = {2, 3, 6, 7, 9};
    int arr2[] = {1, 4, 8, 10};
    int k = 5; //position of element

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    if(k < 1 || k > n + m){
        printf("invalid value of k\n");
        return 1;
    }

    int i = 0, j = 0, count = 0, elem = 0;

    while(count < k){
        if(i < n && (j >= m || arr1[i] < arr2[j])){
            elem = arr1[i];
            i++;
        } 
        else{
            elem = arr2[j];
            j++;
        }
        count++;
    }
    printf("The %dth element is %d\n", k, elem);
    return 0;
}

/*
Output : The 5th element is 6
*/