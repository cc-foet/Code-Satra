import java.util.ArrayList;
import java.util.List;

public class Day_27{
    public static void main(String[] args) {
        List<String> words=new ArrayList<>();
        words.add("cat");
        words.add("car");
        words.add("cart");
        words.add("dog");
        words.add("dove");
        words.add("door");
        Trie trie=new Trie();
        for(String word:words) 
            trie.insert(word);
        String prefix="car";
        List<String> output=trie.search(prefix);
        System.out.println(output);
    }
}

class TrieNode{
    TrieNode children[];
    boolean endofword;
    public TrieNode(){
        children=new TrieNode[26]; 
        endofword=false;
    }
}

class Trie{
    private TrieNode root;

    public Trie(){
        root=new TrieNode();
    }

    public void insert(String word){
        TrieNode node=root;
        for(char ch:word.toCharArray()){
            int index=ch-'a';
            if(node.children[index]==null)
                node.children[index]=new TrieNode();
            node=node.children[index];
        }
        node.endofword=true;
    }

    public List<String> search(String prefix){
        List<String> result=new ArrayList<>();
        TrieNode node=root;
        for(char ch:prefix.toCharArray()){
            int index=ch-'a';
            if(node.children[index]==null)
                return result;
            node=node.children[index];
        }
        dfs(node,prefix,result);
        return result;
    }

    private void dfs(TrieNode node, String prefix, List<String> result) {
        if(node.endofword)
            result.add(prefix);
        for(char ch='a';ch<='z';ch++){
            int index=ch-'a';
            if(node.children[index]!=null)
                dfs(node.children[index],prefix+ch,result);
        }
    }
}


