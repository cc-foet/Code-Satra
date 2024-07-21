#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& arr, int n, int k, int maxTime) {
    int paintersRequired = 1, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > maxTime) {
            paintersRequired++;
            sum = arr[i];
            if (paintersRequired > k) return false;
        }
    }
    return true;
}

int findMinTime(vector<int>& arr, int n, int k) {
    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        start = max(start, arr[i]);
        end += arr[i];
    }
    int result = end;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, k, mid)) {
            result = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return result;
}

int main() {
    int n = 4;
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;
    cout << "Minimum time to paint all boards: " << findMinTime(arr, n, k) << endl;
    return 0;
}