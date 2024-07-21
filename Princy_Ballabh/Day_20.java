public class Day_20{
    public static void main(String args[]){
        int n=4;
        int arr[]={10,20,30,40};
        int k=2;
        System.out.println("The minimum time to paint all boards: "+mintime(arr,n,k));
    }

    private static int sum(int arr[], int s, int e){
        int tot=0,i;
        for(i=s;i<=e;i++)
            tot+=arr[i];
        return tot;
    }

    public static int mintime(int arr[], int n, int k){
        int dp[][]=new int[k+1][n+1];
        int i,j,p;
        for(i=1;i<=n;i++){
            dp[1][i]=sum(arr,0,i-1);
        }
        for(i=1;i<=k;i++){
            dp[i][1]=arr[0];
        }
        for(i=2;i<=k;i++){
            for(j=2;j<=n;j++){ 
                int best=Integer.MAX_VALUE;
                for(p=1;p<=j;p++){
                    best=Math.min(best,Math.max(dp[i-1][p],sum(arr,p,j-1)));
                }
                dp[i][j]=best;
            }
        }
        return dp[k][n];
    }  
}
