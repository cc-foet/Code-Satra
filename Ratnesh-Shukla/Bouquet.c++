#include <bits/stdc++.h>
using namespace std;

bool bouquetPossible(vector<int>& arr, int day, int M, int K) {
  int count = 0;
  int bouquet = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] <= day) {
      count++;
    } 
    else {
      bouquet += (count / K);
      count = 0;
    }
  }
  bouquet += (count / K);
  return bouquet >= M;
}

int minDays(vector<int>& bloomDay, int M, int K) {
  int n = bloomDay.size();
  if (M * K > n) {
    return -1;
  }

  int left = INT_MAX, right = INT_MIN;
  for (int i = 0; i < n; i++) {
    left = min(left, bloomDay[i]);
    right = max(right, bloomDay[i]);
  }

  while (left < right) {
    int mid = left + (right - left) / 2;
    if (bouquetPossible(bloomDay, mid, M, K)) {
      right = mid;
    }
    else {
      left = mid + 1;
    }
  }
  return left;
}

int main() {
  int M, K;
  cout << "Enter the number of bouquets (M): ";
  cin >> M;
  cout << "Enter the number of adjacent flowers needed for a bouquet (K): ";
  cin >> K;

  int n;
  cout << "Enter the number of flowers (size of bloomDay array): ";
  cin >> n;

  vector<int> bloomDay(n);
  cout << "Enter the bloom days for each flower: ";
  for (int i = 0; i < n; ++i) {
    cin >> bloomDay[i];
  }

  int result = minDays(bloomDay, M, K);
  cout << "Minimum number of days: " << result << endl;
  return 0;
}
