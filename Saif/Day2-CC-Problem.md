```java

import java.util.Arrays;

// Problem statement
/* Given an array nums of length n + m where first n element are sorted. Your task is to sort the last m elements in plase so that the whole array become sorted;
        Input : Arr = {1, 3, 6, 19, 11, 16}
        n = 3
        m = 3
 *
 *
 * */
public class CC_Day2_Problem {
    public static void main(String[] args) {
        int [] arr = {1, 3, 6, 19, 11, 16};
        mergeSort(arr , 0 , arr.length);
        System.out.println(Arrays.toString(arr));
    }

    public static void mergeSort(int[] arr, int start , int end) {
        if(end-start == 1 ){
            return;

        }
        int mid =  ( start + end) / 2 ;
         mergeSort(arr, start, mid);
        mergeSort(arr, mid, end);
         mergeInPlace(arr, start, mid , end );


    }

    private static void mergeInPlace(int[] arr, int start, int mid, int end) {
        int[] mix  = new int[end -start] ;
            int i = start ;
            int j = mid ;
            int k = 0 ;
            while(i < mid && j < end ){
            if(arr[i] < arr[j]){
                    mix[k] = arr[i];
                    i++;
            }
            else{
            mix[k] = arr[j];
            j++;
        }
            k++;
        }

            while(i < mid){
                mix[k] = arr[i];
                i++;
                k++;

            }
        while (j < end) {
            mix[k] = arr[j];
            j++;
            k++;



        }
        System.arraycopy(mix, 0, arr, start, mix.length);

    }


}

```
