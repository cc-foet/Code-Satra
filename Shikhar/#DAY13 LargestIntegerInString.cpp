// This is a leetcode question on finding the largest odd number through an already given string.
// Question Link:- https://leetcode.com/problems/largest-odd-number-in-string/

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        for(int i = n-1; i>=0; i--){
            if((num[i]-'0')%2 == 1){
                return num.substr(0, i+1);
            }
        }
        return "";
    }
};