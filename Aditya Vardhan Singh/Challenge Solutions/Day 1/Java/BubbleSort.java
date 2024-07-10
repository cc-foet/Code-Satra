class BubbleSort {
  int bubbleSortAndCount(int[] arr, int n) {
    boolean swap_flag = false;
    int swaps = 0;
    int temp;

    for (int i = 0; i < n; i++) {
      swap_flag = false;
        for (int j = 0; j < n - i - 1; j++) {
          if (arr[j] > arr[j+1]) {
            // swap
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            // count swaps
            swaps++;
            // trun off flag
            swap_flag = true;
          }
        }
        if (!swap_flag) break;
    }

    return swaps;
  }

  void printArray(int[] arr, int n) {
    System.out.print("[ ");
    for (int i = 0; i < n; i++) {
      System.out.printf("%d ", arr[i]);
    }
    System.out.println("]");
  }

  public static void main(String[] args) {
    int[] arr = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;

    BubbleSort ob = new BubbleSort();

    ob.printArray(arr, n);
    int swaps = ob.bubbleSortAndCount(arr, n);
    System.out.print("Sorted array: ");
    ob.printArray(arr, n);
    System.out.printf("Number of swaps: %d\n", swaps);
  }
}
