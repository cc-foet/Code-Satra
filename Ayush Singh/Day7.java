import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class IsPalindrome {
    public static boolean isPalindrome(String input) {

        // Create a stack and a queue
        Stack<Character> stack = new Stack<>();
        Queue<Character> queue = new LinkedList<>();


        for (char c : input.toCharArray()) {
            stack.push(c);
            queue.add(c);
        }

        //  Last Element is being Compared with The First Element Here
        while (!stack.isEmpty()) {
            if (stack.pop() != queue.remove()) {
                return false; 
            }
        }

        return true;
    }

    public static void main(String[] args) {
        String input = "CodeSatra";
        if (isPalindrome(input)) {
            System.out.println("True");
        } else {
            System.out.println("False");
        }
    }
