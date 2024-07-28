class Trie_Node:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False
    
class Trie:
    def __init__(self):
        self.root = Trie_Node()
    
    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = Trie_Node()
            node = node.children[char]
        node.is_end_of_word = True

    def search(self, prefix):
        node = self.root
        for char in prefix:
            if char not in node.children:
                return []
            node = node.children[char]
        return self.autocomplete(node, prefix)

    def autocomplete(self, node, prefix):
        result = []
        if node.is_end_of_word:
            result.append(prefix)
        for char, child in node.children.items():
            result.extend(self.autocomplete(child, prefix + char))
        return result

words = ["cat", "car", "cart", "dog", "dove", "door"]
prefix = "car"

trie = Trie()
for word in words:
    trie.insert(word)

print(trie.search(prefix))