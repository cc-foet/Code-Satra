// Problem: Given a string of lowercase letters, rearrange the characters in such a way that no adjacent characters are the same. If no such arrangement is possible, return an Empty string.

import java.util.HashMap; // Importing the HashMap class
import java.util.Map; // Importing the Map class
import java.util.PriorityQueue; // Importing the PriorityQueue class
import java.util.Comparator; // Importing the Comparator class
 
public class Day13 {

    static class CharFrequency {
        char character;
        int frequency;

        CharFrequency(char character, int frequency) {
            this.character = character;
            this.frequency = frequency;
        }
    }

    public static String rearrangeString(String s) {
        if (s == null || s.length() == 0) return "";

        // Step 1: Count the frequency of each character
        Map<Character, Integer> frequencyMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }

        // Step 2: Create a max heap based on the frequency of characters
        PriorityQueue<CharFrequency> maxHeap = new PriorityQueue<>(new Comparator<CharFrequency>() {
            public int compare(CharFrequency o1, CharFrequency o2) {
                return o2.frequency - o1.frequency;
            }
        });

        for (Map.Entry<Character, Integer> entry : frequencyMap.entrySet()) {
            maxHeap.add(new CharFrequency(entry.getKey(), entry.getValue()));
        }

        // Step 3: Construct the result string
        StringBuilder result = new StringBuilder();
        CharFrequency prev = new CharFrequency('#', -1); // Dummy previous character

        while (!maxHeap.isEmpty()) {
            CharFrequency current = maxHeap.poll();
            result.append(current.character);

            if (prev.frequency > 0) {
                maxHeap.add(prev);
            }

            current.frequency--;
            prev = current;
        }

        // If the result length is not equal to the input length, return empty string
        return result.length() == s.length() ? result.toString() : "";
    }

    public static void main(String[] args) {
        String s = "aaabbc";
        String result = rearrangeString(s);
        System.out.println("Rearranged string: " + result);

    }
}
