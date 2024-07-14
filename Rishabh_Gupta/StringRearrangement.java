import java.util.*;

public class StringRearrangement {

    public static String rearrangeString(String input) {
        //Yahan Pe frequency mapping hogi ki kitne occurence hain
        Map<Character, Integer> frequencyMap = new HashMap<>();
        for (char c : input.toCharArray()) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }

        // Creation of Priority Queue
        PriorityQueue<Character> maxHeap = new PriorityQueue<>((a, b) -> frequencyMap.get(b) - frequencyMap.get(a));
        maxHeap.addAll(frequencyMap.keySet());

        StringBuilder result = new StringBuilder();
        while (!maxHeap.isEmpty()) {
            char current = maxHeap.poll();
            if (result.length() == 0 || result.charAt(result.length() - 1) != current) {
                result.append(current);
                frequencyMap.put(current, frequencyMap.get(current) - 1);
                if (frequencyMap.get(current) > 0) {
                    maxHeap.offer(current); //back to the heap
                }
            } else {
                char next = maxHeap.poll();
                if (next == '\0') {
                    // No valid character remains
                    return "";
                }
                result.append(next);
                frequencyMap.put(next, frequencyMap.get(next) - 1);
                if (frequencyMap.get(next) > 0) {
                    maxHeap.offer(next); //back to the heap
                }
                maxHeap.offer(current);
            }
        }

        return result.toString();
    }

    public static void main(String[] args) {
        String input = "aaabbc";
        String output = rearrangeString(input);
        System.out.println("Input: " + input);
        System.out.println("Output: " + output);
    }
}
