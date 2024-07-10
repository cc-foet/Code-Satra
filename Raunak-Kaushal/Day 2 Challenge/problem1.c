/* Day 2 Problem : 

Given an array nums of length n + m where first n elements are sorted. Your task is to sort the last m elements in-place so that the whole array becomes sorted.
Input:
Array = {1, 3, 6, 19, 11, 16}
n = 3
m = 3
Output: 1, 3, 6, 11, 16, 19

*/

#include <stdio.h>
void main() {
    int arr[] = {1, 3, 6, 19, 11, 16};
    int n = 3;
    int m = 3;
    
    // inserstion sort on subarray arr[n] se arr[n + m - 1] tak
    for (int i = n; i < n + m; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= n && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // Temporary array for store merge result
    int temp[n + m];
    int i = 0, j = n, k = 0;

    while (i < n && j < n + m){  // Merge sorted subarray 
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            k++;
            i++;
        } else {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    while(i < n){
        temp[k] = arr[i];
        k++;
        i++;
    }

    while(j < n + m){
        temp[k] = arr[j];
        k++;
        j++;
    }

    for(i = 0; i < n + m; i++){
        arr[i] = temp[i];
    }

    for(int i = 0; i < n + m; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
ye problem karne me time laga first time aisi problem solve kar rhe hai college me sir ne bas merge sort karaya tha lekin ye sort unsort array aisa concept pehli baar dekha hai sikhne ko bhi mila acha program tha kafi time bhi laga.😁
*/