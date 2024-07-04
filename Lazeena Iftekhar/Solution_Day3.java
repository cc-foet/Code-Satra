class Solution_Day3 {

    public static void main(String[] args) {

        int[] bloomDay = {5, 5, 5, 5, 10, 5, 5};
        System.out.println(minNumberofDays(2, 3, bloomDay));

    }

    public static int minNumberofDays(int M, int K, int[] bloomDay) {
       
        long val=(long) M * K;

       if((val) > bloomDay.length) {
           return -1;
       } 

       int res = -1;
       int low = Integer.MAX_VALUE;
       int high = Integer.MIN_VALUE;
       
       for(int i = 0;i <bloomDay.length; i++) {
           low = Math.min(low,bloomDay[i]);
           high = Math.max(high,bloomDay[i]);
       }
       while(low <= high) {
           int  mid = low + (high-low) / 2 ;

           if(check(bloomDay, M, K, mid)) {
               res =  mid;
               high = mid - 1;
           }
           else {
               low = mid + 1;
           }
       }
        return res;
        
     }
    
    static boolean check(int arr[],int flower,int days,int mid) {
        int count = 0;
    
        for(int i = 0;i < arr.length; i++){

            if(arr[i] <= mid) {
                count++;
            }

           else {
           count = count - (count % days);
           }
        }
          count = count / days;
      
      return count >= flower;
    }

}