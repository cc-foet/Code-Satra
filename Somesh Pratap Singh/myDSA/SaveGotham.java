package Array;
import java.util.*;

public class SaveGotham {
    public static int save_gotham(int[] arr, int n) {
       Stack<Integer> iambatman=new Stack<>();
         int sum=0;
         int mod=1000000001;
            for(int i=0;i<n;i++)
            {
                while(!iambatman.isEmpty() && arr[i]>iambatman.peek())
                {
                    sum=(sum+arr[i])%mod;
                    iambatman.pop();
                }
                iambatman.push(arr[i]);
            }
            return sum;

    }

    public static void main(String[] args) {
        int arr[] = { 112, 133, 161, 311, 122, 512, 1212, 0, 19212 };
        int n = arr.length;
        System.out.println(save_gotham(arr, n));
    }
    
}
