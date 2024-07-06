import java.util.*;

public class reversal {
    public static void reverse(Queue<Integer> a){
        Stack<Integer> s = new Stack<>();
        while(!a.isEmpty()){
            s.push(a.remove());
        }
        while(!s.isEmpty()){
            a.add(s.pop());
        }
    }
    public static void main(String args[]){
        Queue<Integer> s = new LinkedList<>();
        s.add(1);
        s.add(2);
        s.add(3);
        s.add(4);
        s.add(5);
        s.add(6);

        reverse(s);

        while(!s.isEmpty()){
            System.out.print(" "+ s.remove());
        }

    }    
}
