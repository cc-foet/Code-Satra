import java.util.*;
public class Question1 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
    int[] arr={64,34,25,12,22,11,90};
    int n=arr.length;
     int[] ans= sortedArray(arr);
     System.out.println(Arrays.toString(arr));
     System.out.println("Total no of swaps:" + ans[ans.length-1]  );
    }

     // Function to sort the Array using Bubble sort   

    public static int[] sortedArray(int[] arr){
      int temp=0;
      int n=arr.length;
      int swap=0;
        for(int i=0;i<arr.length-1;i++){
            boolean swapped = false;
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    swap++;
                    swapped=true;
             
                     }
            }
       if(!swapped){
        break;
       }
    }
    int[] result = Arrays.copyOf(arr, n + 1);
    result[n] = swap;
    return result;
        
    }
}


















