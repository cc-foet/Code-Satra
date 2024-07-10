# Problem link: https://leetcode.com/problems/remove-outermost-parentheses/
#
# A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.
# 
# For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
#
# A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.
#
# Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
#
# Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        count = 0
        substr = ""
        ans = ""
        for i in s:
            if i == '(':
                count += 1
                substr += i
            elif i == ')':
                count -= 1
                substr += i
            if count == 0:
                ans += substr[1:len(substr)-1]
                substr = ""
        return ans

# Solution accepted
