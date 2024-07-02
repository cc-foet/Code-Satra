// Day 1 Problem Solve :
#include <stdio.h>

int bubbleSort(int n, int arr[]){
    int i, j, temp;
    int count = 0;

    for (i=0; i<n-1; i++){
        for (j=0; j <n-1-i; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
    }
    return count;
}

void printArray(int size, int arr[]){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("original array: ");
    printArray(n , arr);

    int swapcount = bubbleSort(n , arr);

    printf("sorted array: ");
    printArray(n , arr);
    printf("number of swaps: %d\n", swapcount);

    return 0;
}
