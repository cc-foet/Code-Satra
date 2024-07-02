/* 
Day 1 : Bubble sort problem solving
Problem Statement : Given an array of integers, write a function that sorts the array using the bubble sort algorithm and counts the number of swaps performed during the sorting process. The function should return the sorted array and the total number of swaps. 
*/

#include <stdio.h>

int bubbleSort(int n, int arr[])
{
    int i, j, temp;
    int count = 0;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
    }
    return count;
}

void printArray(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("original array: ");
    printArray(n, arr);

    int swapcount = bubbleSort(n, arr);

    printf("sorted array: ");
    printArray(n, arr);
    printf("number of swaps: %d\n", swapcount);

    return 0;
}

/*

OUTPUT :
original array: 64 34 25 12 22 11 90
sorted array: 11 12 22 25 34 64 90
number of swaps: 14

*/