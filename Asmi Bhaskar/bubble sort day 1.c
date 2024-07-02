#include <stdio.h>

void bubbleSort(int numbers[], int length, int* SwapCounter) {
    int tempVar;
    *SwapCounter = 0;
    for (int i = 0; i < length-1; i++) {
        int swapped = 0; 
        for (int j = 0; j < length-i-1; j++) {
            if (numbers[j] > numbers[j+1]) {
                tempVar = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = tempVar;
                (*SwapCounter)++;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

void printArray(int arr[], int size) {
    for (int k = 0; k < size; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
}

int main() {
    int dataArray[] = {64, 34, 25, 12, 22, 11, 90};
    int arrayLength = sizeof(dataArray)/sizeof(dataArray[0]);
    int SwapCounter;

    bubbleSort(dataArray, arrayLength, &SwapCounter);

    printf("Sorted array: \n");
    printArray(dataArray, arrayLength);
    printf("Number of swaps: %d\n", SwapCounter);

    return 0;
}
