<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int longestSubarray(const vector<int>& arr, int k) {
  unordered_map<int, int> remainderIndexMap;
  remainderIndexMap[0] = -1; 

  int maxLength = 0;
  int sum = 0;

  for (int i = 0; i < arr.size(); ++i) {
    sum += arr[i];
    int remainder = ((sum % k) + k) % k; 
    if (remainderIndexMap.find(remainder) != remainderIndexMap.end()) {
      maxLength = max(maxLength, i - remainderIndexMap[remainder]);
    }
    else {
      remainderIndexMap[remainder] = i;
    }
  }
  return maxLength;
}

int main() {
  int n, k;
  cout << "Enter the number of elements in the array: ";
  cin >> n;

  vector<int> arr(n);
  cout << "Enter the elements of the array: ";
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  cout << "Enter the value of k: ";
  cin >> k;

  int result = longestSubarray(arr, k);
  cout << "The length of the longest subarray with sum divisible by " << k << " is: " << result << endl;

  return 0;
=======
#include <bits/stdc++.h>
using namespace std;

int longestSubarray(const vector<int>& arr, int k) {
  unordered_map<int, int> remainderIndexMap;
  remainderIndexMap[0] = -1; 

  int maxLength = 0;
  int sum = 0;

  for (int i = 0; i < arr.size(); ++i) {
    sum += arr[i];
    int remainder = ((sum % k) + k) % k; 
    if (remainderIndexMap.find(remainder) != remainderIndexMap.end()) {
      maxLength = max(maxLength, i - remainderIndexMap[remainder]);
    }
    else {
      remainderIndexMap[remainder] = i;
    }
  }
  return maxLength;
}

int main() {
  int n, k;
  cout << "Enter the number of elements in the array: ";
  cin >> n;

  vector<int> arr(n);
  cout << "Enter the elements of the array: ";
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  cout << "Enter the value of k: ";
  cin >> k;

  int result = longestSubarray(arr, k);
  cout << "The length of the longest subarray with sum divisible by " << k << " is: " << result << endl;

  return 0;
>>>>>>> b864b1e0452feec9ce79d7d716be4083502c132f
}