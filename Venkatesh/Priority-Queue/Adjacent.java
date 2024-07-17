import java.util.PriorityQueue;
import java.util.Map;
import java.util.HashMap;

public class Adjacent {
    public static String rearrange(String s) {
        Map<Character, Integer> freq = new HashMap<>();
        for (char c : s.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }

        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        for (Map.Entry<Character, Integer> entry : freq.entrySet()) {
            maxHeap.add(new int[] {entry.getKey(), entry.getValue()});
        }

        StringBuilder result = new StringBuilder();
        int[] prev = new int[] {-1, -1};

        while (!maxHeap.isEmpty()) {
            int[] current = maxHeap.poll();
            result.append((char) current[0]);
            if (prev[1] > 0) {
                maxHeap.add(prev);
            }
            current[1]--;
            prev = current;
        }

        return result.length() == s.length() ? result.toString() : "";
    }
    public static void main(String[] args) {
        String s = "caaabbbaacdddd";
        System.out.println(rearrange(s));
    }
}