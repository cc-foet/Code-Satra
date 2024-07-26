/* Program to find the length of the longest palindrome possible from the given string [s] which consists of lowercase or uppercase letters.*/

#include <iostream>
#include <vector>
using namespace std;

int longestPalindrome(string s)
{
  vector<int> lowercase(26, 0), uppercase(26, 0);
  int count = 0;
  bool odd = 0;
  for (int i = 0; i < s.size(); ++i)
  {
    if (s[i] >= 'a')
      lowercase[s[i] - 'a']++;
    else
      uppercase[s[i] - 'A']++;
  }
  for (int i = 0; i < 26; ++i)
  {
    if (lowercase[i] % 2 == 0)
      count += lowercase[i];
    else
    {
      count += lowercase[i] - 1;
      odd = 1;
    }

    if (uppercase[i] % 2 == 0)
      count += uppercase[i];
    else
    {
      count += uppercase[i] - 1;
      odd = 1;
    }
  }
  return count + odd;
};

int main(){
  string s = "abccccdd";
  cout<<"Longest palindrome possible from the given string is: "<<longestPalindrome(s)<<endl;
}