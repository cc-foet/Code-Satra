#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        sort(strs.begin(), strs.end());
        
        string first = strs[0];
        string last = strs[strs.size() - 1];
        int minLength = min(first.size(), last.size());
        
        string ans = "";
        for (int i = 0; i < minLength; i++) {
            if (first[i] != last[i]) {
                return ans;
            }
            ans += first[i];
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(strs) << endl;
    return 0;
}
