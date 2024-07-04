public class BinarySearch {

    public static boolean possible (int[] arr, int day, int m, int k){
        int count = 0;
        int noOfB = 0;
        for(int i=0; i<arr.length; i++){
            if(arr[i] <= day){
                count ++;
            }
            else{
                noOfB = noOfB + (count/k);
                count = 0;
            }
        }
        noOfB = noOfB + (count/k);
        return (noOfB >=m);
    }
    public static int flower (int[]arr , int k ,int m){
        long val = (long) m*k;
        int n = arr.length;
        if(val > n) return -1;

        int mini = Integer.MAX_VALUE;
        int maxi = Integer.MIN_VALUE;
        for(int i=0; i<n ; i++){
            mini = Math.min(mini, arr[i]);
            maxi = Math.max(maxi, arr[i]);
        }

        int low = mini;
        int high = maxi;
        while(low<=high) {
            int mid = (low + high)/2;
            if(possible(arr, mid, m, k)){
                high = mid - 1;
            }else{
                low = mid +1;
            }
        }
        return low;
    }
    public static void main(String[] args) {
        int[] arr = {5, 5, 5, 5, 10, 5, 5};
        int k = 3;
        int m = 2;
        int ans = flower(arr, k, m);
        System.out.println(ans);
    }
}
