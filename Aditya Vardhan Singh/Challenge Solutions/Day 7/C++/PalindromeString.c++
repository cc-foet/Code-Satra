#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool is_palindrome_string(string& input_string) {
  stack<char> stk;

  for (auto ch : input_string) {
    stk.push(ch);
  }
  string reverse_string = "";
  while (stk.size()) {
    reverse_string += stk.top();
    stk.pop();
  }
  if (reverse_string == input_string) return true;
  else return false;
}

int main() {
  string input_string;
  cout << "Enter a string: ";
  cin >> input_string;
  if (is_palindrome_string(input_string)) {
    cout << "True";
  } else {
    cout << "False";
  }
  cout << endl;

  return EXIT_SUCCESS;
}
