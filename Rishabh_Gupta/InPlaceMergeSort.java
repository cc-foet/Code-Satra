public class InPlaceMergeSort {

    // Method to merge two sorted subarrays
    public static void conquer(int arr[], int si, int mid, int ei) {
        int merged[] = new int[ei - si + 1];
        int idx1 = si;
        int idx2 = mid + 1;
        int x = 0;
        
        while (idx1 <= mid && idx2 <= ei) {
            if (arr[idx1] <= arr[idx2]) {
                merged[x++] = arr[idx1++];
            } else {
                merged[x++] = arr[idx2++];
            }
        }
        
        while (idx1 <= mid) {
            merged[x++] = arr[idx1++];
        }
        
        while (idx2 <= ei) {
            merged[x++] = arr[idx2++];
        }
        
        for (int i = 0, j = si; i < merged.length; i++, j++) {
            arr[j] = merged[i];
        }
    }

    // Method to sort the array using divide and conquer
    public static void divide(int arr[], int si, int ei) {
        if (si >= ei) {
            return;
        }

        int mid = si + (ei - si) / 2;
        divide(arr, si, mid);
        divide(arr, mid + 1, ei);
        conquer(arr, si, mid, ei);
    }

    public static void main(String[] args) {
        int[] nums = {1, 3, 6, 19, 11, 16};
        int n = 3;
        int m = nums.length - 1;

        // Calling divide method to sort element
        divide(nums, n, m);

        // Calling the Merge method to merge the first n sorted elements with the sorted last m elements
        conquer(nums, 0, n - 1, m);
        
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println();
    }
}
