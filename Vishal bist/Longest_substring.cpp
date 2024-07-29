/* Program to find the longest substring without repeating characters.
   The given string [s] consists of English letters, digits, symbols and spaces. */

#include<iostream>
#include<vector>
using namespace std;

int longestUniqueSubsttr(string s){
        vector<bool>count(256,false);
        int first = 0, second = 0, len = 0;
        while(second<s.size()){
            while(count[s[second]]){
                count[s[first]] = false;
                first++;
            }
            count[s[second]] = true;
            len = max(len,((second-first)+1));
            second++;
        }
    return len;
        
};

int main(){
  string s = "*&^%&$#AASDFGSHJ1Ka3bac47abcbb14";
  cout<<"Length of the longest unique substring: "<<longestUniqueSubsttr(s)<<endl;
  return 0;
}