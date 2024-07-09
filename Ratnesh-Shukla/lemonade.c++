#include <bits/stdc++.h>
using namespace std;

bool lemonade(vector<int>& bills) {
  int five = 0, ten = 0;
  for (int i = 0; i < bills.size(); i++) {
  if (bills[i] == 5) {
    five++;
  } 
  else if (bills[i] == 10) {
    if (five == 0) return false;
      five--;
      ten++;
    } 
    else { 
      if (ten > 0 && five > 0) {
        ten--;
        five--;
      }
      else if (five >= 3) {
        five -= 3;
      } 
      else {
        return false;
      }
    }
  }
    return true;
}

int main() {
  int n;
  cout << "Enter the number of customers: ";
  cin >> n;
  vector<int> bills(n);
  cout << "Enter the bills given by the customers: ";
  for (int i = 0; i < n; ++i) {
    cin >> bills[i];
  }
  if(lemonade(bills)){
    cout << "True"<< endl;
  }
  else{
    cout << "False"<< endl;
  }
  return 0;
}
