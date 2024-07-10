/*
this is a leetcode problem i solve today 
link - https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

--> Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

1     2abc    3def
4ghi   5jkl    6mno
7pqrs  8tuv    9wxyz
*      0        #

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]

-->  I hope you understand the problem otherwise visit the question link

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void solve(string digits,unsigned int index, vector<string>& ans, string output, string mapping[]) {
        // base case
        if (index >= digits.length()) {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];

        for (unsigned int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);
            solve(digits, index + 1, ans, output, mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.length() == 0) return ans;

        string output = "";
        int index = 0;

        string mapping[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, index, ans, output, mapping);
        return ans;
    }
};

int main() {
    Solution solution;
    string digits;
    cout << "Enter a string of digits: ";
    cin >> digits;

    vector<string> result = solution.letterCombinations(digits);

    cout << "Letter combinations: ";
    for (string str : result) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}