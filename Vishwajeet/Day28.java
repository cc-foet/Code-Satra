// Problem: LongestSubarrayWithKIncrements: Given an integer array  arr and a number K, the task is to find the length of the longest subarray such that all the elements in the subarray can be made the same in at most K increments.

// Segment Trees : It is a binary tree used for storing the intervals or segments. It allows querying which segments contain a given poin, and efficiently answers range queries and updates.

// Time Complexity: O(N^2) where N is the number of elements in the array because we are iterating over all the subarrays.

// Space Complexity: O(N) where N is the number of elements in the array because we are using a segment tree to store the maximum value in the range.

import java.util.Arrays;

// Segment Tree class
class SegmentTree {
    int[] tree;
    int n;

    // Constructor
    public SegmentTree(int[] arr) {
        n = arr.length;
        tree = new int[4 * n];
        buildTree(arr, 0, n - 1, 0);
    }

    // Build the segment tree
    private void buildTree(int[] arr, int start, int end, int node) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(arr, start, mid, 2 * node + 1);
            buildTree(arr, mid + 1, end, 2 * node + 2);
            tree[node] = Math.max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    // Range max query
    public int rangeMaxQuery(int l, int r) {
        return rangeMaxQuery(0, n - 1, l, r, 0);
    }

    // Helper function for range max query
    private int rangeMaxQuery(int start, int end, int l, int r, int node) {
        if (r < start || l > end) {
            return Integer.MIN_VALUE;
        }
        if (l <= start && r >= end) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftMax = rangeMaxQuery(start, mid, l, r, 2 * node + 1);
        int rightMax = rangeMaxQuery(mid + 1, end, l, r, 2 * node + 2);
        return Math.max(leftMax, rightMax);
    }
}

// Main class
public class Day28 {
    public static int[] longestSubarrayWithKIncrements(int[] arr, int K) {
        int n = arr.length;
        SegmentTree segmentTree = new SegmentTree(arr);
        int maxLength = 0;
        int start = 0;
        int[] newArray = arr.clone();

        // Find the longest subarray
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int maxInRange = segmentTree.rangeMaxQuery(i, j);
                int totalIncrements = (j - i + 1) * maxInRange - sumOfRange(arr, i, j);
                if (totalIncrements <= K) {
                    if (j - i + 1 > maxLength) {
                        maxLength = j - i + 1;
                        start = i;
                    }
                } else {
                    break;
                }
            }
        }

        // Apply the increments to form the new array
        int maxValueInRange = segmentTree.rangeMaxQuery(start, start + maxLength - 1);
        for (int i = start; i < start + maxLength; i++) {
            newArray[i] = maxValueInRange;
        }

        System.out.println("Length of the longest subarray: " + maxLength);
        
        System.out.println("New array after increments: " + Arrays.toString(newArray));
        return newArray;
    }

    // Helper function to calculate the sum of the range
    private static int sumOfRange(int[] arr, int l, int r) {
        int sum = 0;
        for (int i = l; i <= r; i++) {
            sum += arr[i];
        }
        return sum;
    }

    public static void main(String[] args) {
        int[] arr = {2, 0, 4, 6, 7};
        int K = 6;
        longestSubarrayWithKIncrements(arr, K);
    }
}
