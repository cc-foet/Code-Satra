// In this I have used the two-pointer approach to solve today's problem.

#include <iostream>
#include <vector>

using namespace std;

int findKthElement(vector<int>& arr1, vector<int>& arr2, int k) {
    int n = arr1.size();
    int m = arr2.size();
    int i = 0, j = 0, count = 0;
    int result = -1;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            result = arr1[i];
            i++;
        } else {
            result = arr2[j];
            j++;
        }
        count++;
        if (count == k) return result;
    }

    while (i < n) {
        result = arr1[i];
        i++;
        count++;
        if (count == k) return result;
    }

    while (j < m) {
        result = arr2[j];
        j++;
        count++;
        if (count == k) return result;
    }

    return result;
}

int main() {
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int k = 5;
    cout << findKthElement(arr1, arr2, k) << endl;
    return 0;
}

// Output: 6