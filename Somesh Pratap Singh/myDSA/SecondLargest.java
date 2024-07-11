package Array;
import java.util.*; 


public class SecondLargest 
{

    public static int find2ndLargest(int[] arr)
  {
        int max = arr[0];
        int sec_max = arr[0];

        for (int element : arr)
          {
            if (element > max) 
            {
                sec_max = max;
                max = element;
            } 
            else if (element < max && element > sec_max) 
            {
                sec_max = element;
            }
        }
        return sec_max;
    }

    public static void main(String[] args) {
        int[] arr = {12, 35, 1, 10, 38, 1};
        System.out.println("Second Largest element present in array: " + find2ndLargest(arr));
    }
}
//output 35 with this input.
