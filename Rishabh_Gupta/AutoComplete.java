import java.util.List;
import java.util.ArrayList;

class Node {
    Node[] links;
    boolean endOfWord;

    public Node() {
        links = new Node[26];
        endOfWord = false;
    }
}

class PrefixTree {
    private final Node rootNode;

    public PrefixTree() {
        rootNode = new Node();
    }

    void addWord(String word) {
        Node currentNode = rootNode;
        for (char letter : word.toCharArray()) {
            int index = letter - 'a';
            if (currentNode.links[index] == null) {
                currentNode.links[index] = new Node();
            }
            currentNode = currentNode.links[index];
        }
        currentNode.endOfWord = true;
    }

    public List<String> findWords(String prefix) {
        Node currentNode = rootNode;
        for (char letter : prefix.toCharArray()) {
            int index = letter - 'a';
            if (currentNode.links[index] == null) {
                return new ArrayList<>();
            }
            currentNode = currentNode.links[index];
        }
        return getWords(currentNode, prefix);
    }

    private List<String> getWords(Node currentNode, String prefix) {
        List<String> words = new ArrayList<>();
        if (currentNode.endOfWord) {
            words.add(prefix);
        }
        for (int i = 0; i < 26; i++) {
            if (currentNode.links[i] != null) {
                words.addAll(getWords(currentNode.links[i], prefix + (char) (i + 'a')));
            }
        }
        return words;
    }
}

public class AutoComplete{
    public static void main(String[] args) {
        String[] dictionary = {"cat", "car", "cart", "dog", "dove", "door"};
        String searchPrefix = "car";

        PrefixTree trie = new PrefixTree();
        for (String word : dictionary) {
            trie.addWord(word);
        }
        System.out.println(trie.findWords(searchPrefix));
    }
}
