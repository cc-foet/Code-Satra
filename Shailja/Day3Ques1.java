public class Day3Ques1 {
    public static void main(String[] args) {
      int arr[] = {3,4,-1,1};
      int ans= firstMissingPositive(arr);
      System.out.println(ans);

    }
        public static int firstMissingPositive(int[] nums) {
            int i = 0;
            while (i < nums.length) {
                int correctindex = nums[i]-1 ;
                if (nums[i]>0 && nums[i]<=nums.length && nums[i] != nums[correctindex]) {
                    int temp = nums[i];
                    nums[i] = nums[correctindex];
                    nums[correctindex] = temp;
                } else {
                    i++;
                }
            }
            for (int j = 0; j < nums.length; j++) {
                if (nums[j] != j+1 ) {
                    return j+1;
                }
            }
        
    return nums.length+1;
}
}