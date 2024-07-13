package Array;
import java.util.*;

public class Kadanes_Algorithm {

    public static int kadanes(int arr[], int n)
    {
        int max = Integer.MIN_VALUE;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            if(sum > max)
            {
                max = sum;
            }
            if(sum < 0)
            {
                sum = 0;
            }
        }
        return max;
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
        System.out.println("Maximum sum of subarray is: " + kadanes(arr, n));
    }

    
}
