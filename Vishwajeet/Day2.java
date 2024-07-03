// Problem: Given an array of number of length n+m where first n elements are sorted . Your task is to sort the last m elemnets in place so that the whole array becomes sorted .

import java.util.Arrays;

public class Day2 {
    
    // Method to merge two sorted parts of the array
    public static void merge(int[] arr, int n, int m) {
        // Create three pointers
        int i = n - 1; // Last element of the first sorted part
        int j = n + m - 1; // Last element of the second sorted part
        int k = n + m - 1; // Last position of the merged array
        
        // Merge the two parts from the end
        while (i >= 0 && j >= n) {
            if (arr[i] > arr[j]) {
                arr[k--] = arr[i--];
            } else {
                arr[k--] = arr[j--];
            }
        }
        
        // Copy remaining elements of the second sorted part
        while (j >= n) {
            arr[k--] = arr[j--];
        }
        
        // Copy remaining elements of the first sorted part
        while (i >= 0) {
            arr[k--] = arr[i--];
        }
    }

    // Method to sort the last m elements of the array
    public static void sortLastMElements(int[] arr, int n, int m) {
        Arrays.sort(arr, n, n + m); // Sort the last m elements
    }

    // Main method
    public static void main(String[] args) {
        int[] arr = {1, 3, 6, 19, 11, 16};
        int n = 3;
        int m = 3;
        
        // Sort the last m elements
        sortLastMElements(arr, n, m);
        
        // Merge the two sorted parts
        merge(arr, n, m);
        
        // Print the sorted array
        System.out.println(Arrays.toString(arr));
    }
}
