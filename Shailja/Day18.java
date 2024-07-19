//?leetcode ques 1859
import java.util.Arrays;
import java.util.Comparator;

public class Day18 {

    public static void main(String[] args) {
        String shuffledSentence = "sentence4 a3 is2 This1";
        String originalSentence = reconstructSentence(shuffledSentence);
        System.out.println(originalSentence);
    }

public static String reconstructSentence(String shuffledSentence) {
    String[] words = shuffledSentence.split(" ");

    Arrays.sort(words, new Comparator<String>() {
        @Override
        public int compare(String word1, String word2) {
            int num1 = Integer.parseInt(word1.replaceAll("[^0-9]", ""));
            int num2 = Integer.parseInt(word2.replaceAll("[^0-9]", ""));
            return Integer.compare(num1, num2);
        }
    });

    StringBuilder originalSentence = new StringBuilder();
    for (String word : words) {
        originalSentence.append(word.replaceAll("[0-9]", "")).append(" ");
    }

    return originalSentence.toString().trim();
}
}