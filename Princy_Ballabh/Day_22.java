public class Day_22{

    public static void main(String args[]){
        String str1="abcd1e2",str2="bc12ea",str3="bd1ea";
        int result=subsequence(str1,str2,str3);
        System.out.println("Output: "+result);
    }

    public static int subsequence(String str1, String str2, String str3){
        int a=str1.length(),b=str2.length(),c=str3.length();
        int[][][] dp=new int[a+1][b+1][c+1];
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                for(int k=1;k<=c;k++){
                    if(str1.charAt(i-1)==str2.charAt(j-1) && str2.charAt(j-1)==str3.charAt(k-1))
                        dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                    else 
                        dp[i][j][k]=Math.max(dp[i-1][j][k],Math.max(dp[i][j-1][k],dp[i][j][k-1]));
                }
            }
        }
        return dp[a][b][c];
    }
   
}
