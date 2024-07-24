// Program to find the length of the longest common subsequence in three given sequences
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int lcsOf3(string str1, string str2, string str3) {
    int m = str1.length();
    int n = str2.length();
    int o = str3.length();
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(o + 1)));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= o; k++) {
                if (i == 0 || j == 0 || k == 0)
                    dp[i][j][k] = 0;
                else if (str1[i - 1] == str2[j - 1] && str1[i - 1] == str3[k - 1])
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
            }
        }
    }

    return dp[m][n][o];
}

int main() {
    string str1 = "abcd1e2";
    string str2 = "bc12ea";
    string str3 = "bd1ea";

    cout << "Length of LCS is " << lcsOf3(str1, str2, str3);

    return 0;
}