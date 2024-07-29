
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

class TrieNode {
    Map<Character, TrieNode> children;
    boolean isEndOfWord;

    public TrieNode() {
        children = new HashMap<>();
        isEndOfWord = false;
    }
}

class Trie {
    private final TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    void insert(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            node.children.putIfAbsent(c, new TrieNode());
            node = node.children.get(c);
        }
        node.isEndOfWord = true;
    }

    public List<String> search(String prefix) {
        TrieNode node = root;
        for (char c : prefix.toCharArray()) {
            if (!node.children.containsKey(c)) {
                return new ArrayList<>();
            }
            node = node.children.get(c);
        }
        return autoComplete(node, prefix);
    }

    private List<String> autoComplete(TrieNode node, String prefix) {
        List<String> result = new ArrayList<>();
        if (node.isEndOfWord) {
            result.add(prefix);
        }
        for (char c : node.children.keySet()) {
            result.addAll(autoComplete(node.children.get(c), prefix + c));
        }
        return result;
    }
}

public class Autocomplete {
    public static void main(String[] args) {
        String[] words = {"cat", "car", "cart", "dog", "dove", "door"};
        String prefix = "car";

        Trie trie = new Trie();
        for (String word : words) {
            trie.insert(word);
        }
        System.out.println(trie.search(prefix));
    }
}
