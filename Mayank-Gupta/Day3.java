/*Problem:
Problem Statement: To make one bouquet we need K adjacent flowers from the garden. Here the garden consists of N different flowers, the ith flower will bloom in the bloomDay[i]. Each flower can be used inside only one bouquets. We have to find the minimum number of days need to wait to make M bouquets from the garden. If we cannot make M bouquets, then return -1.
Input:
M = 2, K = 3
bloomDay = [5, 5, 5, 5, 10, 5, 5]
Output:10 */

public class Day3 {
    public static int minDays(int bloomDay[],int M,int K){
        if (bloomDay.length<(M*K) )return -1;

        int left=1,right=1;
        for (int max:bloomDay){
         right=Math.max(max, right);
        }

        while(left<right){
            int mid=left +(right-left)/2;
            if (canmakebouquets(bloomDay,M,K,mid)) right=mid;
            else left=mid+1;    
        }
        return left;
    }
    public static boolean canmakebouquets(int bloomDay[],int M,int K,int day){
        int flower=0;
        int bouquets=0;
        for (int bloom:bloomDay){
            if (bloom<=day) {
                flower++;
                if (flower==K) {
                    bouquets++;
                    flower=0;
                }
            }else flower=0;
        }
        return bouquets>=M;
    }
    public static void main(String[] args) {
        int M=2,K=3;
        int arr[]={5,5,5,5,10,5,5};
        int result=minDays(arr,M,K);
        System.out.println(result);
    }
}
