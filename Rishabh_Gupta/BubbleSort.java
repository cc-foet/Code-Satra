public class BubbleSort {
    //Day 1 Challenge of Code-Satra
    public static int[] bubbleSort(int[] arr) {
        int n = arr.length;
        int numSwaps = 0;
        int[] sortedArray = arr.clone(); // To keep the original array unchanged

        for (int i = 0; i < n; i++) {
            boolean swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (sortedArray[j] > sortedArray[j + 1]) {
                    // Swapping of the element
                    int temp = sortedArray[j];
                    sortedArray[j] = sortedArray[j + 1];
                    sortedArray[j + 1] = temp;
                    numSwaps++;
                    swapped = true;
                }
            }
            // If no elements were swapped, break the loop
            if (!swapped) {
                break;
            }
        }
        System.out.println("Number of Swaps: " + numSwaps);
        return sortedArray;
    }
    public static void printArray(int [] arr){
        int n = arr.length;
        for(int i = 0; i<n; i++){
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        int[] result = bubbleSort(arr);
        printArray(result);
    }
}
