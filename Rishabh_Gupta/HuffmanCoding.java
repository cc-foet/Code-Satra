import java.util.*;

class HuffmanNode implements Comparable<HuffmanNode> {
    char data;
    int frequency;
    HuffmanNode left;
    HuffmanNode right;

    public HuffmanNode(char data, int frequency) {
        this.data = data;
        this.frequency = frequency;
    }

    public int compareTo(HuffmanNode other) {
        return this.frequency - other.frequency;
    }
}

public class HuffmanCoding {

    public static void main(String[] args) {
        String input = "code satra";
        Map<Character, Integer> frequencyMap = new HashMap<>();

        for (char c : input.toCharArray()) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }

        PriorityQueue<HuffmanNode> minHeap = new PriorityQueue<>();
        for (char c : frequencyMap.keySet()) {
            minHeap.offer(new HuffmanNode(c, frequencyMap.get(c)));
        }

        while (minHeap.size() > 1) {
            HuffmanNode left = minHeap.poll();
            HuffmanNode right = minHeap.poll();
            HuffmanNode merged = new HuffmanNode('\0', left.frequency + right.frequency);
            merged.left = left;
            merged.right = right;
            minHeap.offer(merged);
        }

        Map<Character, String> huffmanCodes = new HashMap<>();
        assignCodes(minHeap.peek(), "", huffmanCodes);

        StringBuilder encoded = new StringBuilder();
        for (char c : input.toCharArray()) {
            encoded.append(huffmanCodes.get(c));
        }

        StringBuilder decoded = new StringBuilder();
        HuffmanNode root = minHeap.peek();
        HuffmanNode current = root;
        for (char bit : encoded.toString().toCharArray()) {
            if (bit == '0') {
                current = current.left;
            } else {
                current = current.right;
            }
            if (current.data != '\0') {
                decoded.append(current.data);
                current = root;
            }
        }

        System.out.println("Encoded: " + encoded);
        System.out.println("Decoded: " + decoded);
    }

    private static void assignCodes(HuffmanNode node, String code, Map<Character, String> huffmanCodes) {
        if (node == null) {
            return;
        }
        if (node.data != '\0') {
            huffmanCodes.put(node.data, code);
        }
        assignCodes(node.left, code + "0", huffmanCodes);
        assignCodes(node.right, code + "1", huffmanCodes);
    }
}
