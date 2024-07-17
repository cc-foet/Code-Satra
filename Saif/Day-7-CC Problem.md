# Problem statement
Determine if the given string is a palindrome. Use both stack and queue to check for palindrom


````java
import java.util.Stack;
import java.util.LinkedList;
import java.util.Queue;

public class PalindromeChecker {
    public static boolean isPalindrome(String input) {
        Stack<Character> stack = new Stack<>()  ; // Here I create a stack
        Queue<Character> queue = new LinkedList<>(); // I created  a queue

        // push each character of the input string onto the stack
        // and add each character to the queue
        for (char c : input.toCharArray()) {
            stack.push(c);
            queue.add(c);
        }

        // compare characters from the stack and queue
        while (!stack.isEmpty() && !queue.isEmpty()) {
            if (stack.pop() != queue.poll())    {
                // Here, I am comparing the top element of the stack by calling 'stack.pop()' with the front element of the queue by calling `queue.poll()`
                // queue.poll => remove the first element of the queue and return it;
                // If both are not equal then it will return false ; else true;
                return false; // not a palindrome
            }
        }

        return true; // palindrome
    }

    public static void main(String[] args) {
        System.out.println(isPalindrome("madam")); // true
        System.out.println(isPalindrome("hello")); // false
    }
}
````
