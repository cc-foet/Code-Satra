/* Program to find factorial of a large number. */

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> factorial(int N)
{
  vector<int> ans(1, 1);

  while (N > 1)
  {
    int carry = 0, res, size = ans.size();
    for (int i = 0; i < size; ++i)
    {
      res = ans[i] * N + carry;
      ans[i] = res % 10;
      carry = res / 10;
    }
    while (carry)
    {
      ans.push_back(carry % 10);
      carry /= 10;
    }
    N--;
  }
  reverse(ans.begin(), ans.end());
  return ans;
};

int main(){
  int num = 10;
  vector<int> ans = factorial(num);
  cout<<"Factorial of "<<num<<": ";
  for(int i: ans){
    cout<<i;
  }
}
