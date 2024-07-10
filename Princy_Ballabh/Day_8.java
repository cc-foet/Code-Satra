import java.util.*;
public class Day_8 {
    public static void main(String args[]){
        int arr[]={2,7,6,1,4,5};
        int k=3;
        System.out.println("Maximum length of the subarray : "+subarray(arr,k));
    }

    public static int subarray(int arr[], int k){
        int sum=0,rem=0,ans=0,i,len,id;
        HashMap<Integer,Integer> mp=new HashMap<Integer,Integer>();
        mp.put(0,-1);
        for(i=0;i<arr.length;i++){
            sum+=arr[i];
            rem=sum%k;
            if(sum<0)
            rem+=k;
            if(mp.containsKey(rem)){
                id=mp.get(rem);
                len=i-id;
                if(len>ans)
                ans=len;
            }
            else{
                mp.put(rem,i);
            }
        }
        return ans;
    }
}
