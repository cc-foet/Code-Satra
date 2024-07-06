package DSA;
import java.util.Arrays;

public class divideandconquer {

    public static int Kth(int[] arr1, int[] arr2, int k) {
        int[] merged = new int[arr1.length + arr2.length];
        int i = 0, j = 0, index = 0;

       
        while (i < arr1.length && j < arr2.length) {
            if (arr1[i] < arr2[j]) {
                merged[index++] = arr1[i++];
            } else {
                merged[index++] = arr2[j++];
            }
        }

        
        while (i < arr1.length) {
            merged[index++] = arr1[i++];
        }

        
        while (j < arr2.length) {
            merged[index++] = arr2[j++];
        }

        
        return merged[k - 1];
    }

    public static void main(String[] args) {
        int[] arr1 = {2, 3, 6, 7, 9};
        int[] arr2 = {1, 4, 8, 10};
        int k = 6;
        System.out.println(Kth(arr1, arr2, k));  
    }
}

// At k=6 output will be 7 

    

