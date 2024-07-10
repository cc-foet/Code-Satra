// Problem: Kth element of two sorted arrays

public class Day5 {
    public static int findKthElement(int[] arr1, int[] arr2, int K) {
        return findKthUtil(arr1, arr2, 0, 0, K);
    }

    private static int findKthUtil(int[] arr1, int[] arr2, int start1, int start2, int K) {
        // If arr1 is exhausted, return K-th element from arr2
        if (start1 >= arr1.length) {
            return arr2[start2 + K - 1];
        }

        // If arr2 is exhausted, return K-th element from arr1
        if (start2 >= arr2.length) {
            return arr1[start1 + K - 1];
        }

        // If K is 1, return the minimum of the first elements of both arrays
        if (K == 1) {
            return Math.min(arr1[start1], arr2[start2]);
        }

        // Calculate the middle elements of the current ranges in both arrays
        int mid1 = Integer.MAX_VALUE;
        int mid2 = Integer.MAX_VALUE;

        if (start1 + K / 2 - 1 < arr1.length) {
            mid1 = arr1[start1 + K / 2 - 1];
        }

        if (start2 + K / 2 - 1 < arr2.length) {
            mid2 = arr2[start2 + K / 2 - 1];
        }

        // Recursively eliminate the K/2 elements from one of the arrays
        if (mid1 < mid2) {
            return findKthUtil(arr1, arr2, start1 + K / 2, start2, K - K / 2);
        } else {
            return findKthUtil(arr1, arr2, start1, start2 + K / 2, K - K / 2);
        }
    }

    public static void main(String[] args) {
        int[] arr1 = {2, 3, 6, 7, 9};
        int[] arr2 = {1, 4, 8, 10};
        int K = 5;
        System.out.println("The " + K + "th element in the merged sorted array is: " + findKthElement(arr1, arr2, K));
    }
}
