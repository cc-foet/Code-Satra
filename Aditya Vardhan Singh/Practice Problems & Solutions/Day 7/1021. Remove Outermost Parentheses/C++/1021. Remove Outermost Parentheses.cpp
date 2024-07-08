// Problem link: https://leetcode.com/problems/remove-outermost-parentheses/
//
// A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.
//
// For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
//
// A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.
//
// Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
//
// Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

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
