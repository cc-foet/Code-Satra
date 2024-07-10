#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int sum_factor(vector<int>& arr, int k) {
  unordered_map<int, int> mod_map;
  int max_len = 0, prefix_sum = 0;
  int mod;

  for (int i = 0; i < arr.size(); i++) {
    prefix_sum += arr[i];
    mod = prefix_sum % k;
    if (mod == 0) max_len = i - 1;
    if (mod_map.find(mod) == mod_map.end()) {
      mod_map[mod] = i;
    } else {
      max_len = max(max_len, i - mod_map[mod]);
    }
  }

  return max_len;
}

int main() {
  std::vector<int> arr = {2, 7, 6, 1, 4, 5};
  int k = 3;

  cout << sum_factor(arr, k) << endl;
}
