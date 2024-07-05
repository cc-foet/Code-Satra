//? Leetcode ques 70  Climbing stairs

public class Day4Ques1 {
    public static void main(String[] args) {
        int n = 5;
        System.out.println(climbStairs(n));
    }
    public static int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        
        int first = 1;
        int second = 2;
        
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        
        return second;
}
}