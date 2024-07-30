// Problem: Given an array, count the number of inversions using a Fenwick Tree. An inversion is a pair of indices i, j such that i < j and a[i] > a[j].

// Fenwick Tree is a data structure that can efficiently update elements and calculate prefix sums in a table of numbers.

// Time Complexity: O(n log n) because we need to sort the array where n is the length of the array

// Space Complexity: O(n) because we need to store the sorted array and the Fenwick Tree

import java.util.Arrays;

public class Day29 {

    // Fenwick Tree class
    static class FenwickTree {
        private int[] tree;

        // Constructor
        public FenwickTree(int size) {
            tree = new int[size + 1];
        }

        // Update Method
        public void update(int index, int value) {
            while (index < tree.length) {
                tree[index] += value;
                index += index & -index;
            }
        }

        // Query method
        public int query(int index) {
            int sum = 0;
            while (index > 0) {
                sum += tree[index];
                index -= index & -index;
            }
            return sum;
        }

        // Overloaded query method
        public int query(int left, int right) {
            return query(right) - query(left - 1);
        }
    }

    public static int countInversions(int[] arr) {
        // Step 1: Normalize the array elements to ranks
        int[] sortedArr = arr.clone();
        Arrays.sort(sortedArr);

        // Use a map or binary search to normalize the array
        for (int i = 0; i < arr.length; i++) {
            arr[i] = Arrays.binarySearch(sortedArr, arr[i]) + 1;
        }

        // Step 2: Use Fenwick Tree to count inversions
        FenwickTree fenwickTree = new FenwickTree(arr.length);
        int inversionCount = 0;

        for (int i = arr.length - 1; i >= 0; i--) {
            inversionCount += fenwickTree.query(arr[i] - 1);
            fenwickTree.update(arr[i], 1);
        }

        return inversionCount;
    }

    public static void main(String[] args) {
        int[] arr = {8, 4, 2, 1};
        System.out.println("Number of inversions: " + countInversions(arr)); // Output: 6
    }
}
