#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int bubbleSortAndCount(int *arr, int n) {
  // Memory
  int swaps = 0;
  int temp;
  int swap_flag = 0; // flag = false
  int i, j;

  // Bubble sort algorithm
  for (i = 0; i < n; ++i) {
    swap_flag = 0;
    for (j =  0; j < n-i-1; ++j) {
      if (arr[j] > arr[j+1]) { // Sort ascending
        // swap
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        // count no of swaps
        swaps++;
        // turn on swap flag
        swap_flag = 1;
      }
    }
    // if no swap happened, then array is already sorted
    if (!swap_flag) break;
  }

  return swaps;
}

void printArray(int *arr, int n) {
  printf("[ ");
  for (int i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }
  printf("]\n");
}

int main(int argc, char const **argv) {
  // Check arguments
  if (argc != 2) {
    printf("Usage: %s <input file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Open input file
  FILE *fp = fopen(argv[1], "r");

  // Array
  int n;
  int *arr;

  // Input array from file
  if (fscanf(fp, "%d", &n) == EOF) {
    printf("Error: Cannot get size of array.\n");
    return EXIT_FAILURE;
  }
  arr = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    if (fscanf(fp, "%d", &arr[i]) == EOF) {
      printf("Error: Cannot get array element.\n");
      return EXIT_FAILURE;
    }
  }

  // Print array before sort
  printArray(arr, n);

  // Sort Array using bubble sort
  int swaps = bubbleSortAndCount(arr, n);

  // Print array after sort
  printf("Sorted array:");
  printArray(arr, n);
  printf("Number of swaps: %d\n", swaps);

  return EXIT_SUCCESS;
}

// Array ; Swaps
// 64 34 25 12 22 11 90 ; 5
// 34 25 12 22 11 64 90 ; 5 + 4 = 9
// 25 12 22 11 34 64 90 ; 9 + 3 = 12
// 12 22 11 25 34 64 90 ; 12 + 1 = 13
// 12 11 22 25 34 64 90 ; 13 + 1 = 14
// 11 12 22 25 34 64 90 ; 14 + 0 = 14
