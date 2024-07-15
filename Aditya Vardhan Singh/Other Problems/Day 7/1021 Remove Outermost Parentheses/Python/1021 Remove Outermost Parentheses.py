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
