import java.util.Arrays;

public class Day_21{
    public static void main(String args[]){
        int coins[]={9,6,5,1};
        int v=11;
        int n=coins.length;
        int ans=mincoins(coins,n,v);
        System.out.println("Output: "+ans); 
    }

    public static int mincoins(int coins[], int n, int v){
        int dp[]=new int[v+1];
        Arrays.fill(dp,v+1);
        dp[0]=0;
        for(int i=1;i<=v;i++){
            for(int j=0;j<n;j++){
                if(coins[j]<=i){
                    dp[i]=Math.min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        return dp[v]>v?-1:dp[v];
    }
}
