package Array;  
import java.util.*;
import java.util.Arrays;

public class MissingNum{
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
        
        Arrays.sort(arr);

         int t = 1;
        for (int i = 0; i < n; i++) 
        {
            if (arr[i] == t) 
            {
                t++;
            } 
            else if(arr[i] > t)
            {
                break;
            }
        }
       System.out.println("Smallest positive missing number: " + t);
    }
}
