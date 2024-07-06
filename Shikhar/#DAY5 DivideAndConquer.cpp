#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

int findKth(vector<int>& arr1, vector<int>& arr2, int k, int start1, int start2) {
    if (start1 >= arr1.size()) return arr2[start2 + k - 1];
    if (start2 >= arr2.size()) return arr1[start1 + k - 1];
    if (k == 1) return min(arr1[start1], arr2[start2]);

    int mid1 = start1 + k / 2 - 1 < arr1.size() ? arr1[start1 + k / 2 - 1] : INT_MAX;
    int mid2 = start2 + k / 2 - 1 < arr2.size() ? arr2[start2 + k / 2 - 1] : INT_MAX;

    if (mid1 < mid2) {
        return findKth(arr1, arr2, k - k / 2, start1 + k / 2, start2);
    } else {
        return findKth(arr1, arr2, k - k / 2, start1, start2 + k / 2);
    }
}

int findKthElement(vector<int>& arr1, vector<int>& arr2, int k) {
    return findKth(arr1, arr2, k, 0, 0);
}

int main() {
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int k = 5;
    cout << findKthElement(arr1, arr2, k) << endl;
    return 0;
}
