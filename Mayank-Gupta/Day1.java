/*Problem : Given an Array of integers, Write a function that sorts the array using
 buuble sort algorithm and count the number of swaps. The function should return sorted 
 array and the total number of swaps. */
import java.util.*;
class Day1{
    public static int countswap(int arr[],int n){
        int c=0;// count number of swaps.
        for (int i=0;i<(n-1);i++){//no. of passes
            for (int j=0;j<(n-i-1);j++){
                if (arr[j]>arr[j+1]) {
                    int temp=arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=temp;
                    c++;
                }
            }
        }
        return c;
    }
    public static void display(int[] arr){
        for(int val:arr) System.out.print(val+" ");
        System.out.println();
    }
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter size of array");
        int s=sc.nextInt();
        int arr[]= new int[s];
        System.out.println("Enter elements");
        for(int i=0;i<s;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println("Original Array");
        display(arr);
        int c=countswap(arr,s);
        System.out.println("Sorted Array");
        display(arr);
        System.out.println(c+" swaps performed in sorting given array by bubble sort algorithm");
    }
}