//? Leeetcode ques
import java.util.ArrayList;
import java.util.List;
public class Day7ques1 {
    public static void main(String[] args) {
        int n = 5; 
        int k = 2; 

        int ans = findTheWinner(n, k);
        System.out.println("The winner is friend number " + ans);
    }
    public static int findTheWinner(int n, int k) {
        List<Integer> friends = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            friends.add(i);
        }
        
        int idx = 0;
        while (friends.size() > 1) {
            idx = (idx + k - 1) % friends.size();
            friends.remove(idx);
        }
        
        return friends.get(0);
    }
}
