import java.util.*;
public class PalindromeSQ {
    

    public static boolean Palindrome(String s) {
        Stack<Character> stack = new Stack<>();
        Queue<Character> queue = new LinkedList<>();

        
        String filteredString = s.toLowerCase();

        
        for (char c : filteredString.toCharArray()) {
            stack.push(c);
            queue.add(c);
        }

        
        while (!stack.isEmpty()) {
            if (stack.pop() != queue.remove()) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        String test1 = "Kayak";
        String test2 = "Naman";
        String test3 = "Venkatesh";

        System.out.println("\"" + test1 + "\" is a palindrome: " + Palindrome(test1));
        System.out.println("\"" + test2 + "\" is a palindrome: " + Palindrome(test2));
        System.out.println("\"" + test3 + "\" is a palindrome: " + Palindrome(test3));
    }
}
