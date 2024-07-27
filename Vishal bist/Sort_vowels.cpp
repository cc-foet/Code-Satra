/* Program to sort vowels in a string [s] which contains both lowercase and uppercase leeters.
The vowels must be sorted in the nondecreasing order of their ASCII values. */

#include <iostream>
#include <vector>
using namespace std;

string sortVowels(string s)
{
  vector<int> lower(26, 0);
  vector<int> upper(26, 0);
  string ans;
  char c;

  for (int i = 0; i < s.size(); ++i)
  {
    if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
        s[i] == 'U')
    {
      upper[s[i] - 'A']++;
      s[i] = '#';
    }
    else if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
             s[i] == 'o' || s[i] == 'u')
    {
      lower[s[i] - 'a']++;
      s[i] = '#';
    }
  }
  for (int i = 0; i < 26; ++i)
  {
    c = 'A' + i;
    while (upper[i])
    {
      ans += c;
      upper[i]--;
    }
  }
  for (int i = 0; i < 26; ++i)
  {
    c = 'a' + i;
    while (lower[i])
    {
      ans += c;
      lower[i]--;
    }
  }
  int first = 0, second = 0;
  while (second < ans.size())
  {
    if (s[first] == '#')
    {
      s[first] = ans[second];
      second++;
    }
    first++;
  }
  return s;
};

int main(){
  string s = "lEetcOde";
  cout<<"Sorted string: "<<sortVowels(s)<<endl;
}