#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Key {
public:
    char character;
    int freq;

    Key(char character, int freq) {
        this->character = character;
        this->freq = freq;
    }
};

class KeyComparator {
public:
    bool operator()(const Key& key1, const Key& key2) {
        return key1.freq < key2.freq; // Max-heap: Higher frequency at top
    }
};

void rearrangeString(const string& s) {
    int len = s.length();
    unordered_map<char, int> characterCount;

    // Count the frequency of each character
    for (char c : s) {
        characterCount[c]++;
    }

    priority_queue<Key, vector<Key>, KeyComparator> pQueue;

    // Add keys to our priority queue if the count of that character is > 0
    for (auto& entry : characterCount) {
        if (entry.second > 0) {
            pQueue.push(Key(entry.first, entry.second));
        }
    }

    string result;
    Key prev('#', -1);

    while (!pQueue.empty()) {
        Key k = pQueue.top();
        pQueue.pop();
        result += k.character;

        if (prev.freq > 0) {
            pQueue.push(prev);
        }

        k.freq -= 1;
        prev = k;
    }

    if (result.length() != len) {
        cout << "NOT POSSIBLE" << endl;
    } else {
        cout << result << endl;
    }
}

int main() {
    string s = "aabbc";
    rearrangeString(s);
    return 0;
}
