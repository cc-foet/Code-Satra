public class DAY3Ques2 {
    public static void main(String[] args) {
        int[] arr={5,5,5,5,10,5,5};
        int ans= minDays(arr, 3,4 );
        System.out.println(ans);
    }
    public static int minDays(int[] arr , int m,int k){
       int n=m*k;
       int ans=0;
        for(int i=0;i<arr.length;i++){
         if(arr[i] >n){
      return arr[i];
         }
        }
        return -1;
    }
}
