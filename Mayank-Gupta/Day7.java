import java.util.LinkedList;
import java.util.Stack;
import java.util.Queue;

public class Day7 {
    public static boolean ispalindrome (String str){
        Stack<Character> stack =new Stack<>();
        Queue<Character> queue= new LinkedList<>();
    for (char ch: str.toCharArray()) {
        stack.push(ch);
        queue.add(ch);
    }
    while(!stack.isEmpty()){
        if (stack.pop()!=queue.remove()) return false;
    }
    return true;
    }
    public static void main(String[] args) {
        String str="CodeSatra";
        System.out.println(str+" is palindrome: "+ispalindrome(str.toLowerCase()));
    }
    
}
