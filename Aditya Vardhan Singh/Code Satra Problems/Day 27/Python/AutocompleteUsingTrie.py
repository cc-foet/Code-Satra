class TrieNode:
    def __init__(self):
        self.children: dict[str, TrieNode] = {} # map every children to next TrieNode
        self.is_end_of_word: bool = False

class Trie:
    def __init__(self):
        self.root: TrieNode = TrieNode()
    
    def insert(self, word: str) -> None:
        node: TrieNode = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True

    def find_in_trie(self, node, prefix):
        words = []
        if node.is_end_of_word:
            words.append(prefix)
        for char, child_node in node.children.items():
            words.extend(self.find_in_trie(child_node, prefix + char))
        return words

    def search_prefix(self, prefix):
        node = self.root
        for char in prefix:
            if char not in node.children:
                return []
            node = node.children[char]
        return self.find_in_trie(node, prefix)
    
# Driver code
words = {"cat", "car", "cart", "dog", "dove", "door"}
prefix = "car"

trie = Trie()
for word in words:
    trie.insert(word)

print(trie.search_prefix(prefix))