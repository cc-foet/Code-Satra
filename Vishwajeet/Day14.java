// Problem: Given a string, compress it using Huffman coding and display its binary encoded representation and also decode and print the decoded string.

import java.util.*;

// Define the Huffman node structure
class HuffmanNode {
    char ch;
    int freq;
    HuffmanNode left, right;

    // Constructor
    HuffmanNode(char ch, int freq) {
        this.ch = ch;
        this.freq = freq;
    }

    // Constructor
    HuffmanNode(int freq, HuffmanNode left, HuffmanNode right) {
        this.freq = freq;
        this.left = left;
        this.right = right;
    }
}

class HuffmanCoding {

    private static Map<Character, String> huffmanCodeMap = new HashMap<>();
    private static HuffmanNode root;

    // Build the Huffman tree
    public static void buildHuffmanTree(String text) {

        // Calculate the frequency of each character in the text
        Map<Character, Integer> freqMap = new HashMap<>();
        for (char ch : text.toCharArray()) {
            freqMap.put(ch, freqMap.getOrDefault(ch, 0) + 1);
        }

        // Create a priority queue to store the nodes
        PriorityQueue<HuffmanNode> pq = new PriorityQueue<>(Comparator.comparingInt(node -> node.freq));
        for (Map.Entry<Character, Integer> entry : freqMap.entrySet()) {
            pq.offer(new HuffmanNode(entry.getKey(), entry.getValue()));
        }

        // Build the Huffman tree
        while (pq.size() > 1) {
            HuffmanNode left = pq.poll();  // Extract the two nodes with the lowest frequency
            HuffmanNode right = pq.poll(); // Combine them to form a new node
            HuffmanNode newNode = new HuffmanNode(left.freq + right.freq, left, right);
            pq.offer(newNode);
        }

        root = pq.poll();
        buildCodeMap(root, "");
    }

    // Build the Huffman code map
    private static void buildCodeMap(HuffmanNode node, String code) { 
        if (node == null) {
            return;
        }

        // If leaf node is reached, add the character and its corresponding code to the map
        if (node.ch != 0) {
            huffmanCodeMap.put(node.ch, code);
        }

        buildCodeMap(node.left, code + '0'); // Traverse left and append '0' to the code
        buildCodeMap(node.right, code + '1'); // Traverse right and append '1' to the code
    }

    // Encoding the text
    public static String encode(String text) {
        StringBuilder encodedString = new StringBuilder(); // Initialize an empty string
        
        // Traverse the text and append the corresponding binary code for each character
        for (char ch : text.toCharArray()) {
            encodedString.append(huffmanCodeMap.get(ch));
        }
        return encodedString.toString(); // Return the encoded string
    }
 
    // Decoding the encoded text
    public static String decode(String encodedText) {
        StringBuilder decodedString = new StringBuilder(); // Initialize an empty string
        HuffmanNode current = root;  // Start from the root node

        // Traverse the encoded text
        for (char bit : encodedText.toCharArray()) {
            current = (bit == '0') ? current.left : current.right;

            // If leaf node is reached, append the character to the decoded string
            if (current.left == null && current.right == null) {
                decodedString.append(current.ch);
                current = root;
            }
        }
        return decodedString.toString(); // Return the decoded string
    }

    // Main method
    public static void main(String[] args) {
        String text = "code satra";
        System.out.println("Original text: " + text);

        // Build Huffman tree and encode the text
        buildHuffmanTree(text);
        String encodedText = encode(text);
        System.out.println("Encoded text: " + encodedText);

        // Decode the encoded text
        String decodedText = decode(encodedText);
        System.out.println("Decoded text: " + decodedText);
    }
}
