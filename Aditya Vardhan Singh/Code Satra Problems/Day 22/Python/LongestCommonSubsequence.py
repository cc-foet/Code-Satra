def lcs(str1, str2, str3):
    len1, len2, len3 = len(str1), len(str2), len(str3)

    # Create a 3D DP array with all values initialized to 0
    dp = [[[0 for _ in range(len3 + 1)] for _ in range(len2 + 1)] for _ in range(len1 + 1)]

    # Fill the dp array
    for i in range(1, len1 + 1):
        for j in range(1, len2 + 1):
            for k in range(1, len3 + 1):
                if str1[i-1] == str2[j-1] == str3[k-1]:
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1
                else:
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1])

    # The length of the longest common subsequence
    return dp[len1][len2][len3]

# Test the function
str1 = "abcd1e2"
str2 = "bc12ea"
str3 = "bd1ea"

print(lcs(str1, str2, str3))  # Output: 3
