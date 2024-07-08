import java.util.Queue;
import java.util.Stack;
import java.util.LinkedList;

public class Day_7 {
    public static void main(String args[]){
        String str="CodeSatra";
        System.out.println("Output using stack : "+checkUsingStack(str));
        System.out.println("Output using queue : "+checkUsingQueue(str));
    }

    @SuppressWarnings("unchecked")
    public static String checkUsingStack(String str){
         @SuppressWarnings("rawtypes")
        Stack st = new Stack();
        for(int i=0;i<str.length();i++)
        {
            st.push(str.charAt(i));
        }
        String rev="";
        while(!st.isEmpty()){
            rev=rev+st.pop();
        }
        if(str.equals(rev))
            return("The input String is a palindrome.");
        else
           return("The input String is not a palindrome.");
    }
    @SuppressWarnings("unchecked")
    public static String checkUsingQueue(String str){
        @SuppressWarnings("rawtypes")
        Queue queue=new LinkedList();
        for(int i=str.length()-1;i>=0;i--)
        {
            queue.add(str.charAt(i));
        }
        String rev="";
        while(!queue.isEmpty()){
            rev=rev+queue.remove();
        }
        if(str.equals(rev))
            return("The input String is a palindrome.");
        else
           return("The input String is not a palindrome.");
    }
}
