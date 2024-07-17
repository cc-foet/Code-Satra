import java.util.Arrays;

public class SortArray {
    public static void merge(int[] arr, int n, int m) {
        int[] temp = new int[n + m];
        int i = 0, j = n, k = 0;

        while (i < n && j < n + m) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i < n) {
            temp[k++] = arr[i++];
        }

        while (j < n + m) {
            temp[k++] = arr[j++];
        }

        for (i = 0; i < n + m; i++) {
            arr[i] = temp[i];
        }
    }

    public static void sortArray(int[] arr, int n, int m) {
        Arrays.sort(arr, n, n + m);
        merge(arr, n, m);
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 7, 2, 6, 4, 8};
        int n = 4;  
        int m = 4;  

        System.out.println("Original array: " + Arrays.toString(arr));

        sortArray(arr, n, m);

        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}

