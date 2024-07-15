import heapq
from collections import defaultdict, Counter

# Step 1: Frequency Calculation
def calculate_frequencies(string):
    return Counter(string)

# Step 2: Build Huffman Tree
class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    # Define comparison operators for priority queue
    def __lt__(self, other):
        return self.freq < other.freq

def build_huffman_tree(frequencies):
    heap = [Node(char, freq) for char, freq in frequencies.items()]
    heapq.heapify(heap)
    
    while len(heap) > 1:
        node1 = heapq.heappop(heap)
        node2 = heapq.heappop(heap)
        merged = Node(None, node1.freq + node2.freq)
        merged.left = node1
        merged.right = node2
        heapq.heappush(heap, merged)
    
    return heap[0]

# Step 3: Generate Codes
def generate_codes(node, prefix='', codebook={}):
    if node:
        if node.char is not None:
            codebook[node.char] = prefix
        generate_codes(node.left, prefix + '0', codebook)
        generate_codes(node.right, prefix + '1', codebook)
    return codebook

# Step 4: Encode String
def encode_string(string, codebook):
    return ''.join(codebook[char] for char in string)

# Step 5: Decode String
def decode_string(encoded_string, root):
    decoded_chars = []
    current_node = root
    for bit in encoded_string:
        if bit == '0':
            current_node = current_node.left
        else:
            current_node = current_node.right
        
        if current_node.char is not None:
            decoded_chars.append(current_node.char)
            current_node = root
    
    return ''.join(decoded_chars)

# Main Function
def huffman_coding(string):
    frequencies = calculate_frequencies(string)
    huffman_tree = build_huffman_tree(frequencies)
    codebook = generate_codes(huffman_tree)
    encoded_string = encode_string(string, codebook)
    decoded_string = decode_string(encoded_string, huffman_tree)
    
    return encoded_string, decoded_string

# Input
string = "code satra"
encoded, decoded = huffman_coding(string)
print("Encoded string:", encoded)
print("Decoded string:", decoded)
