#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
  stack<char> stk;
  queue<char> que;
  for (int i = 0; i < s.length(); ++i) {
    stk.push(s[i]);
    que.push(s[i]);
  }
  while (!stk.empty()) {
    if (stk.top() != que.front()) return false;
    stk.pop();
    que.pop();
  }
  return true;
}

int main() {
  string input;
  cout << "Enter a string: ";
  getline(cin, input);

  if (isPalindrome(input)) {
    cout << "Output: True" << endl;
  } 
  else {
    cout << "Output: False" << endl;
  }
  return 0;
}
