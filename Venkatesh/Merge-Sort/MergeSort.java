public class MergeSort {

    public static void mergeSort(int[] array, int n, int m) {
        int[] sorted = new int[n];
        int[] unsorted = new int[m];
        System.arraycopy(array, 0, sorted, 0, n);
        System.arraycopy(array, n, unsorted, 0, m);

        mergeSortRecursion(unsorted, 0, m - 1);
        merge(sorted, unsorted, array);
    }

    private static void mergeSortRecursion(int[] array, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;

            mergeSortRecursion(array, left, mid);
            mergeSortRecursion(array, mid + 1, right);

            merging(array, left, mid, right);
        }
    }

    private static void merging(int[] array, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int[] L = new int[n1];
        int[] R = new int[n2];

        for (int i = 0; i < n1; i++) {
            L[i] = array[left + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = array[mid + 1 + j];
        }

        int i = 0, j = 0;
        int k = left;
        while (i<n1 && j<n2) {
            if (L[i] <= R[j]) {
                array[k] = L[i];
                i++;
            } else {
                array[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            array[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            array[k] = R[j];
            j++;
            k++;
        }
    }

    private static void merge(int[] sorted, int[] unsorted, int[] array) {
        int i = 0, j = 0, k = 0;
        while (i < sorted.length && j < unsorted.length) {
            if (sorted[i] < unsorted[j]) {
                array[k++] = sorted[i++];
            } else {
                array[k++] = unsorted[j++];
            }
        }
        while (i < sorted.length) {
            array[k++] = sorted[i++];
        }
        while (j < unsorted.length) {
            array[k++] = unsorted[j++];
        }
    }
    
    public static void main(String[] args) {
        int[] arr = {1, 5, 9, 11, 15, 19, 77, 30, 80, 97};
        int n = 6;
        int m = 4;
        mergeSort(arr, n, m);
        for (int i : arr) {
            System.out.print(i + ", ");
        }
    }
}