#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Node structure for the Huffman tree
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char character, int frequency) : ch(character), freq(frequency), left(NULL), right(NULL) {}
};

// Compare function to order the nodes in the priority queue
struct compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Function to build the Huffman tree
Node* buildHuffmanTree(string text) {
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;
        pq.push(sum);
    }

    return pq.top();
}

// Function to build the Huffman code map
void buildHuffmanCode(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    buildHuffmanCode(root->left, str + "0", huffmanCode);
    buildHuffmanCode(root->right, str + "1", huffmanCode);
}

// Function to encode the input string using the Huffman code
string encode(string text, unordered_map<char, string>& huffmanCode) {
    string encodedString = "";
    for (char ch : text) {
        encodedString += huffmanCode[ch];
    }
    return encodedString;
}

// Function to decode the encoded string using the Huffman tree
string decode(string encodedString, Node* root) {
    string decodedString = "";
    Node* current = root;
    for (char bit : encodedString) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (!current->left && !current->right) {
            decodedString += current->ch;
            current = root;
        }
    }
    return decodedString;
}

int main() {
    // Input string to be encoded and decoded
    string text = "code satra";

    Node* root = buildHuffmanTree(text);

    unordered_map<char, string> huffmanCode;
    buildHuffmanCode(root, "", huffmanCode);

    string encodedString = encode(text, huffmanCode);
    string decodedString = decode(encodedString, root);

    cout << "Encode: " << encodedString << endl;
    cout << "Decoded: " << decodedString << endl;

    return 0;
}
