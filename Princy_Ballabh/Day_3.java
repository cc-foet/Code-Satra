public class Day_3 {
    public static void main(String args[])
    {
        int[] arr={5,5,5,5,10,5,5};
        int k=3,m=2;
        System.out.println(mindays(arr,k,m));
    }

    static boolean isposs(int days, int[] arr, int k, int m)
    {
        int ans=0;
        int c=0;
        for (int i=0;i<arr.length;i++) {
            if(arr[i]<=days){
                c++;
            }
            else{
                ans+=c/k;
                c=0;
            }
        }
        ans+=c/k;
        if(ans>=m)
            return true;
        return false;
    }
    static int mindays(int[] arr, int k, int m)
    {
        int start=0,end=(int)1e7;
        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(isposs(mid, arr, k, m)){
                ans=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return ans;
    }
}
