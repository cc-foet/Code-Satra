package Stringg;

public class LCS 
{
    public static int  LCSof3Strings(String a, String b,String c)
    {
        int n = a.length();
        int m = b.length();
        int o = c.length();
        int dp[][][] = new int[n+1][m+1][o+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=o;k++)
                {
                    if(i==0 || j==0 || k==0)
                    {
                        dp[i][j][k]=0;
                    }
                    else if(a.charAt(i-1)==b.charAt(j-1) && b.charAt(j-1)==c.charAt(k-1))
                    {
                        dp[i][j][k]=1+dp[i-1][j-1][k-1];
                    }
                    else
                    {
                        dp[i][j][k]=Math.max(dp[i-1][j][k],Math.max(dp[i][j-1][k],dp[i][j][k-1]));
                    }
                }
            }
        }
        return dp[n][m][o];
    }
    public static void main(String[] args) 
    {
      String a="Somesh";
        String b="Somes";
        String c="Som";
        
        System.out.println(LCSof3Strings(a,b,c));
    }
    
}
