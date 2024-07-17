#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// A Tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

// Function to allocate a new tree node
Node* getNode(char ch, int freq, Node* left, Node* right) {
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

// Comparison object to be used to order the heap
struct comp {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Traverse the Huffman Tree and store Huffman Codes in a map.
void encode(Node* root, string str, unordered_map<char, string> &huffmanCode) {
    if (root == nullptr)
        return;

    // found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Traverse the Huffman Tree and decode the encoded string
string decode(Node* root, string &str) {
    string ans = "";
    Node* curr = root;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;

        // reached leaf node
        if (!curr->left && !curr->right) {
            ans += curr->ch;
            curr = root;
        }
    }
    return ans;
}

// Builds Huffman Tree and decode given input text
void buildHuffmanTree(string text) {
    // count frequency of appearance of each character
    // and store it in a map
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Create a priority queue to store live nodes of Huffman tree;
    priority_queue<Node*, vector<Node*>, comp> pq;

    // Create a leaf node for each character and add it
    // to the priority queue.
    for (auto pair : freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    // do till there is more than one node in the queue
    while (pq.size() != 1) {
        // Remove the two nodes of highest priority
        // (lowest frequency) from the queue
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create a new internal node with these two nodes as children
        // and with frequency equal to the sum of the two nodes' frequencies.
        // Add the new node to the priority queue.
        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    // root stores pointer to root of Huffman Tree
    Node* root = pq.top();

    // traverse the Huffman Tree and store Huffman Codes
    // in a map. Also prints them
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "Huffman Codes are:\n" << endl;
    for (auto pair : huffmanCode) {
        cout << pair.first << " " << pair.second << endl;
    }

    cout << "\nOriginal string was:\n" << text << endl;

    // print encoded string
    string str = "";
    for (char ch : text) {
        str += huffmanCode[ch];
    }

    cout << "\nEncoded string is:\n" << str << endl;

    // traverse the Huffman Tree again and this time
    // decode the encoded string
    string decodedStr = decode(root, str);

    cout << "\nDecoded string is:\n" << decodedStr << endl;
}

int main() {
    string text = "code satra";
    buildHuffmanTree(text);

    return 0;
}
