
import java.util.PriorityQueue;
import java.util.HashMap;



public class HuffmanCoding {
    static class Node implements Comparable<Node> {
        char ch;
        int freq;
        Node left, right;

        Node(char ch, int freq, Node left, Node right) {
            this.ch = ch;
            this.freq = freq;
            this.left = left;
            this.right = right;
        }

        @Override
        public int compareTo(Node other) {
            return this.freq - other.freq;
        }
    }

    public static String huffman(String s, int[] f) {
      
        HashMap<Character, Integer> freqMap = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            freqMap.put(ch, freqMap.getOrDefault(ch, 0) + 1);
        }

       
        PriorityQueue<Node> pq = new PriorityQueue<>();
        for (char ch : freqMap.keySet()) {
            pq.offer(new Node(ch, freqMap.get(ch), null, null));
        }

        
        while (pq.size() > 1) {
            Node left = pq.poll();
            Node right = pq.poll();
            Node parent = new Node('\0', left.freq + right.freq, left, right);
            pq.offer(parent);
        }

        HashMap<Character, String> encodingMap = new HashMap<>();
        buildEncodingMap(pq.peek(), "", encodingMap);

        
        StringBuilder encodedString = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            encodedString.append(encodingMap.get(ch));
        }

      
        System.out.println("Encoded String: " + encodedString.toString());

        
        StringBuilder decodedString = new StringBuilder();
        Node root = pq.peek();
        Node curr = root;
        for (int i = 0; i < encodedString.length(); i++) {
            if (encodedString.charAt(i) == '0') {
                curr = curr.left;
            } else {
                curr = curr.right;
            }

            if (curr.left == null && curr.right == null) {
                decodedString.append(curr.ch);
                curr = root;
            }
        }

     
        System.out.println("Decoded String: " + decodedString.toString());

        return encodedString.toString();
    }

    private static void buildEncodingMap(Node node, String code, HashMap<Character, String> encodingMap) {
        if (node == null) {
            return;
        }

        if (node.left == null && node.right == null) {
            encodingMap.put(node.ch, code);
        }

        buildEncodingMap(node.left, code + "0", encodingMap);
        buildEncodingMap(node.right, code + "1", encodingMap);
    }

    public static void main(String[] args) {
        String s = "Messi is better than Ronaldo";
        int[] f = {2, 1, 4, 2, 1, 1};
        huffman(s, f);
    }
}
