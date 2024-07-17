import java.util.PriorityQueue;
import java.util.HashMap;
import java.util.Map;

public class Huffman {
    private static class HuffmanNode implements Comparable<HuffmanNode> {
        char ch;
        int freq;
        HuffmanNode left, right;

        HuffmanNode(char ch, int freq, HuffmanNode left, HuffmanNode right) {
            this.ch = ch;
            this.freq = freq;
            this.left = left;
            this.right = right;
        }

        @Override
        public int compareTo(HuffmanNode that) {
            return this.freq - that.freq;
        }
    }

    public static HuffmanNode buildHuffmanTree(Map<Character, Integer> freq) {
        PriorityQueue<HuffmanNode> pq = new PriorityQueue<>();
        for (Map.Entry<Character, Integer> entry : freq.entrySet()) {
            pq.add(new HuffmanNode(entry.getKey(), entry.getValue(), null, null));
        }

        while (pq.size() > 1) {
            HuffmanNode left = pq.poll();
            HuffmanNode right = pq.poll();
            pq.add(new HuffmanNode('\0', left.freq + right.freq, left, right));
        }

        return pq.poll();
    }

    public static void generateHuffmanCode(HuffmanNode node, String prefix, Map<Character, String> codebook) {
        if (node != null) {
            if (node.ch != '\0') {
                codebook.put(node.ch, prefix);
            } else {
                generateHuffmanCode(node.left, prefix + "0", codebook);
                generateHuffmanCode(node.right, prefix + "1", codebook);
            }
        }
    }

    public static String huffmanEncode(String str, Map<Character, String> codebook) {
        StringBuilder encoded = new StringBuilder();
        for (char ch : str.toCharArray()) {
            encoded.append(codebook.get(ch));
        }
        return encoded.toString();
    }

    public static String huffmanDecode(String str, HuffmanNode root) {
        StringBuilder decoded = new StringBuilder();
        HuffmanNode node = root;
        for (int i = 0; i < str.length(); i++) {
            node = str.charAt(i) == '0' ? node.left : node.right;
            if (node.ch != '\0') {
                decoded.append(node.ch);
                node = root;
            }
        }
        return decoded.toString();
    }

    public static void main(String[] args) {
        String str = "hello world";

        Map<Character, Integer> freq = new HashMap<>();
        for (char ch : str.toCharArray()) {
            freq.put(ch, freq.getOrDefault(ch, 0) + 1);
        }

        HuffmanNode root = buildHuffmanTree(freq);
        Map<Character, String> codebook = new HashMap<>();
        generateHuffmanCode(root, "", codebook);
        String encoded = huffmanEncode(str, codebook);
        String decoded = huffmanDecode(encoded, root);

        System.out.println("Encoded: " + encoded);
        System.out.println("Decoded: " + decoded);
    }
}