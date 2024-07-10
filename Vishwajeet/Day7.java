// Problem: Determine if a string is a palindrome using a stack and queue

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Day7 {

    public static boolean isPalindrome(String str) {
        Stack<Character> stack = new Stack<>();  // LIFO
        Queue<Character> queue = new LinkedList<>(); // FIFO
        
        // Remove spaces and convert to lower case for uniform comparison
        String cleanedStr = str.replaceAll("\\s+", "").toLowerCase();
        
        // Add all characters to stack and queue
        for (char ch : cleanedStr.toCharArray()) {
            stack.push(ch);
            queue.add(ch);
        }

        // Compare characters from stack and queue
        while (!stack.isEmpty() && !queue.isEmpty()) {
            if (stack.pop() != queue.remove()) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        String testStr1 = "code satra";
        String testStr2 = "racecar";
        
        System.out.println("\"" + testStr1 + "\" is palindrome: " + isPalindrome(testStr1));
        System.out.println("\"" + testStr2 + "\" is palindrome: " + isPalindrome(testStr2));
    }
}
