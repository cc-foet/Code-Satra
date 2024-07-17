import heapq
from collections import Counter, namedtuple

class Node:
    def __init__(self, char, freq, left=None, right=None):
        self.char = char
        self.freq = freq
        self.left = left
        self.right = right

    def __lt__(self, other):
        return self.freq < other.freq

class HuffmanCoding:
    def __init__(self, data):
        self.data = data
        self.frequency = Counter(data)
        self.huffman_tree = self.build_huffman_tree()
        self.codes = self.generate_codes()

    def build_huffman_tree(self):
        heap = [Node(char, freq) for char, freq in self.frequency.items()]
        heapq.heapify(heap)
        
        while len(heap) > 1:
            left = heapq.heappop(heap)
            right = heapq.heappop(heap)
            merged = Node(None, left.freq + right.freq, left, right)
            heapq.heappush(heap, merged)
        
        return heap[0]

    def generate_codes(self):
        codes = {}
        
        def generate_codes_helper(node, current_code):
            if node is None:
                return
            
            if node.char is not None:
                codes[node.char] = current_code
                return
            
            generate_codes_helper(node.left, current_code + "0")
            generate_codes_helper(node.right, current_code + "1")
        
        generate_codes_helper(self.huffman_tree, "")
        return codes

    def encode(self):
        encoded_data = ''.join(self.codes[char] for char in self.data)
        return encoded_data

    def decode(self, encoded_data):
        decoded_data = []
        node = self.huffman_tree
        for bit in encoded_data:
            node = node.left if bit == '0' else node.right
            
            if node.char is not None:
                decoded_data.append(node.char)
                node = self.huffman_tree
        
        return ''.join(decoded_data)

data = "code satra"
huffman_coding = HuffmanCoding(data)
encoded_data = huffman_coding.encode()
decoded_data = huffman_coding.decode(encoded_data)

print("Input string: ", data)
print("Encoded: ", encoded_data)
print("Decoded: ", decoded_data)
