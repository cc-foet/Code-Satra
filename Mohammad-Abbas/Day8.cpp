#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarrayDivisibleByK(vector<int>& nums, int k) {
    // Hash map to store the first occurrence of each prefix sum modulo k
    unordered_map<int, int> modMap;
    modMap[0] = -1; // Initialize with mod value 0 at index -1 for edge case

    int maxLength = 0;
    int prefixSum = 0;

    for (int i = 0; i < nums.size(); ++i) {
        prefixSum += nums[i];
        int modValue = prefixSum % k;

        // Ensure non-negative mod value
        if (modValue < 0) {
            modValue += k;
        }

        // If the mod value has been seen before, calculate the length of subarray
        if (modMap.find(modValue) != modMap.end()) {
            maxLength = max(maxLength, i - modMap[modValue]);
        } else {
            // Store the first occurrence of the mod value
            modMap[modValue] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> nums = {2, 7, 6, 1, 4, 5};
    int k = 3;
    cout << "Length of the longest subarray: " << longestSubarrayDivisibleByK(nums, k) << endl;
    return 0;
}