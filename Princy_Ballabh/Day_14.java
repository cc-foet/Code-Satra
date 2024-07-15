import java.util.*;
class HuffmanNode{
    int frequency;
    char c;
    HuffmanNode left;
    HuffmanNode right;
}

class MyComparator implements Comparator<HuffmanNode>{
    public int compare(HuffmanNode x, HuffmanNode y){
        return x.frequency-y.frequency;
    }
}

public class Day_14{

    public static void main(String[] args){
        String data="code satra";
        HuffmanNode root=buildHuffmanTree(data);
        Map<Character,String> huffmanCode=new HashMap<>();
        printCode(root, "", huffmanCode);
        String encodedString = encodeString(data, huffmanCode);
        System.out.println("Encoded : "+encodedString);
        String decodedString = decodeString(root, encodedString);
        System.out.println("Decoded : "+decodedString);
    }

    public static void printCode(HuffmanNode root, String s, Map<Character, String> huffmanCode){
        if(root.left==null && root.right==null && (Character.isLetterOrDigit(root.c)||root.c==' ')){
            huffmanCode.put(root.c, s);
            return;
        }
        printCode(root.left, s + "0", huffmanCode);
        printCode(root.right, s + "1", huffmanCode);
    }

    public static HuffmanNode buildHuffmanTree(String data){
        Map<Character, Integer> freq=new HashMap<>();
        for(char c : data.toCharArray()){
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }
        PriorityQueue<HuffmanNode> queue = new PriorityQueue<>(freq.size(), new MyComparator());
        for(Map.Entry<Character, Integer> entry : freq.entrySet()){
            HuffmanNode node = new HuffmanNode();
            node.c = entry.getKey();
            node.frequency = entry.getValue();
            node.left = null;
            node.right = null;
            queue.add(node);
        }
        while(queue.size() > 1){
            HuffmanNode x=queue.poll();
            HuffmanNode y=queue.poll();
            HuffmanNode f=new HuffmanNode();
            f.frequency=x.frequency+y.frequency;
            f.c='-';
            f.left=x;
            f.right=y;
            queue.add(f);
        }
        return queue.poll();
    }

    public static String encodeString(String data, Map<Character, String> huffmanCode) {
        List<String> encodedList=new ArrayList<>();
        for(char c : data.toCharArray()){
            encodedList.add(huffmanCode.get(c));
        }
        return String.join("", encodedList);
    }

    public static String decodeString(HuffmanNode root, String encodedString) {
        List<Character> decodedList = new ArrayList<>();
        HuffmanNode current = root;
        for (int i = 0; i < encodedString.length(); i++) {
            if (encodedString.charAt(i) == '0') {
                current = current.left;
            } else {
                current = current.right;
            }

            if (current.left == null && current.right == null) {
                decodedList.add(current.c);
                current = root;
            }
        }
        StringBuilder decodedString = new StringBuilder(decodedList.size());
        for (char c : decodedList) {
            decodedString.append(c);
        }
        return decodedString.toString();
    }    
}
