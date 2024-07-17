// Rearrange characters in a string so that no two adjacent characters are the same.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string rearrangeString(string s) {
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    vector<pair<int, char>> charFreq;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            char ch = 'a' + i;
            charFreq.push_back({freq[i], ch});
        }
    }

    sort(charFreq.begin(), charFreq.end(), greater<pair<int, char>>());

    string result;
    pair<int, char> last = {-1, '#'};

    while (!charFreq.empty()) {
        pair<int, char> current = charFreq.back();
        charFreq.pop_back();
        result += current.second;

        if (last.first > 0) {
            charFreq.push_back(last);
        }

        current.first--;
        last = current;

        sort(charFreq.begin(), charFreq.end(), greater<pair<int, char>>());
    }

    if (result.length() != s.length()) {
        return "";
    }

    return result;
}

int main() {
    string s = "aaabbc";
    cout << "Original String: " << s << endl;
    cout << "Rearranged String: " << rearrangeString(s) << endl;

    return 0;
}

// Output:-
// Original String: aaabbc
// Rearranged String: ababac