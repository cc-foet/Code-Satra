public class DivideAndConquer {

    public static int findKth(int[] arr1, int[] arr2, int k) {
        return findKthHelper(arr1, 0, arr1.length, arr2, 0, arr2.length, k);
    }

    private static int findKthHelper(int[] arr1, int start1, int len1, int[] arr2, int start2, int len2, int k) {
        if (len1 > len2) {
            return findKthHelper(arr2, start2, len2, arr1, start1, len1, k);
        }
        if (len1 == 0) {
            return arr2[start2 + k - 1];
        }
        if (k == 1) {
            return Math.min(arr1[start1], arr2[start2]);
        }

        int part1 = Math.min(len1, k / 2);
        int part2 = Math.min(len2, k / 2);

        if (arr1[start1 + part1 - 1] < arr2[start2 + part2 - 1]) {
            return findKthHelper(arr1, start1 + part1, len1 - part1, arr2, start2, len2, k - part1);
        } else {
            return findKthHelper(arr1, start1, len1, arr2, start2 + part2, len2 - part2, k - part2);
        }
    }

    public static void main(String[] args) {
        int[] array1 = {2, 3, 6, 7, 9};
        int[] array2 = {1, 4, 8, 10};
        int k = 6;
        System.out.println(findKth(array1, array2, k));  
    }
}
