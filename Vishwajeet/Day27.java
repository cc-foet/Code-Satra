// Problem: Build an autocomplete system with a list of words that suggests word on a given prefix.

// AutocompleteSystem using Trie Data Structure

// Time Complexity: O(n) for inserting n words into the trie

// Space Complexity: O(n) for storing n words in the trie


import java.util.ArrayList;
import java.util.List;

public class Day27 {
    // Trie Node
    static class TrieNode {
        TrieNode[] children;
        boolean isEndOfWord;

        public TrieNode() {
            children = new TrieNode[26]; // 26 letters in the English alphabet
            isEndOfWord = false;
        }
    }

    // Trie
    static class Trie {
        private TrieNode root;

        public Trie() {
            root = new TrieNode();
        }

        // Insert a word into the trie
        public void insert(String word) {
            TrieNode node = root;
            for (char c : word.toCharArray()) {
                int index = c - 'a';
                if (node.children[index] == null) {
                    node.children[index] = new TrieNode();
                }
                node = node.children[index];
            }
            node.isEndOfWord = true;
        }

        // Find the node representing the prefix
        private TrieNode findNode(String prefix) {
            TrieNode node = root;
            for (char c : prefix.toCharArray()) {
                int index = c - 'a';
                if (node.children[index] == null) {
                    return null;
                }
                node = node.children[index];
            }
            return node;
        }

        // Get all words in the trie that start with the given prefix
        public List<String> autocomplete(String prefix) {
            List<String> results = new ArrayList<>();
            TrieNode node = findNode(prefix);
            if (node != null) {
                backtrack(prefix, node, results);
            }
            return results;
        }

        // Backtrack to find all words starting from the given node
        private void backtrack(String prefix, TrieNode node, List<String> results) {
            if (node.isEndOfWord) {
                results.add(prefix);
            }
            for (char c = 'a'; c <= 'z'; c++) {
                int index = c - 'a';
                if (node.children[index] != null) {
                    backtrack(prefix + c, node.children[index], results);
                }
            }
        }
    }

    // Main method to test the autocomplete system
    public static void main(String[] args) {
        Trie trie = new Trie();
        // Example list of words
        String[] words = {"cat", "car", "cart", "dog", "dove", "door"};

        // Insert words into the trie
        for (String word : words) {
            trie.insert(word);
        }

        // Test the autocomplete feature
        String prefix = "car";
        List<String> suggestions = trie.autocomplete(prefix);
        System.out.println("Words with prefix '" + prefix + "': " + suggestions);
    }
}
