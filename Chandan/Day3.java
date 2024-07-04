

public class Day3 {

    public static int solve(int M, int K, int[] a) {
       
        if((long)M*(long)K>a.length)return -1;
        
        int min=Integer.MAX_VALUE;
        int max=Integer.MIN_VALUE;
        
        
        for(int i: a){
            
            min=Math.min(min,i);
            
            max=Math.max(max,i);
            
        }
        
        
         
        int ans=0;
        
        while(min<=max){
            
            
            int mid=min+(max-min)/2;
            
           
           
         
           
           
           if(fl(mid,K,a)>=M){
               ans=mid;
               max=mid-1;
           }
           else{
                min=mid+1;
              
           }
            
           
            
            
        }
        
        return ans;
        
        
        
     }
     
     
    static int fl(int Mid, int K, int[] a){
         
         int b=0;
         int f=0;
         
         
         
         for(int i=0; i<a.length; i++){
             
             
             if(a[i]>Mid){
                 b+=f/K;
                 f=0;
             }
             else{
                 f++;
             }
          
             
         }
           
      b+=f/K;
         
         return b;
         
     }
    
    public static void main(String[] args) {
        // Sample input
        int M = 2;
        int K = 3;
        int[] bloomDay = {5, 5, 5, 5, 10, 5, 5};


    
        int result = solve(M, K, bloomDay);
        System.out.println("Output: " + result);
    }
}