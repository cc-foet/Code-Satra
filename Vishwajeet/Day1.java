/**
 * A Java program to implement Bubble Sort Algorithm with Swaps and count the total number of swaps.
 */
public class Day1 {
    public static Object[] bubbleSortWithSwaps(int[] array) {
        int n = array.length;
        int[] sortedArray = array.clone();
        int swapCount = 0;
        boolean swapped;

        // Bubble Sort Algorithm
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - 1 - i; j++) {
                if (sortedArray[j] > sortedArray[j + 1]) {
                    // Swap the elements
                    int temp = sortedArray[j];
                    sortedArray[j] = sortedArray[j + 1];
                    sortedArray[j + 1] = temp;
                    swapCount++;
                    swapped = true;
                }
            }
            // If no two elements were swapped by inner loop, then break
            if (!swapped) break;
        }

        // Return the sorted array and the total number of swaps
        return new Object[]{sortedArray, swapCount};
    }

    public static void main(String[] args) {
        int[] array = {64, 34, 25, 12, 22, 11, 90};
        Object[] result = bubbleSortWithSwaps(array);
        int[] sortedArray = (int[]) result[0];
        int swapCount = (int) result[1];

        System.out.println("Sorted array: ");
        for (int num : sortedArray) {
            System.out.print(num + " ");
        }
        System.out.println("\nTotal number of swaps: " + swapCount);
    }
}
