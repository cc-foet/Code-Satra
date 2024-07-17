package Array;

public class TrappingRainWater 
{

    public static long trappingWater(int arr[], int n)
     {
        int[] left = new int[n];
        int[] right = new int[n];
        int max = arr[0];
        for (int i = 0; i < n; i++) 
        {
            max = Math.max(max, arr[i]);
            left[i] = max;
        }
        max = arr[n - 1];
        for (int i = n - 1; i >= 0; i--) 
        {
            max = Math.max(max, arr[i]);
            right[i] = max;
        }
        long sum = 0;
        for (int i = 0; i < n; i++)
         {
            sum += Math.min(left[i], right[i]) - arr[i];
        }
        return sum;
    }
    public static void main(String[] args) {
        int[] arr = {3, 0, 0, 2, 0, 4};
        int n = arr.length;
        System.out.println(trappingWater(arr, n));
    }
    
}
