 #include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to calculate the sum of elements in arr from start to end
int sum(vector<int>& arr, int start, int end) {
    int total = 0;
    for (int i = start; i <= end; i++) {
        total += arr[i];
    }
    return total;
}

int minTimeToPaintBoards(vector<int>& arr, int n, int k) {
    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));

    // Base case: with one painter, the time is the sum of the first i boards
    for (int i = 1; i <= n; i++) {
        dp[i][1] = sum(arr, 0, i - 1);
    }

    // Fill the DP table
    for (int j = 2; j <= k; j++) { // For each painter from 2 to k
        for (int i = 1; i <= n; i++) { // For each board from 1 to n
            for (int p = 1; p < i; p++) { // Try to partition the boards
                dp[i][j] = min(dp[i][j], max(dp[p][j - 1], sum(arr, p, i - 1)));
            }
        }
    }

    return dp[n][k];
}

int main() {
    int n = 4;
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;

    int result = minTimeToPaintBoards(arr, n, k);
    cout << "Minimum time to paint all boards: " << result << endl;

    return 0;
}
