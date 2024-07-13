#include <string>

class Solution {
public:
    string removeOuterParentheses(string s) {
      int count = 0;
      string substring = "", ans = "";
      for (auto ch : s) {
        if (ch == '(') {
          count++;
          substring += ch;
        } else if (ch == ')') {
          count--;
          substring += ch;
        }
        if (count == 0) {
          ans += substring.substr(1, substring.size()-2);
          substring = "";
        }
      }
      return ans;
    }
};
