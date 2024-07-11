#include <bits/stdc++.h>
using namespace std;

long long int factorial(long long int n){
  long long int result = 1;
  for (int i =  2; i <= n; i++)
  {
    result *= i;
  }
  return result;
}

int numTree(int n){
  long long int result = factorial(2*n)/((factorial(n+1)) * (factorial(n)));
  return result;
}

int main() {
    
  int n;
    
  cout << "Enter the number of elements in the array: ";
  cin >> n;
    
  vector<int> arr(n);
  cout << "Enter the elements of the array: ";
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int result = numTree(n);
    
  cout << "The number of possible binary trees is: " << result << endl;
    
  return 0;
}