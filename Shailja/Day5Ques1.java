//? Leetcode ques 2582
public class Day5Ques1 {
        public static void main(String[] args) {
            int n = 4; 
            int time = 5; 
            int result = findPillowHolder(n, time);
            System.out.println("The person holding the pillow after " + time + " seconds is " + result);
        }
    
        public static int findPillowHolder(int n, int time) {
            int cycleLength = 2 * (n - 1);
            
            int effectiveTime = time % cycleLength;
            
            if (effectiveTime < n) {
                return 1 + effectiveTime;
            } else {
                return n - (effectiveTime - (n - 1));
            }
        }
    }
    

