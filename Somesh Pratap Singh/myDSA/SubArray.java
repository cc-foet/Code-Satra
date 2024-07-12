package Array;

import java.util.*;


public class SubArray    
 {

    public static int[] subarray(int[] arr, int s)
     {

        int n = arr.length;
        int sum = 0;
        for(int i = 0; i < n; i++) 
        {
            sum = arr[i];
            for (int j = i+1; j < n; j++) 
            {
                if (sum == s) 
                {
                    return new int[]{i, j - 1};
                } else if (sum > s || j == n) 
                {
                    break;
                } else
                 {
                    sum += arr[j];
                }
            }
        }
        return new int[]{-1,-1};
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array :");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the elements of the array :");
        for(int i = 0; i < n; i++)
        {
            arr[i] = sc.nextInt();
        }
        System.out.println("Enter the sum to be found :");
        int s = sc.nextInt();
    

        int[] result = subarray(arr, s);
        System.out.println(result[0] + "-" + result[1]);
    }
}
