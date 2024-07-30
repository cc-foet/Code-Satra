import java.util.Arrays;

public class Day_28{
    public static void main(String args[]){
        int arr[]={2,0,4,6,7};
        int K=6;
        int ans=findsubarray(arr,K);
        System.out.println("Output: "+ans);
    }

    public static int findsubarray(int[] arr, int K){
        int n=arr.length;
        Arrays.sort(arr);
        int maxLength=0;
        int start=0;
        int sum=0;
        for(int end=0;end<n;end++){
            sum+=arr[end];
            while(arr[end]*(end-start+1)-sum>K){
                sum-=arr[start];
                start++;
            }
            maxLength=Math.max(maxLength, end-start+1);
        }
        return maxLength;
    }
}
