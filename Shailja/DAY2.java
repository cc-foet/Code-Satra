import java.util.Arrays;

public class DAY2 {
  public static void main(String[] args) {
    int[] nums={1,3,6,19,11,16};
    int[] ans=sortArray(nums, 3, 3);
    System.out.println(Arrays.toString(ans));
  }
     public static int[] sortArray(int[] nums , int n, int m) {
           for(int i=m;i<nums.length-1;i++){
            for(int j=i+1;j<nums.length;j++){
                if(nums[i]>nums[j]){
                    int temp=nums[i];
                    nums[i]=nums[j];
                    nums[j]=temp;
                }
            }
           }
        return nums;
     }
    
}