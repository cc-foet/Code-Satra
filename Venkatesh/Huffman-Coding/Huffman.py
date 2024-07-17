import heapq
from collections import Counter, namedtuple

class HuffmanNode(namedtuple("HuffmanNode", ["char", "freq", "left", "right"])):
    def __lt__(self, other):
        return self.freq < other.freq

def build_huffman_tree(freq):
    heap = [HuffmanNode(char, freq, None, None) for char, freq in freq.items()]
    heapq.heapify(heap)
    
    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)
        node = HuffmanNode(None, left.freq + right.freq, left, right)
        heapq.heappush(heap, node)
    
    return heap[0]

def generate_huffman_codes(node, prefix="", codebook={}):
    if node.char is not None:
        codebook[node.char] = prefix
    else:
        generate_huffman_codes(node.left, prefix + "0", codebook)
        generate_huffman_codes(node.right, prefix + "1", codebook)
    return codebook

def huffman_encode(str, codebook):
    return ''.join(codebook[char] for char in str)

def huffman_decode(str, root):
    node, decoded = root, []
    for bit in str:
        node = node.left if bit == '0' else node.right
        if node.char is not None:
            decoded.append(node.char)
            node = root
    return ''.join(decoded)

str = "hello world"
freq = Counter(str)
root = build_huffman_tree(freq)
codebook = generate_huffman_codes(root)
encoded_data = huffman_encode(str, codebook)
decoded_data = huffman_decode(encoded_data, root)
print(f"Encoded: {encoded_data}")
print(f"Decoded: {decoded_data}")